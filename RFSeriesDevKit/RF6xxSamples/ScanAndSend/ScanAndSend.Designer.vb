<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class ScanAndSend
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(ScanAndSend))
        Me.AxPLServer1 = New AxPLSERVERLib.AxPLServer()
        Me.BSConnBut = New System.Windows.Forms.Button()
        Me.List1 = New System.Windows.Forms.ListBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label1 = New System.Windows.Forms.Label()
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'AxPLServer1
        '
        Me.AxPLServer1.Enabled = True
        Me.AxPLServer1.Location = New System.Drawing.Point(13, 13)
        Me.AxPLServer1.Name = "AxPLServer1"
        Me.AxPLServer1.OcxState = CType(resources.GetObject("AxPLServer1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.AxPLServer1.Size = New System.Drawing.Size(295, 110)
        Me.AxPLServer1.TabIndex = 0
        '
        'BSConnBut
        '
        Me.BSConnBut.Location = New System.Drawing.Point(314, 12)
        Me.BSConnBut.Name = "BSConnBut"
        Me.BSConnBut.Size = New System.Drawing.Size(168, 32)
        Me.BSConnBut.TabIndex = 10
        Me.BSConnBut.Text = "Base station connections"
        '
        'List1
        '
        Me.List1.BackColor = System.Drawing.SystemColors.Window
        Me.List1.Cursor = System.Windows.Forms.Cursors.Default
        Me.List1.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.List1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.List1.ItemHeight = 14
        Me.List1.Location = New System.Drawing.Point(13, 129)
        Me.List1.Name = "List1"
        Me.List1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.List1.Size = New System.Drawing.Size(209, 270)
        Me.List1.TabIndex = 7
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.SystemColors.Control
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(311, 146)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(313, 49)
        Me.Label2.TabIndex = 9
        Me.Label2.Text = "Listbox shows scanned barcodes 10 at the time. Hand terminal generates beep and f" & _
            "orm is cleared when all 10 barcodes has been sent to HOST."
        '
        'Label1
        '
        Me.Label1.BackColor = System.Drawing.SystemColors.Control
        Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label1.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label1.Location = New System.Drawing.Point(311, 75)
        Me.Label1.Name = "Label1"
        Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label1.Size = New System.Drawing.Size(313, 49)
        Me.Label1.TabIndex = 8
        Me.Label1.Text = "This demo creates 10 input fields into the hand terminal. When last input field (" & _
            "bottom) is filled with scanner, content of all lines are sent same time to HOST." & _
            ""
        '
        'ScanAndSend
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(656, 424)
        Me.Controls.Add(Me.BSConnBut)
        Me.Controls.Add(Me.List1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.AxPLServer1)
        Me.Name = "ScanAndSend"
        Me.Text = "ScanAndSend"
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents AxPLServer1 As AxPLSERVERLib.AxPLServer
    Friend WithEvents BSConnBut As System.Windows.Forms.Button
    Public WithEvents List1 As System.Windows.Forms.ListBox
    Public WithEvents Label2 As System.Windows.Forms.Label
    Public WithEvents Label1 As System.Windows.Forms.Label

End Class
