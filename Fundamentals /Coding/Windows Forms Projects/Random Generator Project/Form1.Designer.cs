namespace Random_Generator_Project
{
    partial class frmRandom_Generator
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
            this.lblResult = new System.Windows.Forms.Label();
            this.btnReset = new System.Windows.Forms.Button();
            this.btnGenerate = new System.Windows.Forms.Button();
            this.gbDetails = new System.Windows.Forms.GroupBox();
            this.rbMix = new System.Windows.Forms.RadioButton();
            this.rbSpecial_Character = new System.Windows.Forms.RadioButton();
            this.rbNumbers = new System.Windows.Forms.RadioButton();
            this.rbLetters = new System.Windows.Forms.RadioButton();
            this.cmsLettersOptions = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.Capital_Letter = new System.Windows.Forms.ToolStripMenuItem();
            this.Small_Letter = new System.Windows.Forms.ToolStripMenuItem();
            this.numericUpDown = new System.Windows.Forms.NumericUpDown();
            this.txtbNumber_of_Digits = new System.Windows.Forms.TextBox();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.gbDetails.SuspendLayout();
            this.cmsLettersOptions.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown)).BeginInit();
            this.SuspendLayout();
            // 
            // lblResult
            // 
            this.lblResult.AutoSize = true;
            this.lblResult.Font = new System.Drawing.Font("Tahoma", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblResult.ForeColor = System.Drawing.Color.GreenYellow;
            this.lblResult.Location = new System.Drawing.Point(382, 64);
            this.lblResult.Name = "lblResult";
            this.lblResult.Size = new System.Drawing.Size(97, 36);
            this.lblResult.TabIndex = 0;
            this.lblResult.Text = "Result";
            // 
            // btnReset
            // 
            this.btnReset.BackColor = System.Drawing.Color.OrangeRed;
            this.btnReset.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnReset.Location = new System.Drawing.Point(525, 437);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(116, 44);
            this.btnReset.TabIndex = 7;
            this.btnReset.Text = "Reset";
            this.btnReset.UseVisualStyleBackColor = false;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // btnGenerate
            // 
            this.btnGenerate.BackColor = System.Drawing.Color.Gold;
            this.btnGenerate.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnGenerate.Location = new System.Drawing.Point(242, 437);
            this.btnGenerate.Name = "btnGenerate";
            this.btnGenerate.Size = new System.Drawing.Size(118, 44);
            this.btnGenerate.TabIndex = 6;
            this.btnGenerate.Text = "Generate";
            this.btnGenerate.UseVisualStyleBackColor = false;
            this.btnGenerate.Click += new System.EventHandler(this.btnGenerate_Click);
            // 
            // gbDetails
            // 
            this.gbDetails.Controls.Add(this.rbMix);
            this.gbDetails.Controls.Add(this.rbSpecial_Character);
            this.gbDetails.Controls.Add(this.rbNumbers);
            this.gbDetails.Controls.Add(this.rbLetters);
            this.gbDetails.Controls.Add(this.numericUpDown);
            this.gbDetails.Controls.Add(this.txtbNumber_of_Digits);
            this.gbDetails.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gbDetails.Location = new System.Drawing.Point(197, 196);
            this.gbDetails.Name = "gbDetails";
            this.gbDetails.Size = new System.Drawing.Size(489, 220);
            this.gbDetails.TabIndex = 3;
            this.gbDetails.TabStop = false;
            this.gbDetails.Text = "Details";
            // 
            // rbMix
            // 
            this.rbMix.AutoSize = true;
            this.rbMix.ForeColor = System.Drawing.Color.Khaki;
            this.rbMix.Location = new System.Drawing.Point(263, 167);
            this.rbMix.Name = "rbMix";
            this.rbMix.Size = new System.Drawing.Size(61, 25);
            this.rbMix.TabIndex = 5;
            this.rbMix.TabStop = true;
            this.rbMix.Text = "Mix";
            this.rbMix.UseVisualStyleBackColor = true;
            // 
            // rbSpecial_Character
            // 
            this.rbSpecial_Character.AutoSize = true;
            this.rbSpecial_Character.ForeColor = System.Drawing.Color.Khaki;
            this.rbSpecial_Character.Location = new System.Drawing.Point(36, 167);
            this.rbSpecial_Character.Name = "rbSpecial_Character";
            this.rbSpecial_Character.Size = new System.Drawing.Size(179, 25);
            this.rbSpecial_Character.TabIndex = 4;
            this.rbSpecial_Character.TabStop = true;
            this.rbSpecial_Character.Text = "Special Character";
            this.rbSpecial_Character.UseVisualStyleBackColor = true;
            // 
            // rbNumbers
            // 
            this.rbNumbers.AutoSize = true;
            this.rbNumbers.ForeColor = System.Drawing.Color.Khaki;
            this.rbNumbers.Location = new System.Drawing.Point(263, 105);
            this.rbNumbers.Name = "rbNumbers";
            this.rbNumbers.Size = new System.Drawing.Size(108, 25);
            this.rbNumbers.TabIndex = 3;
            this.rbNumbers.TabStop = true;
            this.rbNumbers.Text = "Numbers";
            this.rbNumbers.UseVisualStyleBackColor = true;
            // 
            // rbLetters
            // 
            this.rbLetters.AutoSize = true;
            this.rbLetters.ContextMenuStrip = this.cmsLettersOptions;
            this.rbLetters.ForeColor = System.Drawing.Color.Khaki;
            this.rbLetters.Location = new System.Drawing.Point(36, 105);
            this.rbLetters.Name = "rbLetters";
            this.rbLetters.Size = new System.Drawing.Size(91, 25);
            this.rbLetters.TabIndex = 2;
            this.rbLetters.TabStop = true;
            this.rbLetters.Text = "Letters";
            this.rbLetters.UseVisualStyleBackColor = true;
            // 
            // cmsLettersOptions
            // 
            this.cmsLettersOptions.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.cmsLettersOptions.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.Capital_Letter,
            this.Small_Letter});
            this.cmsLettersOptions.Name = "cmsLettersOptions";
            this.cmsLettersOptions.Size = new System.Drawing.Size(211, 80);
            // 
            // Capital_Letter
            // 
            this.Capital_Letter.Name = "Capital_Letter";
            this.Capital_Letter.Size = new System.Drawing.Size(210, 24);
            this.Capital_Letter.Text = "Capital Letter";
            this.Capital_Letter.Click += new System.EventHandler(this.Capital_Letter_Click);
            // 
            // Small_Letter
            // 
            this.Small_Letter.Name = "Small_Letter";
            this.Small_Letter.Size = new System.Drawing.Size(210, 24);
            this.Small_Letter.Text = "Small Letter";
            this.Small_Letter.Click += new System.EventHandler(this.Small_Letter_Click);
            // 
            // numericUpDown
            // 
            this.numericUpDown.BackColor = System.Drawing.Color.Teal;
            this.numericUpDown.Location = new System.Drawing.Point(263, 40);
            this.numericUpDown.Maximum = new decimal(new int[] {
            19,
            0,
            0,
            0});
            this.numericUpDown.Name = "numericUpDown";
            this.numericUpDown.Size = new System.Drawing.Size(120, 28);
            this.numericUpDown.TabIndex = 1;
            // 
            // txtbNumber_of_Digits
            // 
            this.txtbNumber_of_Digits.BackColor = System.Drawing.Color.Teal;
            this.txtbNumber_of_Digits.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtbNumber_of_Digits.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtbNumber_of_Digits.ForeColor = System.Drawing.Color.Khaki;
            this.txtbNumber_of_Digits.Location = new System.Drawing.Point(36, 39);
            this.txtbNumber_of_Digits.Name = "txtbNumber_of_Digits";
            this.txtbNumber_of_Digits.Size = new System.Drawing.Size(177, 25);
            this.txtbNumber_of_Digits.TabIndex = 0;
            this.txtbNumber_of_Digits.Text = "Number of Digits";
            // 
            // txtResult
            // 
            this.txtResult.BackColor = System.Drawing.Color.White;
            this.txtResult.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtResult.Location = new System.Drawing.Point(256, 147);
            this.txtResult.Name = "txtResult";
            this.txtResult.Size = new System.Drawing.Size(357, 17);
            this.txtResult.TabIndex = 0;
            // 
            // frmRandom_Generator
            // 
            this.AcceptButton = this.btnGenerate;
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Teal;
            this.ClientSize = new System.Drawing.Size(881, 558);
            this.Controls.Add(this.txtResult);
            this.Controls.Add(this.gbDetails);
            this.Controls.Add(this.btnGenerate);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.lblResult);
            this.Name = "frmRandom_Generator";
            this.Text = "Random Generator";
            this.Load += new System.EventHandler(this.frmRandom_Generator_Load);
            this.gbDetails.ResumeLayout(false);
            this.gbDetails.PerformLayout();
            this.cmsLettersOptions.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblResult;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.Button btnGenerate;
        private System.Windows.Forms.GroupBox gbDetails;
        private System.Windows.Forms.TextBox txtbNumber_of_Digits;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.NumericUpDown numericUpDown;
        private System.Windows.Forms.RadioButton rbLetters;
        private System.Windows.Forms.RadioButton rbSpecial_Character;
        private System.Windows.Forms.RadioButton rbNumbers;
        private System.Windows.Forms.RadioButton rbMix;
        private System.Windows.Forms.ContextMenuStrip cmsLettersOptions;
        private System.Windows.Forms.ToolStripMenuItem Capital_Letter;
        private System.Windows.Forms.ToolStripMenuItem Small_Letter;
    }
}

