'NORDIC ID DEMO SOFTWARE DISCLAIMER

'You are about to use Nordic ID Demo Software (“Software”).
'It is explicitly stated that Nordic ID does not give any kind of warranties, expressed or implied, for this Software.
'Software is provided “as is” and with all faults.
'Under no circumstances is Nordic ID liable for any direct, special, incidental or indirect damages or for any economic consequential damages to you or to any third party.
'The use of this software indicates your complete and unconditional understanding of the terms of this disclaimer.
'IF YOU DO NOT AGREE OF THE TERMS OF THIS DISCLAIMER, DO NOT USE THE SOFTWARE.
'-----------------------------------------------------------------------------

'------------ SWedge ------------------------------
'This program sends string from the hand terminal to the active window as if typed at the keybord.
'Line feed character added.
'Use real hand terminal to test this because Nordic ID Thin client PC software will be that "active window" which receives keystrokes.
'Version 1.0 8.4.2011 Ari Pöyhönen
'----------------------------------------------------------

Public Class SWedge

    'NEW_FIELD_EX constants
    Const SND_ENTER As Byte = 1
    Const NO_SEND As Byte = 2
    Const SND_ALL As Byte = 4
    Const FLD_LOCK As Byte = 8
    Const OVR As Byte = 16
    Const FLD_READER As Byte = 32
    Const READER_DEFAULT As Byte = 64
    Const FLD_ACTIVE As Byte = 128

    Private Sub BSConnBut_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BSConnBut.Click
        AxPLServer1.OpenBSConnections()
    End Sub

    Private Sub AxPLServer1_DataArrived(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent) Handles AxPLServer1.DataArrived

        Dim data As String

        If e.frameid = -1 Then
            AxPLServer1.ClearForm(e.id)
            AxPLServer1.TextEx(e.id, 0, "*Software wedge*")
            AxPLServer1.NewFieldEx(e.id, 20, 63, FLD_ACTIVE + FLD_READER + OVR + SND_ENTER)
            AxPLServer1.Send(e.id, 10)
            Exit Sub
        End If

        data = AxPLServer1.GetData(e.id, 20)
        System.Windows.Forms.SendKeys.SendWait(data & "{ENTER}")

        If Chk1.Checked = True Then
            'Special command to HS for starting Laser scanning. Just emulate SCAN key press
            AxPLServer1.SpecialCmd(e.id, 1, 6)
        Else
            AxPLServer1.Ack(e.id) 'or send just ack
        End If

        AxPLServer1.Send(e.id, -1)

    End Sub
End Class
