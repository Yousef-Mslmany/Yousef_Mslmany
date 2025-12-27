namespace Tick_Tack_Project
{
    partial class frmCurrent_Clock
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
            this.lblCurrnt_Clock = new System.Windows.Forms.Label();
            this.lblCurrent_Clock = new System.Windows.Forms.Label();
            this.tmrCurrent_Clock = new System.Windows.Forms.Timer(this.components);
            this.SuspendLayout();
            // 
            // lblCurrnt_Clock
            // 
            this.lblCurrnt_Clock.AutoSize = true;
            this.lblCurrnt_Clock.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrnt_Clock.ForeColor = System.Drawing.Color.White;
            this.lblCurrnt_Clock.Location = new System.Drawing.Point(326, 56);
            this.lblCurrnt_Clock.Name = "lblCurrnt_Clock";
            this.lblCurrnt_Clock.Size = new System.Drawing.Size(170, 28);
            this.lblCurrnt_Clock.TabIndex = 0;
            this.lblCurrnt_Clock.Text = "Current Clock";
            this.lblCurrnt_Clock.Click += new System.EventHandler(this.lblCurrnt_Clock_Click);
            // 
            // lblCurrent_Clock
            // 
            this.lblCurrent_Clock.AutoSize = true;
            this.lblCurrent_Clock.Font = new System.Drawing.Font("Tahoma", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCurrent_Clock.ForeColor = System.Drawing.Color.Bisque;
            this.lblCurrent_Clock.Location = new System.Drawing.Point(311, 121);
            this.lblCurrent_Clock.Name = "lblCurrent_Clock";
            this.lblCurrent_Clock.Size = new System.Drawing.Size(44, 48);
            this.lblCurrent_Clock.TabIndex = 1;
            this.lblCurrent_Clock.Text = "  ";
            this.lblCurrent_Clock.Click += new System.EventHandler(this.lblCurrent_Clock_Click);
            // 
            // tmrCurrent_Clock
            // 
            this.tmrCurrent_Clock.Enabled = true;
            this.tmrCurrent_Clock.Interval = 1000;
            this.tmrCurrent_Clock.Tick += new System.EventHandler(this.tmrCurrent_Clock_Tick);
            // 
            // frmCurrent_Clock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(788, 286);
            this.Controls.Add(this.lblCurrent_Clock);
            this.Controls.Add(this.lblCurrnt_Clock);
            this.Name = "frmCurrent_Clock";
            this.Text = "Current Clock";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblCurrnt_Clock;
        private System.Windows.Forms.Label lblCurrent_Clock;
        private System.Windows.Forms.Timer tmrCurrent_Clock;
    }
}