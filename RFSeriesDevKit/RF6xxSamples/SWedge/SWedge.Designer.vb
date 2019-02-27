<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class SWedge
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(SWedge))
        Me.AxPLServer1 = New AxPLSERVERLib.AxPLServer()
        Me.Chk1 = New System.Windows.Forms.CheckBox()
        Me.BSConnBut = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'AxPLServer1
        '
        Me.AxPLServer1.Enabled = True
        Me.AxPLServer1.Location = New System.Drawing.Point(13, 28)
        Me.AxPLServer1.Name = "AxPLServer1"
        Me.AxPLServer1.OcxState = CType(resources.GetObject("AxPLServer1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.AxPLServer1.Size = New System.Drawing.Size(230, 78)
        Me.AxPLServer1.TabIndex = 0
        '
        'Chk1
        '
        Me.Chk1.Location = New System.Drawing.Point(13, 172)
        Me.Chk1.Name = "Chk1"
        Me.Chk1.Size = New System.Drawing.Size(192, 16)
        Me.Chk1.TabIndex = 6
        Me.Chk1.Text = "Activate scanner automatically"
        '
        'BSConnBut
        '
        Me.BSConnBut.Location = New System.Drawing.Point(13, 204)
        Me.BSConnBut.Name = "BSConnBut"
        Me.BSConnBut.Size = New System.Drawing.Size(208, 32)
        Me.BSConnBut.TabIndex = 5
        Me.BSConnBut.Text = "Base station connections"
        '
        'Label1
        '
        Me.Label1.BackColor = System.Drawing.SystemColors.Control
        Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label1.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label1.Location = New System.Drawing.Point(13, 116)
        Me.Label1.Name = "Label1"
        Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label1.Size = New System.Drawing.Size(225, 53)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "This program sends string from the hand terminal to the active window as if typed" & _
            " at the keybord. Line feed character added."
        '
        'SWedge
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(255, 247)
        Me.Controls.Add(Me.Chk1)
        Me.Controls.Add(Me.BSConnBut)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.AxPLServer1)
        Me.Name = "SWedge"
        Me.Text = "Software Wedge"
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents AxPLServer1 As AxPLSERVERLib.AxPLServer
    Friend WithEvents Chk1 As System.Windows.Forms.CheckBox
    Friend WithEvents BSConnBut As System.Windows.Forms.Button
    Public WithEvents Label1 As System.Windows.Forms.Label

End Class
