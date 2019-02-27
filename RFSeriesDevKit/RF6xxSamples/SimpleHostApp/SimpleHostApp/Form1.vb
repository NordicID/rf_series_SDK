Public Class Form1

    'Form ID's
    Public Const MAIN_FORM = 100
    Public Const FORM_1 = 101
    Public Const FORM_2 = 102

    'Main menu button positions
    Public Const POS_FORM_1 = 45
    Public Const POS_FORM_2 = 65

    'NewFieldEx style flags
    Public Const STYLE_SND_ENTER = 1
    Public Const STYLE_NO_SEND = 2
    Public Const STYLE_SND_ALL = 4
    Public Const STYLE_OVR = 16
    Public Const STYLE_FLD_READER = 32
    Public Const STYLE_READER_DEFAULT = 64
    Public Const STYLE_FLD_ACTIVE = 128

    Private Sub AxPLServer1_DataArrived(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent) Handles AxPLServer1.DataArrived

        If e.frameid = -1 Then
            'Data is coming from F-key press or from initial screen
            SendMainForm(e.id)
            Exit Sub
        End If

        Dim formID As Integer = AxPLServer1.GetFormID(e.id)

        If formID = MAIN_FORM Then
            DataFromMainForm(e.id)
        ElseIf formID = FORM_1 Then
            DataFromForm1(e.id)
        ElseIf formID = FORM_2 Then
            DataFromForm2(e.id)
        End If

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        AxPLServer1.StartServer(2300)
    End Sub

    Private Sub SendMainForm(ByVal id As Integer)

        AxPLServer1.ClearForm(id) 'Clearing existing stuff
        AxPLServer1.What(id, 0) 'Make sure we do not send "what" at this point
        AxPLServer1.TextEx(id, 3, "* Main menu*")
        AxPLServer1.Button(id, POS_FORM_1, "[Form1]")
        AxPLServer1.Button(id, POS_FORM_2, "[Form2]")

        'Set formID
        AxPLServer1.SetFormID(id, MAIN_FORM)
        'Send all
        AxPLServer1.Send(id, MAIN_FORM)
    End Sub
    Private Sub DataFromMainForm(ByVal id As Integer)

        If AxPLServer1.IsData(id, POS_FORM_1) = True Then
            'Data from form 1
            SendForm1(id)
        ElseIf AxPLServer1.IsData(id, POS_FORM_2) = True Then
            'Data from form 2
            SendForm2(id)
       
        End If

    End Sub

    Private Sub SendForm1(ByVal id As Integer)
        AxPLServer1.ClearForm(id)
        AxPLServer1.TextEx(id, 20, "Scan code:")
        AxPLServer1.NewFieldEx(id, 40, 13, STYLE_SND_ENTER + STYLE_FLD_READER + STYLE_FLD_ACTIVE + STYLE_OVR)
        AxPLServer1.SetFormID(id, FORM_1)
        AxPLServer1.Send(id, FORM_1)
    End Sub
    Private Sub DataFromForm1(ByVal id As Integer)

        Dim code As String
        code = AxPLServer1.GetData(id, 40)
        ListBox1.Items.Add(code)

        'Giving answer to HS
        AxPLServer1.PopMessage(id, 20, "Thanks for the code: " & code)
        AxPLServer1.FieldCmd(id, 40, 2) ' Clears the field
        AxPLServer1.Send(id, -1)

    End Sub

    Private Sub SendForm2(ByVal id As Integer)
        AxPLServer1.ClearForm(id)
        AxPLServer1.TextEx(id, 20, "Msg from host:")
        AxPLServer1.Button(id, 140, "[Close]")
        AxPLServer1.What(id, 5)
        AxPLServer1.SetFormID(id, FORM_2)
        AxPLServer1.Send(id, FORM_2)
    End Sub
    Private Sub DataFromForm2(ByVal id As Integer)

        If AxPLServer1.IsData(id, 140) = True Then
            AxPLServer1.What(id, 0)
            SendMainForm(id)
        End If

    End Sub

    Private Sub AxPLServer1_WhatEvent(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_WhatEvent) Handles AxPLServer1.WhatEvent

        If TextBox1.TextLength > 0 Then
            'Clear existing text
            AxPLServer1.ClearCmd(e.id, 1, 60, 139)
            AxPLServer1.TextEx(e.id, 60, TextBox1.Text)
            AxPLServer1.Bell(e.id)
        Else
            AxPLServer1.Ack(e.id)
        End If

        AxPLServer1.Send(e.id, -1)

    End Sub
End Class

