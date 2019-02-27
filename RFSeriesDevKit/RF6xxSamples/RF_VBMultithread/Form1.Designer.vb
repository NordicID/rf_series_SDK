<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.AxPLServer1 = New AxPLSERVERLib.AxPLServer()
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'AxPLServer1
        '
        Me.AxPLServer1.Enabled = True
        Me.AxPLServer1.Location = New System.Drawing.Point(13, 13)
        Me.AxPLServer1.Name = "AxPLServer1"
        Me.AxPLServer1.OcxState = CType(resources.GetObject("AxPLServer1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.AxPLServer1.Size = New System.Drawing.Size(220, 94)
        Me.AxPLServer1.TabIndex = 0
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(249, 282)
        Me.Controls.Add(Me.AxPLServer1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.AxPLServer1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents AxPLServer1 As AxPLSERVERLib.AxPLServer

End Class
