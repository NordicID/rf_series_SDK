'NORDIC ID DEMO SOFTWARE DISCLAIMER

'You are about to use Nordic ID Demo Software (“Software”).
'It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
'Software is provided “as is” and with all faults.
'Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
'The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
'IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.
'-----------------------------------------------------------------------------

'------------ FastInventory ------------------------------
'The Fast Inventory is a simple application for collecting data to the specific text file using the RF6xx hand terminal.
'Version 1.0 7.4.2011 Ari Pöyhönen
'----------------------------------------------------------


Public Class FastInventory

    'frameid constants
    Const COUNT_READ As Short = 20

    'NEW_FIELD_EX constants
    Const SND_ENTER As Byte = 1
    Const NO_SEND As Byte = 2
    Const SND_ALL As Byte = 4
    Const OVR As Byte = 16
    Const FLD_READER As Byte = 32
    Const READER_DEFAULT As Byte = 64
    Const FLD_ACTIVE As Byte = 128

    'Field position constants
    Const COUNT_POS As Short = 26 'count & Read form
    Const CODE_POS As Short = 46

    'DataArrived event handler of PLServer.
    'When user send data with hand terminal, this event is fired.

    Private Sub AxPLServer1_DataArrived(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent) Handles AxPLServer1.DataArrived
        Dim datastr As String

        If e.frameid = -1 Then 'Data from initial screen or from F-key
            datastr = AxPLServer1.GetData(e.id, -1)
            SendCountAndReadForm((e.id)) 'Send the form
        End If

        '*********Data from forms***********
        If e.frameid = COUNT_READ Then
            DataFromCountAndReadForm((e.id))
        Else
            SendCountAndReadForm((e.id))
        End If
    End Sub

    Private Sub SendCountAndReadForm(ByVal id As Integer)

        Dim retval As Boolean 'PLserver methods usually returns boolean value

        AxPLServer1.ClearForm(id) 'Clear all
        retval = AxPLServer1.TextEx(id, 0, "*Count & Read*")
        retval = AxPLServer1.TextEx(id, 20, "Count:")
        retval = AxPLServer1.TextEx(id, 40, "Code :")
        retval = AxPLServer1.NewFieldEx(id, COUNT_POS, 4, OVR + FLD_ACTIVE)
        retval = AxPLServer1.NewFieldEx(id, CODE_POS, 13, SND_ENTER + SND_ALL + OVR + FLD_READER + READER_DEFAULT)

        retval = AxPLServer1.Send(id, COUNT_READ)

    End Sub

    Private Sub DataFromCountAndReadForm(ByVal id As Integer)

        Dim retval As Boolean
        Dim count As String
        Dim code As String
        Dim linetxt As String
        Dim MyXL As Object ' Variable to hold reference

        Const ForReading As Short = 1
        Const ForWriting As Short = 2
        Const ForAppending As Short = 3
        Dim f, fs, ts As Object

        'Count and Code has arrived from hand terminal
        count = AxPLServer1.GetData(id, COUNT_POS)
        code = AxPLServer1.GetData(id, CODE_POS)

        linetxt = code & ";" & count

        'Adding current date and time
        If DateChk.CheckState = 1 Then
            linetxt = linetxt & ";" & CStr(Now)
        End If

        'Adding hand terminal ID value
        If IDChk.CheckState = 1 Then
            linetxt = linetxt & ";" & Str(id)
        End If

        fs = CreateObject("Scripting.FileSystemObject")
        On Error GoTo ErrorHandler
        If fs.FileExists(Path.Text) = False Then
            fs.CreateTextFile(Path.Text) 'Create a file if not exists
        End If

        f = fs.GetFile(Path.Text) 'Get file object
        ts = f.OpenAsTextStream(8, 0)

        ts.Write(linetxt & vbCrLf) 'Write to file and add linefeed
        ts.Close()

        retval = AxPLServer1.FieldCmd(id, COUNT_POS, FLD_ACTIVE) 'Set count field active
        retval = AxPLServer1.Send(id, -1) 'frameid -1 meens 'same as before'
        Exit Sub

ErrorHandler:
        If Err.Number = 76 Then
            retval = AxPLServer1.PopMessage(id, 22, "Path not found")
        Else
            retval = AxPLServer1.PopMessage(id, 22, "Can't open file")
        End If

        retval = AxPLServer1.Send(id, -1)

    End Sub

    Private Sub BSBut_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BSBut.Click
        AxPLServer1.OpenBSConnections()
    End Sub

    Private Sub OpenNotepadBut_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OpenNotepadBut.Click
        'Open notepad for viewing collected data
        Dim f As Double
        f = Shell("notepad " & Path.Text, AppWinStyle.NormalFocus)
    End Sub
End Class
