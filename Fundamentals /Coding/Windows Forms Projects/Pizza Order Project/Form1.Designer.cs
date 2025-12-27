namespace Pizza_Order_Project
{
    partial class Main_Form
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
            this.label1 = new System.Windows.Forms.Label();
            this.gbSize = new System.Windows.Forms.GroupBox();
            this.rbLarg = new System.Windows.Forms.RadioButton();
            this.rbMeduim = new System.Windows.Forms.RadioButton();
            this.rbSmall = new System.Windows.Forms.RadioButton();
            this.gbToppings = new System.Windows.Forms.GroupBox();
            this.ckbGreen_Peppers = new System.Windows.Forms.CheckBox();
            this.ckbOlives = new System.Windows.Forms.CheckBox();
            this.ckbOnion = new System.Windows.Forms.CheckBox();
            this.ckbTomatoes = new System.Windows.Forms.CheckBox();
            this.ckbMushrooms = new System.Windows.Forms.CheckBox();
            this.ckbExtra_Chees = new System.Windows.Forms.CheckBox();
            this.gbCrust_Type = new System.Windows.Forms.GroupBox();
            this.rbThick_Crust = new System.Windows.Forms.RadioButton();
            this.rbThin_Crust = new System.Windows.Forms.RadioButton();
            this.gbWhere_To_Eat = new System.Windows.Forms.GroupBox();
            this.rbTake_Out = new System.Windows.Forms.RadioButton();
            this.rbEat_In = new System.Windows.Forms.RadioButton();
            this.btnOrder_Pizza = new System.Windows.Forms.Button();
            this.btnReset_Form = new System.Windows.Forms.Button();
            this.tetbSummary = new System.Windows.Forms.TextBox();
            this.txtbSize1 = new System.Windows.Forms.TextBox();
            this.lblSize = new System.Windows.Forms.TextBox();
            this.txtbTopping = new System.Windows.Forms.TextBox();
            this.lblToppings = new System.Windows.Forms.TextBox();
            this.txtbCrustType = new System.Windows.Forms.TextBox();
            this.lblCrustType = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.lblWhereToEat = new System.Windows.Forms.TextBox();
            this.txtbTotalPrice = new System.Windows.Forms.TextBox();
            this.lblTotalPrice = new System.Windows.Forms.TextBox();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.txtNumber_Of_Pizza = new System.Windows.Forms.TextBox();
            this.gbSize.SuspendLayout();
            this.gbToppings.SuspendLayout();
            this.gbCrust_Type.SuspendLayout();
            this.gbWhere_To_Eat.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Insaniburger with Cheese", 36F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(268, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(521, 66);
            this.label1.TabIndex = 0;
            this.label1.Text = "MAKE YOUR PIZZA";
            // 
            // gbSize
            // 
            this.gbSize.Controls.Add(this.rbLarg);
            this.gbSize.Controls.Add(this.rbMeduim);
            this.gbSize.Controls.Add(this.rbSmall);
            this.gbSize.Location = new System.Drawing.Point(45, 87);
            this.gbSize.Name = "gbSize";
            this.gbSize.Size = new System.Drawing.Size(208, 157);
            this.gbSize.TabIndex = 4;
            this.gbSize.TabStop = false;
            this.gbSize.Text = "Size";
            // 
            // rbLarg
            // 
            this.rbLarg.AutoSize = true;
            this.rbLarg.Location = new System.Drawing.Point(35, 122);
            this.rbLarg.Name = "rbLarg";
            this.rbLarg.Size = new System.Drawing.Size(56, 21);
            this.rbLarg.TabIndex = 2;
            this.rbLarg.Tag = "40";
            this.rbLarg.Text = "Larg";
            this.rbLarg.UseVisualStyleBackColor = true;
            this.rbLarg.CheckedChanged += new System.EventHandler(this.rbLarg_CheckedChanged);
            // 
            // rbMeduim
            // 
            this.rbMeduim.AutoSize = true;
            this.rbMeduim.Location = new System.Drawing.Point(35, 76);
            this.rbMeduim.Name = "rbMeduim";
            this.rbMeduim.Size = new System.Drawing.Size(76, 21);
            this.rbMeduim.TabIndex = 1;
            this.rbMeduim.Tag = "30";
            this.rbMeduim.Text = "Meduim";
            this.rbMeduim.UseVisualStyleBackColor = true;
            this.rbMeduim.CheckedChanged += new System.EventHandler(this.rbMeduim_CheckedChanged);
            // 
            // rbSmall
            // 
            this.rbSmall.AutoSize = true;
            this.rbSmall.Checked = true;
            this.rbSmall.Location = new System.Drawing.Point(35, 30);
            this.rbSmall.Name = "rbSmall";
            this.rbSmall.Size = new System.Drawing.Size(60, 21);
            this.rbSmall.TabIndex = 0;
            this.rbSmall.TabStop = true;
            this.rbSmall.Tag = "20";
            this.rbSmall.Text = "Small";
            this.rbSmall.UseVisualStyleBackColor = true;
            this.rbSmall.CheckedChanged += new System.EventHandler(this.rbSmall_CheckedChanged);
            // 
            // gbToppings
            // 
            this.gbToppings.Controls.Add(this.ckbGreen_Peppers);
            this.gbToppings.Controls.Add(this.ckbOlives);
            this.gbToppings.Controls.Add(this.ckbOnion);
            this.gbToppings.Controls.Add(this.ckbTomatoes);
            this.gbToppings.Controls.Add(this.ckbMushrooms);
            this.gbToppings.Controls.Add(this.ckbExtra_Chees);
            this.gbToppings.Location = new System.Drawing.Point(313, 87);
            this.gbToppings.Name = "gbToppings";
            this.gbToppings.Size = new System.Drawing.Size(296, 157);
            this.gbToppings.TabIndex = 5;
            this.gbToppings.TabStop = false;
            this.gbToppings.Text = "Toppings";
            // 
            // ckbGreen_Peppers
            // 
            this.ckbGreen_Peppers.AutoSize = true;
            this.ckbGreen_Peppers.Location = new System.Drawing.Point(157, 122);
            this.ckbGreen_Peppers.Name = "ckbGreen_Peppers";
            this.ckbGreen_Peppers.Size = new System.Drawing.Size(119, 21);
            this.ckbGreen_Peppers.TabIndex = 8;
            this.ckbGreen_Peppers.Tag = "5";
            this.ckbGreen_Peppers.Text = "Green Peppers";
            this.ckbGreen_Peppers.UseVisualStyleBackColor = true;
            this.ckbGreen_Peppers.CheckedChanged += new System.EventHandler(this.ckbGreen_Peppers_CheckedChanged);
            // 
            // ckbOlives
            // 
            this.ckbOlives.AutoSize = true;
            this.ckbOlives.Location = new System.Drawing.Point(157, 76);
            this.ckbOlives.Name = "ckbOlives";
            this.ckbOlives.Size = new System.Drawing.Size(65, 21);
            this.ckbOlives.TabIndex = 7;
            this.ckbOlives.Tag = "5";
            this.ckbOlives.Text = "Olives";
            this.ckbOlives.UseVisualStyleBackColor = true;
            this.ckbOlives.CheckedChanged += new System.EventHandler(this.ckbOlives_CheckedChanged);
            // 
            // ckbOnion
            // 
            this.ckbOnion.AutoSize = true;
            this.ckbOnion.Location = new System.Drawing.Point(157, 30);
            this.ckbOnion.Name = "ckbOnion";
            this.ckbOnion.Size = new System.Drawing.Size(66, 21);
            this.ckbOnion.TabIndex = 6;
            this.ckbOnion.Tag = "5";
            this.ckbOnion.Text = "Onion";
            this.ckbOnion.UseVisualStyleBackColor = true;
            this.ckbOnion.CheckedChanged += new System.EventHandler(this.ckbOnion_CheckedChanged);
            // 
            // ckbTomatoes
            // 
            this.ckbTomatoes.AutoSize = true;
            this.ckbTomatoes.Location = new System.Drawing.Point(6, 122);
            this.ckbTomatoes.Name = "ckbTomatoes";
            this.ckbTomatoes.Size = new System.Drawing.Size(91, 21);
            this.ckbTomatoes.TabIndex = 5;
            this.ckbTomatoes.Tag = "5";
            this.ckbTomatoes.Text = "Tomatoes";
            this.ckbTomatoes.UseVisualStyleBackColor = true;
            this.ckbTomatoes.CheckedChanged += new System.EventHandler(this.ckbTomatoes_CheckedChanged);
            // 
            // ckbMushrooms
            // 
            this.ckbMushrooms.AutoSize = true;
            this.ckbMushrooms.Location = new System.Drawing.Point(6, 76);
            this.ckbMushrooms.Name = "ckbMushrooms";
            this.ckbMushrooms.Size = new System.Drawing.Size(101, 21);
            this.ckbMushrooms.TabIndex = 4;
            this.ckbMushrooms.Tag = "5";
            this.ckbMushrooms.Text = "Mushrooms";
            this.ckbMushrooms.UseVisualStyleBackColor = true;
            this.ckbMushrooms.CheckedChanged += new System.EventHandler(this.ckbMushrooms_CheckedChanged);
            // 
            // ckbExtra_Chees
            // 
            this.ckbExtra_Chees.AutoSize = true;
            this.ckbExtra_Chees.Location = new System.Drawing.Point(6, 30);
            this.ckbExtra_Chees.Name = "ckbExtra_Chees";
            this.ckbExtra_Chees.Size = new System.Drawing.Size(104, 21);
            this.ckbExtra_Chees.TabIndex = 3;
            this.ckbExtra_Chees.Tag = "5";
            this.ckbExtra_Chees.Text = "Extra Chees";
            this.ckbExtra_Chees.UseVisualStyleBackColor = true;
            this.ckbExtra_Chees.CheckedChanged += new System.EventHandler(this.chkExtra_Chees_CheckedChanged);
            // 
            // gbCrust_Type
            // 
            this.gbCrust_Type.Controls.Add(this.rbThick_Crust);
            this.gbCrust_Type.Controls.Add(this.rbThin_Crust);
            this.gbCrust_Type.Location = new System.Drawing.Point(45, 290);
            this.gbCrust_Type.Name = "gbCrust_Type";
            this.gbCrust_Type.Size = new System.Drawing.Size(208, 125);
            this.gbCrust_Type.TabIndex = 6;
            this.gbCrust_Type.TabStop = false;
            this.gbCrust_Type.Tag = "0";
            this.gbCrust_Type.Text = "Crust Type";
            // 
            // rbThick_Crust
            // 
            this.rbThick_Crust.AutoSize = true;
            this.rbThick_Crust.Location = new System.Drawing.Point(35, 81);
            this.rbThick_Crust.Name = "rbThick_Crust";
            this.rbThick_Crust.Size = new System.Drawing.Size(98, 21);
            this.rbThick_Crust.TabIndex = 10;
            this.rbThick_Crust.TabStop = true;
            this.rbThick_Crust.Tag = "10";
            this.rbThick_Crust.Text = "Thick Crust";
            this.rbThick_Crust.UseVisualStyleBackColor = true;
            this.rbThick_Crust.CheckedChanged += new System.EventHandler(this.rbThink_Crust_CheckedChanged);
            // 
            // rbThin_Crust
            // 
            this.rbThin_Crust.AutoSize = true;
            this.rbThin_Crust.Checked = true;
            this.rbThin_Crust.Location = new System.Drawing.Point(35, 40);
            this.rbThin_Crust.Name = "rbThin_Crust";
            this.rbThin_Crust.Size = new System.Drawing.Size(92, 21);
            this.rbThin_Crust.TabIndex = 9;
            this.rbThin_Crust.TabStop = true;
            this.rbThin_Crust.Tag = "0";
            this.rbThin_Crust.Text = "Thin Crust";
            this.rbThin_Crust.UseVisualStyleBackColor = true;
            this.rbThin_Crust.CheckedChanged += new System.EventHandler(this.rbThin_Crust_CheckedChanged);
            // 
            // gbWhere_To_Eat
            // 
            this.gbWhere_To_Eat.Controls.Add(this.rbTake_Out);
            this.gbWhere_To_Eat.Controls.Add(this.rbEat_In);
            this.gbWhere_To_Eat.Location = new System.Drawing.Point(335, 290);
            this.gbWhere_To_Eat.Name = "gbWhere_To_Eat";
            this.gbWhere_To_Eat.Size = new System.Drawing.Size(236, 80);
            this.gbWhere_To_Eat.TabIndex = 9;
            this.gbWhere_To_Eat.TabStop = false;
            this.gbWhere_To_Eat.Text = "Where To Eat";
            // 
            // rbTake_Out
            // 
            this.rbTake_Out.AutoSize = true;
            this.rbTake_Out.Location = new System.Drawing.Point(115, 40);
            this.rbTake_Out.Name = "rbTake_Out";
            this.rbTake_Out.Size = new System.Drawing.Size(85, 21);
            this.rbTake_Out.TabIndex = 12;
            this.rbTake_Out.TabStop = true;
            this.rbTake_Out.Text = "Take Out";
            this.rbTake_Out.UseVisualStyleBackColor = true;
            this.rbTake_Out.CheckedChanged += new System.EventHandler(this.rbTake_Out_CheckedChanged);
            // 
            // rbEat_In
            // 
            this.rbEat_In.AutoSize = true;
            this.rbEat_In.Checked = true;
            this.rbEat_In.Location = new System.Drawing.Point(17, 40);
            this.rbEat_In.Name = "rbEat_In";
            this.rbEat_In.Size = new System.Drawing.Size(65, 21);
            this.rbEat_In.TabIndex = 11;
            this.rbEat_In.TabStop = true;
            this.rbEat_In.Text = "Eat In";
            this.rbEat_In.UseVisualStyleBackColor = true;
            this.rbEat_In.CheckedChanged += new System.EventHandler(this.rbEat_In_CheckedChanged);
            // 
            // btnOrder_Pizza
            // 
            this.btnOrder_Pizza.Location = new System.Drawing.Point(335, 419);
            this.btnOrder_Pizza.Name = "btnOrder_Pizza";
            this.btnOrder_Pizza.Size = new System.Drawing.Size(110, 51);
            this.btnOrder_Pizza.TabIndex = 13;
            this.btnOrder_Pizza.Text = "Order Pizza";
            this.btnOrder_Pizza.UseVisualStyleBackColor = true;
            this.btnOrder_Pizza.Click += new System.EventHandler(this.btnOrder_Pizza_Click);
            // 
            // btnReset_Form
            // 
            this.btnReset_Form.Location = new System.Drawing.Point(479, 419);
            this.btnReset_Form.Name = "btnReset_Form";
            this.btnReset_Form.Size = new System.Drawing.Size(110, 51);
            this.btnReset_Form.TabIndex = 14;
            this.btnReset_Form.Text = "Reset From";
            this.btnReset_Form.UseVisualStyleBackColor = true;
            this.btnReset_Form.Click += new System.EventHandler(this.btnReset_Form_Click);
            // 
            // tetbSummary
            // 
            this.tetbSummary.BackColor = System.Drawing.Color.White;
            this.tetbSummary.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.tetbSummary.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tetbSummary.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.tetbSummary.Location = new System.Drawing.Point(676, 105);
            this.tetbSummary.Name = "tetbSummary";
            this.tetbSummary.Size = new System.Drawing.Size(130, 21);
            this.tetbSummary.TabIndex = 15;
            this.tetbSummary.Text = "Order Summary";
            // 
            // txtbSize1
            // 
            this.txtbSize1.BackColor = System.Drawing.Color.White;
            this.txtbSize1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtbSize1.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtbSize1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.txtbSize1.Location = new System.Drawing.Point(699, 141);
            this.txtbSize1.Name = "txtbSize1";
            this.txtbSize1.Size = new System.Drawing.Size(41, 22);
            this.txtbSize1.TabIndex = 16;
            this.txtbSize1.Text = "Size:";
            // 
            // lblSize
            // 
            this.lblSize.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lblSize.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblSize.Location = new System.Drawing.Point(746, 141);
            this.lblSize.Name = "lblSize";
            this.lblSize.Size = new System.Drawing.Size(100, 21);
            this.lblSize.TabIndex = 17;
            this.lblSize.Text = "Small";
            // 
            // txtbTopping
            // 
            this.txtbTopping.BackColor = System.Drawing.Color.White;
            this.txtbTopping.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtbTopping.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtbTopping.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.txtbTopping.Location = new System.Drawing.Point(699, 183);
            this.txtbTopping.Name = "txtbTopping";
            this.txtbTopping.Size = new System.Drawing.Size(90, 22);
            this.txtbTopping.TabIndex = 18;
            this.txtbTopping.Text = "Toppings:";
            // 
            // lblToppings
            // 
            this.lblToppings.BackColor = System.Drawing.Color.White;
            this.lblToppings.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lblToppings.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblToppings.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.lblToppings.Location = new System.Drawing.Point(746, 211);
            this.lblToppings.Multiline = true;
            this.lblToppings.Name = "lblToppings";
            this.lblToppings.Size = new System.Drawing.Size(285, 76);
            this.lblToppings.TabIndex = 19;
            this.lblToppings.Text = "No Topping";
            // 
            // txtbCrustType
            // 
            this.txtbCrustType.BackColor = System.Drawing.Color.White;
            this.txtbCrustType.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtbCrustType.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtbCrustType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.txtbCrustType.Location = new System.Drawing.Point(699, 293);
            this.txtbCrustType.Name = "txtbCrustType";
            this.txtbCrustType.Size = new System.Drawing.Size(107, 22);
            this.txtbCrustType.TabIndex = 20;
            this.txtbCrustType.Text = "Crust Type:";
            // 
            // lblCrustType
            // 
            this.lblCrustType.BackColor = System.Drawing.Color.White;
            this.lblCrustType.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lblCrustType.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblCrustType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.lblCrustType.Location = new System.Drawing.Point(812, 293);
            this.lblCrustType.Multiline = true;
            this.lblCrustType.Name = "lblCrustType";
            this.lblCrustType.Size = new System.Drawing.Size(103, 22);
            this.lblCrustType.TabIndex = 21;
            this.lblCrustType.Text = "Thin Crust";
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.White;
            this.textBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.textBox1.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.textBox1.Location = new System.Drawing.Point(699, 330);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(132, 22);
            this.textBox1.TabIndex = 22;
            this.textBox1.Text = "Where To Eat:";
            // 
            // lblWhereToEat
            // 
            this.lblWhereToEat.BackColor = System.Drawing.Color.White;
            this.lblWhereToEat.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lblWhereToEat.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWhereToEat.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.lblWhereToEat.Location = new System.Drawing.Point(826, 358);
            this.lblWhereToEat.Multiline = true;
            this.lblWhereToEat.Name = "lblWhereToEat";
            this.lblWhereToEat.Size = new System.Drawing.Size(89, 34);
            this.lblWhereToEat.TabIndex = 23;
            this.lblWhereToEat.Text = "Eat In";
            // 
            // txtbTotalPrice
            // 
            this.txtbTotalPrice.BackColor = System.Drawing.Color.White;
            this.txtbTotalPrice.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtbTotalPrice.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtbTotalPrice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.txtbTotalPrice.Location = new System.Drawing.Point(699, 398);
            this.txtbTotalPrice.Name = "txtbTotalPrice";
            this.txtbTotalPrice.Size = new System.Drawing.Size(107, 22);
            this.txtbTotalPrice.TabIndex = 24;
            this.txtbTotalPrice.Text = "Total Price:";
            // 
            // lblTotalPrice
            // 
            this.lblTotalPrice.BackColor = System.Drawing.Color.White;
            this.lblTotalPrice.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.lblTotalPrice.Font = new System.Drawing.Font("Tahoma", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTotalPrice.ForeColor = System.Drawing.Color.Green;
            this.lblTotalPrice.Location = new System.Drawing.Point(812, 410);
            this.lblTotalPrice.Multiline = true;
            this.lblTotalPrice.Name = "lblTotalPrice";
            this.lblTotalPrice.Size = new System.Drawing.Size(139, 60);
            this.lblTotalPrice.TabIndex = 25;
            this.lblTotalPrice.Text = "$20";
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.Location = new System.Drawing.Point(852, 138);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(120, 24);
            this.numericUpDown1.TabIndex = 26;
            this.numericUpDown1.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 10.8F, System.Drawing.FontStyle.Bold);
            this.label2.Location = new System.Drawing.Point(822, 104);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(172, 22);
            this.label2.TabIndex = 27;
            this.label2.Text = "Number of pizzas:";
            // 
            // txtNumber_Of_Pizza
            // 
            this.txtNumber_Of_Pizza.BackColor = System.Drawing.Color.White;
            this.txtNumber_Of_Pizza.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtNumber_Of_Pizza.Font = new System.Drawing.Font("Tahoma", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.txtNumber_Of_Pizza.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(64)))), ((int)(((byte)(64)))));
            this.txtNumber_Of_Pizza.Location = new System.Drawing.Point(1000, 104);
            this.txtNumber_Of_Pizza.Multiline = true;
            this.txtNumber_Of_Pizza.Name = "txtNumber_Of_Pizza";
            this.txtNumber_Of_Pizza.Size = new System.Drawing.Size(68, 22);
            this.txtNumber_Of_Pizza.TabIndex = 28;
            this.txtNumber_Of_Pizza.Text = "1";
            // 
            // Main_Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1067, 508);
            this.Controls.Add(this.txtNumber_Of_Pizza);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.numericUpDown1);
            this.Controls.Add(this.lblTotalPrice);
            this.Controls.Add(this.txtbTotalPrice);
            this.Controls.Add(this.lblWhereToEat);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.lblCrustType);
            this.Controls.Add(this.txtbCrustType);
            this.Controls.Add(this.lblToppings);
            this.Controls.Add(this.txtbTopping);
            this.Controls.Add(this.lblSize);
            this.Controls.Add(this.txtbSize1);
            this.Controls.Add(this.tetbSummary);
            this.Controls.Add(this.btnReset_Form);
            this.Controls.Add(this.btnOrder_Pizza);
            this.Controls.Add(this.gbWhere_To_Eat);
            this.Controls.Add(this.gbCrust_Type);
            this.Controls.Add(this.gbToppings);
            this.Controls.Add(this.gbSize);
            this.Controls.Add(this.label1);
            this.Name = "Main_Form";
            this.Text = "Pizza Order";
            this.Load += new System.EventHandler(this.Main_Form_Load);
            this.gbSize.ResumeLayout(false);
            this.gbSize.PerformLayout();
            this.gbToppings.ResumeLayout(false);
            this.gbToppings.PerformLayout();
            this.gbCrust_Type.ResumeLayout(false);
            this.gbCrust_Type.PerformLayout();
            this.gbWhere_To_Eat.ResumeLayout(false);
            this.gbWhere_To_Eat.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gbSize;
        private System.Windows.Forms.RadioButton rbLarg;
        private System.Windows.Forms.RadioButton rbMeduim;
        private System.Windows.Forms.RadioButton rbSmall;
        private System.Windows.Forms.GroupBox gbToppings;
        private System.Windows.Forms.CheckBox ckbGreen_Peppers;
        private System.Windows.Forms.CheckBox ckbOlives;
        private System.Windows.Forms.CheckBox ckbOnion;
        private System.Windows.Forms.CheckBox ckbTomatoes;
        private System.Windows.Forms.CheckBox ckbMushrooms;
        private System.Windows.Forms.CheckBox ckbExtra_Chees;
        private System.Windows.Forms.GroupBox gbCrust_Type;
        private System.Windows.Forms.GroupBox gbWhere_To_Eat;
        private System.Windows.Forms.RadioButton rbTake_Out;
        private System.Windows.Forms.RadioButton rbEat_In;
        private System.Windows.Forms.Button btnOrder_Pizza;
        private System.Windows.Forms.Button btnReset_Form;
        private System.Windows.Forms.TextBox tetbSummary;
        private System.Windows.Forms.TextBox txtbSize1;
        private System.Windows.Forms.TextBox lblSize;
        private System.Windows.Forms.TextBox txtbTopping;
        private System.Windows.Forms.TextBox lblToppings;
        private System.Windows.Forms.TextBox txtbCrustType;
        private System.Windows.Forms.TextBox lblCrustType;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox lblWhereToEat;
        private System.Windows.Forms.TextBox txtbTotalPrice;
        private System.Windows.Forms.TextBox lblTotalPrice;
        private System.Windows.Forms.RadioButton rbThick_Crust;
        private System.Windows.Forms.RadioButton rbThin_Crust;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtNumber_Of_Pizza;
    }
}

