using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_Order_Project
{
    public partial class Main_Form : Form
    {
        public Main_Form()
        {
            InitializeComponent();
        }

        float GetSelectedCrustPrice()
        {
            if (rbThin_Crust.Checked)
                return Convert.ToSingle(rbThin_Crust.Tag);
            else
                return Convert.ToSingle(rbThick_Crust.Tag);
        } 

        float CalculateToppingsPrice()
        {

            float ToppingsTotalPrice = 0;

            if (ckbExtra_Chees.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbExtra_Chees.Tag);
            }

            if(ckbOnion.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbOnion.Tag);
            }

            if (ckbOlives.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbOlives.Tag);
            }

            if (ckbMushrooms.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbMushrooms.Tag);
            }

            if (ckbTomatoes.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbTomatoes.Tag);
            }

            if (ckbGreen_Peppers.Checked)
            {
                ToppingsTotalPrice += Convert.ToSingle(ckbGreen_Peppers.Tag);
            }

            return ToppingsTotalPrice;
        }

        float GetSelectedSizePrice()
        {
            if (rbSmall.Checked)
                return Convert.ToSingle(rbSmall.Tag);

            else if(rbMeduim.Checked)
                return Convert.ToSingle(rbMeduim.Tag);

            else
                return Convert.ToSingle(rbLarg.Tag);
        }

        float CalculateTotalPrice()
        {
            return ((GetSelectedSizePrice() + CalculateToppingsPrice() + GetSelectedCrustPrice()) * Convert.ToSingle(numericUpDown1.Value));
        }

        void UpdateTotalPrice()
        {
            lblTotalPrice.Text = "$" + CalculateTotalPrice().ToString();
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rbSmall.Checked)
            {
                lblSize.Text = "Small";
                return;
            }

            if (rbMeduim.Checked)
            {
                lblSize.Text = "Meduim";
                return;
            }

            if (rbLarg.Checked)
            {
                lblSize.Text = "Larg";
                return;
            }

        }

        void UpdateCrust()
        {
            UpdateTotalPrice();

            if (rbThin_Crust.Checked)
            {
                lblCrustType.Text = "Thin Crust";
                return;
            }

            if (rbThick_Crust.Checked)
            {
                lblCrustType.Text = "Thick Crust";
                return;
            }

        }

        void UpdateToppings()
        {
            UpdateTotalPrice();

            string sToppings = "";

            if(ckbExtra_Chees.Checked)
            {
                sToppings = "Extra Chees";
            }

            if (ckbOnion.Checked)
            {
                sToppings += ", Onion";
            }

            if(ckbMushrooms.Checked)
            {
                sToppings += ", Mushrooms";
            }

            if (ckbOlives.Checked)
            {
                sToppings += ", Olives";
            }

            if (ckbTomatoes.Checked)
            {
                sToppings += ", Tomatoes";
            }

            if (ckbGreen_Peppers.Checked)
            {
                sToppings += ", Green Peppers";
            }

            if(sToppings.StartsWith(","))
            {
                sToppings = sToppings.Substring(1, sToppings.Length - 1).Trim();
            }

            if(sToppings == "")
            {
                sToppings = "No Toppings";
            }

            lblToppings.Text = sToppings;
        }

        void UpdateWhereToEat()
        {
            UpdateTotalPrice();

            if (rbEat_In.Checked)
            {
                lblWhereToEat.Text = "Eat In"; 
            }
            else
            {
                lblWhereToEat.Text = "Take Out";
            }

        }

        void ResetForm()
        {
            gbSize.Enabled = true;
            gbCrust_Type.Enabled = true;
            gbToppings.Enabled = true;
            gbWhere_To_Eat.Enabled = true;

            rbSmall.Checked = true;
            rbThin_Crust.Checked = true;
            rbEat_In.Checked = true;

            ckbExtra_Chees.Checked = false;
            ckbOnion.Checked = false;
            ckbMushrooms.Checked = false;
            ckbOlives.Checked = false;
            ckbTomatoes.Checked = false;
            ckbGreen_Peppers.Checked = false;

            btnOrder_Pizza.Enabled = true;
        }

        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateToppings();
            UpdateCrust();
            UpdateWhereToEat();
            UpdateTotalPrice();
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbMeduim_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbLarg_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rbThin_Crust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbThink_Crust_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrust();
        }

        private void rbEat_In_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void rbTake_Out_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEat();
        }

        private void chkExtra_Chees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ckbOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ckbMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ckbOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ckbTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void ckbGreen_Peppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();
        }

        private void btnOrder_Pizza_Click(object sender, EventArgs e)
        {
            if(MessageBox.Show("Confirm Order", "Confirm",
                MessageBoxButtons.OKCancel, MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success",
                MessageBoxButtons.OK, MessageBoxIcon.Information);
                btnOrder_Pizza.Enabled = false;
                gbSize.Enabled = false;
                gbToppings.Enabled = false;
                gbCrust_Type.Enabled = false;
                gbWhere_To_Eat.Enabled = false;
            }
        }

        private void btnReset_Form_Click(object sender, EventArgs e)
        {
            ResetForm();
        }

        private void Main_Form_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            txtNumber_Of_Pizza.Text = numericUpDown1.Value.ToString();
            UpdateTotalPrice();
        }
    }

    }
    