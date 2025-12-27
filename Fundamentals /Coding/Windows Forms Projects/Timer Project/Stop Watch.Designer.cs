namespace Tick_Tack_Project
{
    partial class frmStop_Watch
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
            this.btnStart = new System.Windows.Forms.Button();
            this.btnStop = new System.Windows.Forms.Button();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.lblTimer = new System.Windows.Forms.Label();
            this.lblSeconds = new System.Windows.Forms.Label();
            this.lblMinutes = new System.Windows.Forms.Label();
            this.lblHours = new System.Windows.Forms.Label();
            this.cbHours = new System.Windows.Forms.ComboBox();
            this.cbMinutes = new System.Windows.Forms.ComboBox();
            this.cbSeconds = new System.Windows.Forms.ComboBox();
            this.tmr = new System.Windows.Forms.Timer(this.components);
            this.notifyIcon1 = new System.Windows.Forms.NotifyIcon(this.components);
            this.SuspendLayout();
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.DarkOrange;
            this.btnStart.Location = new System.Drawing.Point(179, 215);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(97, 44);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.OrangeRed;
            this.btnStop.Location = new System.Drawing.Point(499, 215);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(97, 44);
            this.btnStop.TabIndex = 3;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(230, 120);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(320, 32);
            this.progressBar.Step = 1;
            this.progressBar.TabIndex = 4;
            this.progressBar.Value = 1;
            // 
            // lblTimer
            // 
            this.lblTimer.AutoSize = true;
            this.lblTimer.Font = new System.Drawing.Font("Consolas", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTimer.ForeColor = System.Drawing.Color.White;
            this.lblTimer.Location = new System.Drawing.Point(289, 155);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(196, 47);
            this.lblTimer.TabIndex = 5;
            this.lblTimer.Text = "00:00:00";
            // 
            // lblSeconds
            // 
            this.lblSeconds.AutoSize = true;
            this.lblSeconds.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSeconds.Location = new System.Drawing.Point(602, 9);
            this.lblSeconds.Name = "lblSeconds";
            this.lblSeconds.Size = new System.Drawing.Size(85, 22);
            this.lblSeconds.TabIndex = 6;
            this.lblSeconds.Text = "Seconds";
            // 
            // lblMinutes
            // 
            this.lblMinutes.AutoSize = true;
            this.lblMinutes.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMinutes.Location = new System.Drawing.Point(334, 9);
            this.lblMinutes.Name = "lblMinutes";
            this.lblMinutes.Size = new System.Drawing.Size(82, 22);
            this.lblMinutes.TabIndex = 7;
            this.lblMinutes.Text = "Minutes";
            // 
            // lblHours
            // 
            this.lblHours.AutoSize = true;
            this.lblHours.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblHours.Location = new System.Drawing.Point(84, 9);
            this.lblHours.Name = "lblHours";
            this.lblHours.Size = new System.Drawing.Size(64, 22);
            this.lblHours.TabIndex = 8;
            this.lblHours.Text = "Hours";
            // 
            // cbHours
            // 
            this.cbHours.FormattingEnabled = true;
            this.cbHours.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23"});
            this.cbHours.Location = new System.Drawing.Point(69, 34);
            this.cbHours.Name = "cbHours";
            this.cbHours.Size = new System.Drawing.Size(99, 24);
            this.cbHours.TabIndex = 9;
            this.cbHours.Text = "0";
            this.cbHours.SelectedIndexChanged += new System.EventHandler(this.cbHours_SelectedIndexChanged);
            // 
            // cbMinutes
            // 
            this.cbMinutes.FormattingEnabled = true;
            this.cbMinutes.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59"});
            this.cbMinutes.Location = new System.Drawing.Point(325, 34);
            this.cbMinutes.Name = "cbMinutes";
            this.cbMinutes.Size = new System.Drawing.Size(100, 24);
            this.cbMinutes.TabIndex = 10;
            this.cbMinutes.Text = "0";
            this.cbMinutes.SelectedIndexChanged += new System.EventHandler(this.cbMinutes_SelectedIndexChanged);
            // 
            // cbSeconds
            // 
            this.cbSeconds.FormattingEnabled = true;
            this.cbSeconds.Items.AddRange(new object[] {
            "0",
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "20",
            "21",
            "22",
            "23",
            "24",
            "25",
            "26",
            "27",
            "28",
            "29",
            "30",
            "31",
            "32",
            "33",
            "34",
            "35",
            "36",
            "37",
            "38",
            "39",
            "40",
            "41",
            "42",
            "43",
            "44",
            "45",
            "46",
            "47",
            "48",
            "49",
            "50",
            "51",
            "52",
            "53",
            "54",
            "55",
            "56",
            "57",
            "58",
            "59"});
            this.cbSeconds.Location = new System.Drawing.Point(597, 34);
            this.cbSeconds.Name = "cbSeconds";
            this.cbSeconds.Size = new System.Drawing.Size(100, 24);
            this.cbSeconds.TabIndex = 11;
            this.cbSeconds.Text = "0";
            this.cbSeconds.SelectedIndexChanged += new System.EventHandler(this.cbSeconds_SelectedIndexChanged);
            // 
            // tmr
            // 
            this.tmr.Enabled = true;
            this.tmr.Interval = 1000;
            this.tmr.Tick += new System.EventHandler(this.tmr_Tick);
            // 
            // notifyIcon1
            // 
            this.notifyIcon1.BalloonTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.notifyIcon1.Text = "notifyIcon1";
            this.notifyIcon1.Visible = true;
            // 
            // frmStop_Watch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkSlateGray;
            this.ClientSize = new System.Drawing.Size(788, 286);
            this.Controls.Add(this.cbSeconds);
            this.Controls.Add(this.cbMinutes);
            this.Controls.Add(this.cbHours);
            this.Controls.Add(this.lblHours);
            this.Controls.Add(this.lblMinutes);
            this.Controls.Add(this.lblSeconds);
            this.Controls.Add(this.lblTimer);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Name = "frmStop_Watch";
            this.Text = "Stop Watch";
            this.Load += new System.EventHandler(this.frmStop_Watch_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.Label lblSeconds;
        private System.Windows.Forms.Label lblMinutes;
        private System.Windows.Forms.Label lblHours;
        private System.Windows.Forms.ComboBox cbHours;
        private System.Windows.Forms.ComboBox cbMinutes;
        private System.Windows.Forms.ComboBox cbSeconds;
        private System.Windows.Forms.Timer tmr;
        private System.Windows.Forms.NotifyIcon notifyIcon1;
    }
}