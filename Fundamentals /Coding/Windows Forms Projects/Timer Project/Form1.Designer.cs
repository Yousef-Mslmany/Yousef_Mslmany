namespace Tick_Tack_Project
{
    partial class frmTick_Tack
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
            this.btnCurrent_Clock = new System.Windows.Forms.Button();
            this.btnTimer = new System.Windows.Forms.Button();
            this.btnStop_Watch = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnCurrent_Clock
            // 
            this.btnCurrent_Clock.BackColor = System.Drawing.Color.PaleGreen;
            this.btnCurrent_Clock.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnCurrent_Clock.Location = new System.Drawing.Point(322, 49);
            this.btnCurrent_Clock.Name = "btnCurrent_Clock";
            this.btnCurrent_Clock.Size = new System.Drawing.Size(150, 46);
            this.btnCurrent_Clock.TabIndex = 0;
            this.btnCurrent_Clock.Text = "Current Clock";
            this.btnCurrent_Clock.UseVisualStyleBackColor = false;
            this.btnCurrent_Clock.Click += new System.EventHandler(this.btnCurrent_Clock_Click);
            // 
            // btnTimer
            // 
            this.btnTimer.BackColor = System.Drawing.Color.PaleGreen;
            this.btnTimer.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnTimer.Location = new System.Drawing.Point(322, 126);
            this.btnTimer.Name = "btnTimer";
            this.btnTimer.Size = new System.Drawing.Size(150, 45);
            this.btnTimer.TabIndex = 1;
            this.btnTimer.Text = "Timer";
            this.btnTimer.UseVisualStyleBackColor = false;
            this.btnTimer.Click += new System.EventHandler(this.btnTimer_Click);
            // 
            // btnStop_Watch
            // 
            this.btnStop_Watch.BackColor = System.Drawing.Color.PaleGreen;
            this.btnStop_Watch.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold);
            this.btnStop_Watch.Location = new System.Drawing.Point(322, 203);
            this.btnStop_Watch.Name = "btnStop_Watch";
            this.btnStop_Watch.Size = new System.Drawing.Size(150, 44);
            this.btnStop_Watch.TabIndex = 2;
            this.btnStop_Watch.Text = "Stop Watch";
            this.btnStop_Watch.UseVisualStyleBackColor = false;
            this.btnStop_Watch.Click += new System.EventHandler(this.btnStop_Watch_Click);
            // 
            // frmTick_Tack
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(788, 286);
            this.Controls.Add(this.btnStop_Watch);
            this.Controls.Add(this.btnTimer);
            this.Controls.Add(this.btnCurrent_Clock);
            this.Name = "frmTick_Tack";
            this.Text = "Tick Tack";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnCurrent_Clock;
        private System.Windows.Forms.Button btnTimer;
        private System.Windows.Forms.Button btnStop_Watch;
    }
}

