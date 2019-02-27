Public Class Form1

    Private Sub AxPLServer1_DataArrived(ByVal sender As System.Object, ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent) Handles AxPLServer1.DataArrived

        Dim handlerThread As New System.Threading.Thread(AddressOf DataProcess)
        handlerThread.Start(e)

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        AxPLServer1.StartServer(3001)
    End Sub
    Private Sub DataProcess(ByVal e As AxPLSERVERLib._DPLServerEvents_DataArrivedEvent)

        Dim rassi As Integer

        rassi = AxPLServer1.GetRSSI(e.id)
        AxPLServer1.PopMessage(e.id, 21, "RSSI:" & rassi.ToString)
        AxPLServer1.Send(e.id, -1)
        Threading.Thread.Sleep(1000)

    End Sub
End Class
