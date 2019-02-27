<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FastInventory
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FastInventory))
        Me.AxPLServer1 = New AxPLSERVERLib.AxPLServer()
        Me.BSBut = New System.Windows.Forms.Button()
        Me.IDChk = New System.Windows.Forms.CheckBox()
        Me.DateChk = New System.Windows.Forms.CheckBox()
        Me.OpenNotepadBut = New System.Windows.Forms.Button()
        Me.Path = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'AxPLServer1
        '
        Me.AxPLServer1.Enabled = True
        Me.AxPLServer1.Location = New System.Drawing.Point(12, 12)
        Me.AxPLServer1.Name = "AxPLServer1"
        Me.AxPLServer1.OcxState = CType(resources.GetObject("AxPLServer1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.AxPLServer1.Size = New System.Drawing.Size(351, 93)
        Me.AxPLServer1.TabIndex = 0
        '
        'BSBut
        '
        Me.BSBut.Location = New System.Drawing.Point(369, 12)
        Me.BSBut.Name = "BSBut"
        Me.BSBut.Size = New System.Drawing.Size(160, 32)
        Me.BSBut.TabIndex = 11
        Me.BSBut.Text = "Base station connections"
        '
        'IDChk
        '
        Me.IDChk.BackColor = System.Drawing.SystemColors.Control
        Me.IDChk.Cursor = System.Windows.Forms.Cursors.Default
        Me.IDChk.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.IDChk.ForeColor = System.Drawing.SystemColors.ControlText
        Me.IDChk.Location = New System.Drawing.Point(13, 179)
        Me.IDChk.Name = "IDChk"
        Me.IDChk.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.IDChk.Size = New System.Drawing.Size(129, 17)
        Me.IDChk.TabIndex = 16
        Me.IDChk.Text = "Add Hand Terminal ID"
        Me.IDChk.UseVisualStyleBackColor = False
        '
        'DateChk
        '
        Me.DateChk.BackColor = System.Drawing.SystemColors.Control
        Me.DateChk.Cursor = System.Windows.Forms.Cursors.Default
        Me.DateChk.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.DateChk.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DateChk.Location = New System.Drawing.Point(13, 155)
        Me.DateChk.Name = "DateChk"
        Me.DateChk.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.DateChk.Size = New System.Drawing.Size(129, 17)
        Me.DateChk.TabIndex = 15
        Me.DateChk.Text = "Add Date and Time"
        Me.DateChk.UseVisualStyleBackColor = False
        '
        'OpenNotepadBut
        '
        Me.OpenNotepadBut.BackColor = System.Drawing.SystemColors.Control
        Me.OpenNotepadBut.Cursor = System.Windows.Forms.Cursors.Default
        Me.OpenNotepadBut.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.OpenNotepadBut.ForeColor = System.Drawing.SystemColors.ControlText
        Me.OpenNotepadBut.Location = New System.Drawing.Point(369, 115)
        Me.OpenNotepadBut.Name = "OpenNotepadBut"
        Me.OpenNotepadBut.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.OpenNotepadBut.Size = New System.Drawing.Size(129, 25)
        Me.OpenNotepadBut.TabIndex = 14
        Me.OpenNotepadBut.Text = "Open with Notepad"
        Me.OpenNotepadBut.UseVisualStyleBackColor = False
        '
        'Path
        '
        Me.Path.AcceptsReturn = True
        Me.Path.BackColor = System.Drawing.SystemColors.Window
        Me.Path.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Path.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Path.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Path.Location = New System.Drawing.Point(90, 115)
        Me.Path.MaxLength = 0
        Me.Path.Name = "Path"
        Me.Path.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Path.Size = New System.Drawing.Size(273, 20)
        Me.Path.TabIndex = 13
        Me.Path.Text = "C:\inventory.txt"
        '
        'Label1
        '
        Me.Label1.BackColor = System.Drawing.SystemColors.Control
        Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label1.Font = New System.Drawing.Font("Arial", 8.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label1.Location = New System.Drawing.Point(10, 115)
        Me.Label1.Name = "Label1"
        Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label1.Size = New System.Drawing.Size(73, 25)
        Me.Label1.TabIndex = 12
        Me.Label1.Text = "Inventory file:"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(542, 219)
        Me.Controls.Add(Me.IDChk)
        Me.Controls.Add(Me.DateChk)
        Me.Controls.Add(Me.OpenNotepadBut)
        Me.Controls.Add(Me.Path)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.BSBut)
        Me.Controls.Add(Me.AxPLServer1)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "Form1"
        Me.Text = "FastInventory"
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents AxPLServer1 As AxPLSERVERLib.AxPLServer
    Friend WithEvents BSBut As System.Windows.Forms.Button
    Public WithEvents IDChk As System.Windows.Forms.CheckBox
    Public WithEvents DateChk As System.Windows.Forms.CheckBox
    Public WithEvents OpenNotepadBut As System.Windows.Forms.Button
    Public WithEvents Path As System.Windows.Forms.TextBox
    Public WithEvents Label1 As System.Windows.Forms.Label

End Class
