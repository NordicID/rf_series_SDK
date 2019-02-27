namespace C_Sharp_MultiThread
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.axPLServer1 = new AxPLSERVERLib.AxPLServer();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.BSCONN_BUT = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.axPLServer1)).BeginInit();
            this.SuspendLayout();
            // 
            // axPLServer1
            // 
            this.axPLServer1.Enabled = true;
            this.axPLServer1.Location = new System.Drawing.Point(2, 2);
            this.axPLServer1.Name = "axPLServer1";
            this.axPLServer1.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axPLServer1.OcxState")));
            this.axPLServer1.Size = new System.Drawing.Size(402, 94);
            this.axPLServer1.TabIndex = 0;
            this.axPLServer1.DataArrived += new AxPLSERVERLib._DPLServerEvents_DataArrivedEventHandler(this.axPLServer1_DataArrived);
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(13, 115);
            this.listBox1.MultiColumn = true;
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(507, 238);
            this.listBox1.TabIndex = 2;
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // BSCONN_BUT
            // 
            this.BSCONN_BUT.Location = new System.Drawing.Point(411, 12);
            this.BSCONN_BUT.Name = "BSCONN_BUT";
            this.BSCONN_BUT.Size = new System.Drawing.Size(109, 34);
            this.BSCONN_BUT.TabIndex = 3;
            this.BSCONN_BUT.Text = "BS Connections";
            this.BSCONN_BUT.UseVisualStyleBackColor = true;
            this.BSCONN_BUT.Click += new System.EventHandler(this.BSCONN_BUT_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(532, 358);
            this.Controls.Add(this.BSCONN_BUT);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.axPLServer1);
            this.Name = "Form1";
            this.Text = "C# RF-Sample (Multithreaded data handler)";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.axPLServer1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private AxPLSERVERLib.AxPLServer axPLServer1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button BSCONN_BUT;
    }
}

