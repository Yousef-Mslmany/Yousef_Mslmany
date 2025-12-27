namespace Memory_Game_Project
{
    partial class frmMemory_Game
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
            this.lblMemory_Game = new System.Windows.Forms.Label();
            this.gbGame_Details = new System.Windows.Forms.GroupBox();
            this.lblTimer = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.cbSpeed = new System.Windows.Forms.ComboBox();
            this.cbTimer = new System.Windows.Forms.ComboBox();
            this.lblSpeed = new System.Windows.Forms.Label();
            this.lable1 = new System.Windows.Forms.Label();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.btnStart = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.pbQuestion_Mark10 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark9 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark8 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark7 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark6 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark5 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark4 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark3 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark2 = new System.Windows.Forms.PictureBox();
            this.pbQuestion_Mark1 = new System.Windows.Forms.PictureBox();
            this.Star1 = new System.Windows.Forms.PictureBox();
            this.Star2 = new System.Windows.Forms.PictureBox();
            this.Star3 = new System.Windows.Forms.PictureBox();
            this.Star4 = new System.Windows.Forms.PictureBox();
            this.Star5 = new System.Windows.Forms.PictureBox();
            this.WrongMatchTimer = new System.Windows.Forms.Timer(this.components);
            this.gbGame_Details.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star5)).BeginInit();
            this.SuspendLayout();
            // 
            // lblMemory_Game
            // 
            this.lblMemory_Game.AutoSize = true;
            this.lblMemory_Game.Font = new System.Drawing.Font("Jozoor Font", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblMemory_Game.ForeColor = System.Drawing.Color.Yellow;
            this.lblMemory_Game.Location = new System.Drawing.Point(511, 9);
            this.lblMemory_Game.Name = "lblMemory_Game";
            this.lblMemory_Game.Size = new System.Drawing.Size(361, 80);
            this.lblMemory_Game.TabIndex = 0;
            this.lblMemory_Game.Text = "Memory Game";
            // 
            // gbGame_Details
            // 
            this.gbGame_Details.Controls.Add(this.Star5);
            this.gbGame_Details.Controls.Add(this.Star4);
            this.gbGame_Details.Controls.Add(this.Star3);
            this.gbGame_Details.Controls.Add(this.Star2);
            this.gbGame_Details.Controls.Add(this.Star1);
            this.gbGame_Details.Controls.Add(this.lblTimer);
            this.gbGame_Details.Controls.Add(this.label1);
            this.gbGame_Details.Controls.Add(this.label2);
            this.gbGame_Details.Controls.Add(this.cbSpeed);
            this.gbGame_Details.Controls.Add(this.cbTimer);
            this.gbGame_Details.Controls.Add(this.lblSpeed);
            this.gbGame_Details.Controls.Add(this.lable1);
            this.gbGame_Details.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.gbGame_Details.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbGame_Details.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.gbGame_Details.Location = new System.Drawing.Point(931, 164);
            this.gbGame_Details.Name = "gbGame_Details";
            this.gbGame_Details.Size = new System.Drawing.Size(392, 426);
            this.gbGame_Details.TabIndex = 1;
            this.gbGame_Details.TabStop = false;
            this.gbGame_Details.Text = "Game Details";
            // 
            // lblTimer
            // 
            this.lblTimer.AutoSize = true;
            this.lblTimer.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTimer.ForeColor = System.Drawing.Color.Black;
            this.lblTimer.Location = new System.Drawing.Point(201, 193);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(80, 28);
            this.lblTimer.TabIndex = 12;
            this.lblTimer.Text = "00:00";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.label1.Location = new System.Drawing.Point(126, 270);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(136, 28);
            this.label1.TabIndex = 6;
            this.label1.Text = "Your Score :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.Black;
            this.label2.Location = new System.Drawing.Point(111, 193);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(94, 28);
            this.label2.TabIndex = 4;
            this.label2.Text = "Timer :";
            // 
            // cbSpeed
            // 
            this.cbSpeed.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbSpeed.FormattingEnabled = true;
            this.cbSpeed.Items.AddRange(new object[] {
            "1x",
            "1.5x",
            "2x"});
            this.cbSpeed.Location = new System.Drawing.Point(243, 125);
            this.cbSpeed.Name = "cbSpeed";
            this.cbSpeed.Size = new System.Drawing.Size(107, 30);
            this.cbSpeed.TabIndex = 3;
            this.cbSpeed.Text = "1x";
            this.cbSpeed.SelectedIndexChanged += new System.EventHandler(this.cbSpeed_SelectedIndexChanged);
            // 
            // cbTimer
            // 
            this.cbTimer.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cbTimer.FormattingEnabled = true;
            this.cbTimer.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5"});
            this.cbTimer.Location = new System.Drawing.Point(36, 125);
            this.cbTimer.Name = "cbTimer";
            this.cbTimer.Size = new System.Drawing.Size(107, 30);
            this.cbTimer.TabIndex = 2;
            this.cbTimer.Text = "1";
            this.cbTimer.SelectedIndexChanged += new System.EventHandler(this.cbTimer_SelectedIndexChanged);
            // 
            // lblSpeed
            // 
            this.lblSpeed.AutoSize = true;
            this.lblSpeed.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSpeed.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.lblSpeed.Location = new System.Drawing.Point(256, 85);
            this.lblSpeed.Name = "lblSpeed";
            this.lblSpeed.Size = new System.Drawing.Size(75, 28);
            this.lblSpeed.TabIndex = 1;
            this.lblSpeed.Text = "Speed";
            // 
            // lable1
            // 
            this.lable1.AutoSize = true;
            this.lable1.Font = new System.Drawing.Font("Tahoma", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lable1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.lable1.Location = new System.Drawing.Point(54, 85);
            this.lable1.Name = "lable1";
            this.lable1.Size = new System.Drawing.Size(69, 28);
            this.lable1.TabIndex = 0;
            this.lable1.Text = "Timer";
            // 
            // Timer
            // 
            this.Timer.Enabled = true;
            this.Timer.Interval = 1000;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Khaki;
            this.btnStart.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStart.Location = new System.Drawing.Point(904, 646);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(170, 67);
            this.btnStart.TabIndex = 2;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click_1);
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.Color.OrangeRed;
            this.btnReset.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnReset.Location = new System.Drawing.Point(1183, 646);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(170, 67);
            this.btnReset.TabIndex = 3;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // pbQuestion_Mark10
            // 
            this.pbQuestion_Mark10.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark10.Location = new System.Drawing.Point(577, 534);
            this.pbQuestion_Mark10.Name = "pbQuestion_Mark10";
            this.pbQuestion_Mark10.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark10.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark10.TabIndex = 13;
            this.pbQuestion_Mark10.TabStop = false;
            this.pbQuestion_Mark10.Tag = "Question_Card";
            this.pbQuestion_Mark10.Click += new System.EventHandler(this.pbQuestion_Mark10_Click);
            // 
            // pbQuestion_Mark9
            // 
            this.pbQuestion_Mark9.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark9.Location = new System.Drawing.Point(353, 535);
            this.pbQuestion_Mark9.Name = "pbQuestion_Mark9";
            this.pbQuestion_Mark9.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark9.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark9.TabIndex = 12;
            this.pbQuestion_Mark9.TabStop = false;
            this.pbQuestion_Mark9.Tag = "Question_Card";
            this.pbQuestion_Mark9.Click += new System.EventHandler(this.pbQuestion_Mark9_Click);
            // 
            // pbQuestion_Mark8
            // 
            this.pbQuestion_Mark8.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark8.Location = new System.Drawing.Point(129, 534);
            this.pbQuestion_Mark8.Name = "pbQuestion_Mark8";
            this.pbQuestion_Mark8.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark8.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark8.TabIndex = 11;
            this.pbQuestion_Mark8.TabStop = false;
            this.pbQuestion_Mark8.Tag = "Question_Card";
            this.pbQuestion_Mark8.Click += new System.EventHandler(this.pbQuestion_Mark8_Click);
            // 
            // pbQuestion_Mark7
            // 
            this.pbQuestion_Mark7.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark7.Location = new System.Drawing.Point(681, 349);
            this.pbQuestion_Mark7.Name = "pbQuestion_Mark7";
            this.pbQuestion_Mark7.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark7.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark7.TabIndex = 10;
            this.pbQuestion_Mark7.TabStop = false;
            this.pbQuestion_Mark7.Tag = "Question_Card";
            this.pbQuestion_Mark7.Click += new System.EventHandler(this.pbQuestion_Mark7_Click);
            // 
            // pbQuestion_Mark6
            // 
            this.pbQuestion_Mark6.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark6.Location = new System.Drawing.Point(466, 349);
            this.pbQuestion_Mark6.Name = "pbQuestion_Mark6";
            this.pbQuestion_Mark6.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark6.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark6.TabIndex = 9;
            this.pbQuestion_Mark6.TabStop = false;
            this.pbQuestion_Mark6.Tag = "Question_Card";
            this.pbQuestion_Mark6.Click += new System.EventHandler(this.pbQuestion_Mark6_Click);
            // 
            // pbQuestion_Mark5
            // 
            this.pbQuestion_Mark5.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark5.Location = new System.Drawing.Point(249, 349);
            this.pbQuestion_Mark5.Name = "pbQuestion_Mark5";
            this.pbQuestion_Mark5.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark5.TabIndex = 8;
            this.pbQuestion_Mark5.TabStop = false;
            this.pbQuestion_Mark5.Tag = "Question_Card";
            this.pbQuestion_Mark5.Click += new System.EventHandler(this.pbQuestion_Mark5_Click);
            // 
            // pbQuestion_Mark4
            // 
            this.pbQuestion_Mark4.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark4.Location = new System.Drawing.Point(34, 349);
            this.pbQuestion_Mark4.Name = "pbQuestion_Mark4";
            this.pbQuestion_Mark4.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark4.TabIndex = 7;
            this.pbQuestion_Mark4.TabStop = false;
            this.pbQuestion_Mark4.Tag = "Question_Card";
            this.pbQuestion_Mark4.Click += new System.EventHandler(this.pbQuestion_Mark4_Click);
            // 
            // pbQuestion_Mark3
            // 
            this.pbQuestion_Mark3.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark3.Location = new System.Drawing.Point(577, 164);
            this.pbQuestion_Mark3.Name = "pbQuestion_Mark3";
            this.pbQuestion_Mark3.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark3.TabIndex = 6;
            this.pbQuestion_Mark3.TabStop = false;
            this.pbQuestion_Mark3.Tag = "Question_Card";
            this.pbQuestion_Mark3.Click += new System.EventHandler(this.pbQuestion_Mark3_Click);
            // 
            // pbQuestion_Mark2
            // 
            this.pbQuestion_Mark2.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark2.Location = new System.Drawing.Point(353, 164);
            this.pbQuestion_Mark2.Name = "pbQuestion_Mark2";
            this.pbQuestion_Mark2.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark2.TabIndex = 5;
            this.pbQuestion_Mark2.TabStop = false;
            this.pbQuestion_Mark2.Tag = "Question_Card";
            this.pbQuestion_Mark2.Click += new System.EventHandler(this.pbQuestion_Mark2_Click);
            // 
            // pbQuestion_Mark1
            // 
            this.pbQuestion_Mark1.Image = global::Memory_Game_Project.Properties.Resources.question_mark;
            this.pbQuestion_Mark1.Location = new System.Drawing.Point(129, 164);
            this.pbQuestion_Mark1.Name = "pbQuestion_Mark1";
            this.pbQuestion_Mark1.Size = new System.Drawing.Size(141, 136);
            this.pbQuestion_Mark1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbQuestion_Mark1.TabIndex = 4;
            this.pbQuestion_Mark1.TabStop = false;
            this.pbQuestion_Mark1.Tag = "Question_Card";
            this.pbQuestion_Mark1.Click += new System.EventHandler(this.pbQuestion_Mark1_Click);
            // 
            // Star1
            // 
            this.Star1.Image = global::Memory_Game_Project.Properties.Resources.Star_Empty;
            this.Star1.Location = new System.Drawing.Point(17, 340);
            this.Star1.Name = "Star1";
            this.Star1.Size = new System.Drawing.Size(69, 64);
            this.Star1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Star1.TabIndex = 14;
            this.Star1.TabStop = false;
            this.Star1.Tag = "Empty_Star";
            // 
            // Star2
            // 
            this.Star2.Image = global::Memory_Game_Project.Properties.Resources.Star_Empty;
            this.Star2.Location = new System.Drawing.Point(92, 340);
            this.Star2.Name = "Star2";
            this.Star2.Size = new System.Drawing.Size(69, 64);
            this.Star2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Star2.TabIndex = 15;
            this.Star2.TabStop = false;
            this.Star2.Tag = "Empty_Star";
            // 
            // Star3
            // 
            this.Star3.Image = global::Memory_Game_Project.Properties.Resources.Star_Empty;
            this.Star3.Location = new System.Drawing.Point(167, 340);
            this.Star3.Name = "Star3";
            this.Star3.Size = new System.Drawing.Size(69, 64);
            this.Star3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Star3.TabIndex = 16;
            this.Star3.TabStop = false;
            this.Star3.Tag = "Empty_Star";
            // 
            // Star4
            // 
            this.Star4.Image = global::Memory_Game_Project.Properties.Resources.Star_Empty;
            this.Star4.Location = new System.Drawing.Point(242, 340);
            this.Star4.Name = "Star4";
            this.Star4.Size = new System.Drawing.Size(69, 64);
            this.Star4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Star4.TabIndex = 17;
            this.Star4.TabStop = false;
            this.Star4.Tag = "Empty_Star";
            // 
            // Star5
            // 
            this.Star5.Image = global::Memory_Game_Project.Properties.Resources.Star_Empty;
            this.Star5.Location = new System.Drawing.Point(317, 340);
            this.Star5.Name = "Star5";
            this.Star5.Size = new System.Drawing.Size(69, 64);
            this.Star5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Star5.TabIndex = 18;
            this.Star5.TabStop = false;
            this.Star5.Tag = "Empty_Star";
            // 
            // WrongMatchTimer
            // 
            this.WrongMatchTimer.Interval = 1000;
            this.WrongMatchTimer.Tick += new System.EventHandler(this.WrongMatchTimer_Tick);
            // 
            // frmMemory_Game
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.MediumTurquoise;
            this.ClientSize = new System.Drawing.Size(1382, 775);
            this.Controls.Add(this.pbQuestion_Mark10);
            this.Controls.Add(this.pbQuestion_Mark9);
            this.Controls.Add(this.pbQuestion_Mark8);
            this.Controls.Add(this.pbQuestion_Mark7);
            this.Controls.Add(this.pbQuestion_Mark6);
            this.Controls.Add(this.pbQuestion_Mark5);
            this.Controls.Add(this.pbQuestion_Mark4);
            this.Controls.Add(this.pbQuestion_Mark3);
            this.Controls.Add(this.pbQuestion_Mark2);
            this.Controls.Add(this.pbQuestion_Mark1);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.gbGame_Details);
            this.Controls.Add(this.lblMemory_Game);
            this.Name = "frmMemory_Game";
            this.Text = "Memory Game";
            this.Load += new System.EventHandler(this.frmMemory_Game_Load);
            this.gbGame_Details.ResumeLayout(false);
            this.gbGame_Details.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbQuestion_Mark1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.Star5)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblMemory_Game;
        private System.Windows.Forms.GroupBox gbGame_Details;
        private System.Windows.Forms.Label lable1;
        private System.Windows.Forms.ComboBox cbTimer;
        private System.Windows.Forms.Label lblSpeed;
        private System.Windows.Forms.ComboBox cbSpeed;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Timer Timer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.PictureBox pbQuestion_Mark1;
        private System.Windows.Forms.PictureBox pbQuestion_Mark2;
        private System.Windows.Forms.PictureBox pbQuestion_Mark3;
        private System.Windows.Forms.PictureBox pbQuestion_Mark4;
        private System.Windows.Forms.PictureBox pbQuestion_Mark5;
        private System.Windows.Forms.PictureBox pbQuestion_Mark6;
        private System.Windows.Forms.PictureBox pbQuestion_Mark7;
        private System.Windows.Forms.PictureBox pbQuestion_Mark8;
        private System.Windows.Forms.PictureBox pbQuestion_Mark9;
        private System.Windows.Forms.PictureBox pbQuestion_Mark10;
        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.PictureBox Star5;
        private System.Windows.Forms.PictureBox Star4;
        private System.Windows.Forms.PictureBox Star3;
        private System.Windows.Forms.PictureBox Star2;
        private System.Windows.Forms.PictureBox Star1;
        private System.Windows.Forms.Timer WrongMatchTimer;
    }
}

