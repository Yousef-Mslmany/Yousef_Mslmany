namespace Encryption_Decryption_Project
{
    partial class frmEncryption_Decryption_Project
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
            this.lblEncryption = new System.Windows.Forms.Label();
            this.lblDecryption = new System.Windows.Forms.Label();
            this.lblOriginal_Text = new System.Windows.Forms.Label();
            this.lblText_Decrypted = new System.Windows.Forms.Label();
            this.txtOriginal_Text = new System.Windows.Forms.TextBox();
            this.txtDecryption = new System.Windows.Forms.TextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.openFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnEncryption = new System.Windows.Forms.Button();
            this.btnReset_En = new System.Windows.Forms.Button();
            this.btnDecryption = new System.Windows.Forms.Button();
            this.btnReset_De = new System.Windows.Forms.Button();
            this.lblOriginal_Text2 = new System.Windows.Forms.Label();
            this.lblText_Decrypted2 = new System.Windows.Forms.Label();
            this.txtDecryption2 = new System.Windows.Forms.TextBox();
            this.txtOriginal_Text2 = new System.Windows.Forms.TextBox();
            this.btnSave_1 = new System.Windows.Forms.Button();
            this.btnSave_2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.SaveTextFile = new System.Windows.Forms.SaveFileDialog();
            this.OpenTextFile = new System.Windows.Forms.OpenFileDialog();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblEncryption
            // 
            this.lblEncryption.AutoSize = true;
            this.lblEncryption.Font = new System.Drawing.Font("Rockwell", 25.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblEncryption.Location = new System.Drawing.Point(160, 41);
            this.lblEncryption.Name = "lblEncryption";
            this.lblEncryption.Size = new System.Drawing.Size(257, 53);
            this.lblEncryption.TabIndex = 0;
            this.lblEncryption.Text = "Encryption";
            // 
            // lblDecryption
            // 
            this.lblDecryption.AutoSize = true;
            this.lblDecryption.Font = new System.Drawing.Font("Rockwell", 25.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblDecryption.Location = new System.Drawing.Point(910, 41);
            this.lblDecryption.Name = "lblDecryption";
            this.lblDecryption.Size = new System.Drawing.Size(260, 53);
            this.lblDecryption.TabIndex = 1;
            this.lblDecryption.Text = "Decryption";
            // 
            // lblOriginal_Text
            // 
            this.lblOriginal_Text.AutoSize = true;
            this.lblOriginal_Text.Font = new System.Drawing.Font("Rockwell", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOriginal_Text.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.lblOriginal_Text.Location = new System.Drawing.Point(88, 128);
            this.lblOriginal_Text.Name = "lblOriginal_Text";
            this.lblOriginal_Text.Size = new System.Drawing.Size(250, 41);
            this.lblOriginal_Text.TabIndex = 2;
            this.lblOriginal_Text.Text = "Original Text:";
            // 
            // lblText_Decrypted
            // 
            this.lblText_Decrypted.AutoSize = true;
            this.lblText_Decrypted.Font = new System.Drawing.Font("Rockwell", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblText_Decrypted.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.lblText_Decrypted.Location = new System.Drawing.Point(831, 128);
            this.lblText_Decrypted.Name = "lblText_Decrypted";
            this.lblText_Decrypted.Size = new System.Drawing.Size(282, 41);
            this.lblText_Decrypted.TabIndex = 3;
            this.lblText_Decrypted.Text = "Text Decrypted:";
            // 
            // txtOriginal_Text
            // 
            this.txtOriginal_Text.Font = new System.Drawing.Font("Rockwell", 12F);
            this.txtOriginal_Text.Location = new System.Drawing.Point(95, 186);
            this.txtOriginal_Text.Multiline = true;
            this.txtOriginal_Text.Name = "txtOriginal_Text";
            this.txtOriginal_Text.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtOriginal_Text.Size = new System.Drawing.Size(471, 180);
            this.txtOriginal_Text.TabIndex = 4;
            this.txtOriginal_Text.Enter += new System.EventHandler(this.txtOriginal_Text_Enter);
            this.txtOriginal_Text.Leave += new System.EventHandler(this.txtOriginal_Text_Leave);
            // 
            // txtDecryption
            // 
            this.txtDecryption.ContextMenuStrip = this.contextMenuStrip1;
            this.txtDecryption.Font = new System.Drawing.Font("Rockwell", 12F);
            this.txtDecryption.Location = new System.Drawing.Point(838, 186);
            this.txtDecryption.Multiline = true;
            this.txtDecryption.Name = "txtDecryption";
            this.txtDecryption.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtDecryption.Size = new System.Drawing.Size(471, 180);
            this.txtDecryption.TabIndex = 5;
            this.txtDecryption.Enter += new System.EventHandler(this.txtDecryption_Enter);
            this.txtDecryption.Leave += new System.EventHandler(this.txtDecryption_Leave);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(220, 28);
            // 
            // openFileToolStripMenuItem
            // 
            this.openFileToolStripMenuItem.Name = "openFileToolStripMenuItem";
            this.openFileToolStripMenuItem.Size = new System.Drawing.Size(219, 24);
            this.openFileToolStripMenuItem.Text = "Open File To Get Text";
            this.openFileToolStripMenuItem.Click += new System.EventHandler(this.openFileToolStripMenuItem_Click);
            // 
            // btnEncryption
            // 
            this.btnEncryption.BackColor = System.Drawing.Color.Orange;
            this.btnEncryption.Font = new System.Drawing.Font("Rockwell", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnEncryption.Location = new System.Drawing.Point(127, 393);
            this.btnEncryption.Name = "btnEncryption";
            this.btnEncryption.Size = new System.Drawing.Size(156, 48);
            this.btnEncryption.TabIndex = 6;
            this.btnEncryption.Text = "Encryption";
            this.btnEncryption.UseVisualStyleBackColor = false;
            this.btnEncryption.Click += new System.EventHandler(this.btnEncryption_Click);
            // 
            // btnReset_En
            // 
            this.btnReset_En.BackColor = System.Drawing.Color.OrangeRed;
            this.btnReset_En.Font = new System.Drawing.Font("Rockwell", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnReset_En.Location = new System.Drawing.Point(366, 393);
            this.btnReset_En.Name = "btnReset_En";
            this.btnReset_En.Size = new System.Drawing.Size(156, 48);
            this.btnReset_En.TabIndex = 7;
            this.btnReset_En.Text = "Reset";
            this.btnReset_En.UseVisualStyleBackColor = false;
            this.btnReset_En.Click += new System.EventHandler(this.btnReset_En_Click);
            // 
            // btnDecryption
            // 
            this.btnDecryption.BackColor = System.Drawing.Color.Orange;
            this.btnDecryption.Font = new System.Drawing.Font("Rockwell", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnDecryption.Location = new System.Drawing.Point(878, 393);
            this.btnDecryption.Name = "btnDecryption";
            this.btnDecryption.Size = new System.Drawing.Size(156, 48);
            this.btnDecryption.TabIndex = 8;
            this.btnDecryption.Text = "Decryption";
            this.btnDecryption.UseVisualStyleBackColor = false;
            this.btnDecryption.Click += new System.EventHandler(this.btnDecryption_Click);
            // 
            // btnReset_De
            // 
            this.btnReset_De.BackColor = System.Drawing.Color.OrangeRed;
            this.btnReset_De.Font = new System.Drawing.Font("Rockwell", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnReset_De.Location = new System.Drawing.Point(1111, 393);
            this.btnReset_De.Name = "btnReset_De";
            this.btnReset_De.Size = new System.Drawing.Size(156, 48);
            this.btnReset_De.TabIndex = 9;
            this.btnReset_De.Text = "Reset";
            this.btnReset_De.UseVisualStyleBackColor = false;
            this.btnReset_De.Click += new System.EventHandler(this.btnReset_De_Click);
            // 
            // lblOriginal_Text2
            // 
            this.lblOriginal_Text2.AutoSize = true;
            this.lblOriginal_Text2.Font = new System.Drawing.Font("Rockwell", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblOriginal_Text2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.lblOriginal_Text2.Location = new System.Drawing.Point(831, 482);
            this.lblOriginal_Text2.Name = "lblOriginal_Text2";
            this.lblOriginal_Text2.Size = new System.Drawing.Size(250, 41);
            this.lblOriginal_Text2.TabIndex = 10;
            this.lblOriginal_Text2.Text = "Original Text:";
            // 
            // lblText_Decrypted2
            // 
            this.lblText_Decrypted2.AutoSize = true;
            this.lblText_Decrypted2.Font = new System.Drawing.Font("Rockwell", 19.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblText_Decrypted2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.lblText_Decrypted2.Location = new System.Drawing.Point(88, 482);
            this.lblText_Decrypted2.Name = "lblText_Decrypted2";
            this.lblText_Decrypted2.Size = new System.Drawing.Size(282, 41);
            this.lblText_Decrypted2.TabIndex = 11;
            this.lblText_Decrypted2.Text = "Text Decrypted:";
            // 
            // txtDecryption2
            // 
            this.txtDecryption2.Font = new System.Drawing.Font("Rockwell", 12F);
            this.txtDecryption2.Location = new System.Drawing.Point(95, 538);
            this.txtDecryption2.Multiline = true;
            this.txtDecryption2.Name = "txtDecryption2";
            this.txtDecryption2.Size = new System.Drawing.Size(471, 180);
            this.txtDecryption2.TabIndex = 12;
            // 
            // txtOriginal_Text2
            // 
            this.txtOriginal_Text2.Font = new System.Drawing.Font("Rockwell", 12F);
            this.txtOriginal_Text2.Location = new System.Drawing.Point(838, 538);
            this.txtOriginal_Text2.Multiline = true;
            this.txtOriginal_Text2.Name = "txtOriginal_Text2";
            this.txtOriginal_Text2.Size = new System.Drawing.Size(471, 180);
            this.txtOriginal_Text2.TabIndex = 13;
            // 
            // btnSave_1
            // 
            this.btnSave_1.BackColor = System.Drawing.Color.Orange;
            this.btnSave_1.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSave_1.ForeColor = System.Drawing.SystemColors.GrayText;
            this.btnSave_1.Location = new System.Drawing.Point(268, 736);
            this.btnSave_1.Name = "btnSave_1";
            this.btnSave_1.Size = new System.Drawing.Size(156, 48);
            this.btnSave_1.TabIndex = 14;
            this.btnSave_1.Text = "Save";
            this.btnSave_1.UseVisualStyleBackColor = false;
            this.btnSave_1.Click += new System.EventHandler(this.btnSave_1_Click);
            // 
            // btnSave_2
            // 
            this.btnSave_2.BackColor = System.Drawing.Color.Orange;
            this.btnSave_2.Font = new System.Drawing.Font("Rockwell", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSave_2.ForeColor = System.Drawing.SystemColors.GrayText;
            this.btnSave_2.Location = new System.Drawing.Point(1021, 736);
            this.btnSave_2.Name = "btnSave_2";
            this.btnSave_2.Size = new System.Drawing.Size(156, 48);
            this.btnSave_2.TabIndex = 15;
            this.btnSave_2.Text = "Save";
            this.btnSave_2.UseVisualStyleBackColor = false;
            this.btnSave_2.Click += new System.EventHandler(this.btnSave_2_Click);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.White;
            this.panel1.Location = new System.Drawing.Point(686, 18);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(3, 775);
            this.panel1.TabIndex = 17;
            // 
            // OpenTextFile
            // 
            this.OpenTextFile.FileName = "openFileDialog1";
            // 
            // frmEncryption_Decryption_Project
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.NavajoWhite;
            this.ClientSize = new System.Drawing.Size(1382, 810);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.btnSave_2);
            this.Controls.Add(this.btnSave_1);
            this.Controls.Add(this.txtOriginal_Text2);
            this.Controls.Add(this.txtDecryption2);
            this.Controls.Add(this.lblText_Decrypted2);
            this.Controls.Add(this.lblOriginal_Text2);
            this.Controls.Add(this.btnReset_De);
            this.Controls.Add(this.btnDecryption);
            this.Controls.Add(this.btnReset_En);
            this.Controls.Add(this.btnEncryption);
            this.Controls.Add(this.txtDecryption);
            this.Controls.Add(this.txtOriginal_Text);
            this.Controls.Add(this.lblText_Decrypted);
            this.Controls.Add(this.lblOriginal_Text);
            this.Controls.Add(this.lblDecryption);
            this.Controls.Add(this.lblEncryption);
            this.Name = "frmEncryption_Decryption_Project";
            this.Text = "Encryption Decryption Project";
            this.Load += new System.EventHandler(this.frmEncryption_Decryption_Project_Load);
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblEncryption;
        private System.Windows.Forms.Label lblDecryption;
        private System.Windows.Forms.Label lblOriginal_Text;
        private System.Windows.Forms.Label lblText_Decrypted;
        private System.Windows.Forms.TextBox txtOriginal_Text;
        private System.Windows.Forms.TextBox txtDecryption;
        private System.Windows.Forms.Button btnEncryption;
        private System.Windows.Forms.Button btnReset_En;
        private System.Windows.Forms.Button btnDecryption;
        private System.Windows.Forms.Button btnReset_De;
        private System.Windows.Forms.Label lblOriginal_Text2;
        private System.Windows.Forms.Label lblText_Decrypted2;
        private System.Windows.Forms.TextBox txtDecryption2;
        private System.Windows.Forms.TextBox txtOriginal_Text2;
        private System.Windows.Forms.Button btnSave_1;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem openFileToolStripMenuItem;
        private System.Windows.Forms.Button btnSave_2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.SaveFileDialog SaveTextFile;
        private System.Windows.Forms.OpenFileDialog OpenTextFile;
    }
}

