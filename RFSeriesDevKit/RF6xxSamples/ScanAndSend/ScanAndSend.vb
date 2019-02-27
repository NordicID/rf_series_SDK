
'NORDIC ID DEMO SOFTWARE DISCLAIMER

'You are about to use Nordic ID Demo Software (“Software”).
'It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
'Software is provided “as is” and with all faults.
'Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
'The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
'IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.
'-----------------------------------------------------------------------------

'------------ ScanAndSend ------------------------------
'The ScanAndSend creates 10 input fields into the hand terminal.
'When last input field (bottom) is filled with scanner, content of all lines are sent same time to HOST.
'Version 1.0 7.4.2011 Ari Pöyhönen
'----------------------------------------------------------

Public Class ScanAndSend

    'NEW_FIELD_EX constants
    Const SND_ENTER As Byte = 1
    Const NO_SEND As Byte = 2
    Const SND_ALL As Byte = 4
    Const FLD_LOCK As Byte = 8
    Const OVR As Byte = 16
    Const FLD_READER As Byte = 32
    Const READER_DEFAULT As Byte = 64
    Const FLD_ACTIVE As Byte = 128

    Private Sub AxPLServer1_DataArrived(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent) Handles AxPLServer1.DataArrived

        Dim formid As Integer

        formid = AxPLServer1.GetFormID(e.id)

        If formid = 100 And e.frameid <> -1 Then 'Data from inputfield form
            'let's read codes and print them into listbox
            List1.Items.Clear()
            List1.Items.Add((AxPLServer1.GetData(e.id, 23)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 43)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 63)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 83)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 103)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 123)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 143)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 163)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 183)))
            List1.Items.Add((AxPLServer1.GetData(e.id, 203)))

            AxPLServer1.ClearCmd(e.id, 4, 0, 239) 'clear field data
            AxPLServer1.Beep(e.id, 20, 1)
            AxPLServer1.Send(e.id, -1)
        Else
            'Let's send input field form
            AxPLServer1.ClearForm(e.id) 'clear screen

            AxPLServer1.NewFieldEx(e.id, 3, 13, FLD_READER + FLD_ACTIVE)
            AxPLServer1.NewFieldEx(e.id, 23, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 43, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 63, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 83, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 103, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 123, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 143, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 163, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 183, 13, FLD_READER)
            AxPLServer1.NewFieldEx(e.id, 203, 13, SND_ALL + FLD_READER) 'This field activates all sending
            AxPLServer1.SetFormID(e.id, 100)
            AxPLServer1.Send(e.id, -1)
        End If
    End Sub

    Private Sub BSConnBut_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BSConnBut.Click
        AxPLServer1.OpenBSConnections()
    End Sub
End Class
