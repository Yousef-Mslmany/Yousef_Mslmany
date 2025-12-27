using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;

namespace Memory_Game_Project
{
    public partial class frmMemory_Game : Form
    {
        public frmMemory_Game()
        {
            InitializeComponent();
        }

        int ClickCounter = 0; 
        int Total_Sec = 0;
        PictureBox FirstChoice;
        PictureBox SecondChoice; 

        void Disable_Images()
        {
            pbQuestion_Mark1.Enabled = false;
            pbQuestion_Mark2.Enabled = false;
            pbQuestion_Mark3.Enabled = false;
            pbQuestion_Mark4.Enabled = false;
            pbQuestion_Mark5.Enabled = false;
            pbQuestion_Mark6.Enabled = false;
            pbQuestion_Mark7.Enabled = false;
            pbQuestion_Mark8.Enabled = false;
            pbQuestion_Mark9.Enabled = false;
            pbQuestion_Mark10.Enabled = false;
        }

        void Activate_Images()
        {
            pbQuestion_Mark1.Enabled = true;
            pbQuestion_Mark2.Enabled = true;
            pbQuestion_Mark3.Enabled = true;
            pbQuestion_Mark4.Enabled = true;
            pbQuestion_Mark5.Enabled = true;
            pbQuestion_Mark6.Enabled = true;
            pbQuestion_Mark7.Enabled = true;
            pbQuestion_Mark8.Enabled = true;
            pbQuestion_Mark9.Enabled = true;
            pbQuestion_Mark10.Enabled = true;
        }

        private void frmMemory_Game_Load(object sender, EventArgs e)
        {
            cbSpeed.SelectedIndex = 0;
            cbTimer.SelectedIndex = 0;

            Disable_Images();
            Timer.Stop();
        }

        void Star_Score()
        {
            if(Star1.Tag.ToString() == "Empty_Star")
            {
                Star1.Image = Properties.Resources.Star_Gold;
                Star1.Tag = "Gold_Star";
                return;
            }

            if (Star2.Tag.ToString() == "Empty_Star")
            {
                Star2.Image = Properties.Resources.Star_Gold;
                Star2.Tag = "Gold_Star";
                return;
            }

            if (Star3.Tag.ToString() == "Empty_Star")
            {
                Star3.Image = Properties.Resources.Star_Gold;
                Star3.Tag = "Gold_Star";
                return;
            }

            if (Star4.Tag.ToString() == "Empty_Star")
            {
                Star4.Image = Properties.Resources.Star_Gold;
                Star4.Tag = "Gold_Star";
                return;
            }

            if (Star5.Tag.ToString() == "Empty_Star")
            {
                Star5.Image = Properties.Resources.Star_Gold;
                Star5.Tag = "Gold_Star";
                return;
            }
        }

        void Check_Match()
        {
            if (FirstChoice.Tag.ToString() == SecondChoice.Tag.ToString())
            {
                Star_Score();
                FirstChoice.Enabled = false;
                SecondChoice.Enabled = false;

                Chick_Win();
                ClickCounter = 0;
            }
            else
            {
                WrongMatchTimer.Start();
            }
        }

        void ChangeImage(PictureBox pictureBox)
        {
            if (pictureBox == pbQuestion_Mark1 || pictureBox == pbQuestion_Mark10)
            {
                pictureBox.Image = Properties.Resources.rubik;
                pictureBox.Tag = "rubik";
            }
            else if (pictureBox == pbQuestion_Mark2 || pictureBox == pbQuestion_Mark9)
            {
                pictureBox.Image = Properties.Resources.shapes;
                pictureBox.Tag = "shapes";
            }
            else if (pictureBox == pbQuestion_Mark3 || pictureBox == pbQuestion_Mark8)
            {
                pictureBox.Image = Properties.Resources.unique1;
                pictureBox.Tag = "unique1";
            }
            else if (pictureBox == pbQuestion_Mark4 || pictureBox == pbQuestion_Mark6)
            {
                pictureBox.Image = Properties.Resources.shapes__1_;
                pictureBox.Tag = "shapes__1_";
            }
            else if (pictureBox == pbQuestion_Mark5 || pictureBox == pbQuestion_Mark7)
            {
                pictureBox.Image = Properties.Resources.blocks;
                pictureBox.Tag = "blocks";
            }
        }

        void Re_image(PictureBox pictureBox)
        {
            if (pictureBox == pbQuestion_Mark1 || pictureBox == pbQuestion_Mark10)
            {
                pbQuestion_Mark1.Image = Properties.Resources.question_mark;
                pbQuestion_Mark1.Tag = "Question_Card";

                pbQuestion_Mark10.Image = Properties.Resources.question_mark;
                pbQuestion_Mark10.Tag = "Question_Card";
            }
            else if (pictureBox == pbQuestion_Mark2 || pictureBox == pbQuestion_Mark9)
            {
                pbQuestion_Mark2.Image = Properties.Resources.question_mark;
                pbQuestion_Mark2.Tag = "Question_Card";

                pbQuestion_Mark9.Image = Properties.Resources.question_mark;
                pbQuestion_Mark9.Tag = "Question_Card";
            }
            else if (pictureBox == pbQuestion_Mark3 || pictureBox == pbQuestion_Mark8)
            {
                pbQuestion_Mark3.Image = Properties.Resources.question_mark;
                pbQuestion_Mark3.Tag = "Question_Card";

                pbQuestion_Mark8.Image = Properties.Resources.question_mark;
                pbQuestion_Mark8.Tag = "Question_Card";
            }
            else if (pictureBox == pbQuestion_Mark4 || pictureBox == pbQuestion_Mark6)
            {
                pbQuestion_Mark4.Image = Properties.Resources.question_mark;
                pbQuestion_Mark4.Tag = "Question_Card";

                pbQuestion_Mark6.Image = Properties.Resources.question_mark;
                pbQuestion_Mark6.Tag = "Question_Card";
            }
            else if (pictureBox == pbQuestion_Mark5 || pictureBox == pbQuestion_Mark7)
            {
                pbQuestion_Mark5.Image = Properties.Resources.question_mark;
                pbQuestion_Mark5.Tag = "Question_Card";

                pbQuestion_Mark7.Image = Properties.Resources.question_mark;
                pbQuestion_Mark7.Tag = "Question_Card";
            }
        }

        void Chick_Win()
        {
            if(pbQuestion_Mark1.Tag.ToString() == "rubik"
                && pbQuestion_Mark10.Tag.ToString() == "rubik"
                && pbQuestion_Mark2.Tag.ToString() == "shapes"
                && pbQuestion_Mark9.Tag.ToString() == "shapes"
                && pbQuestion_Mark3.Tag.ToString() == "unique1"
                && pbQuestion_Mark8.Tag.ToString() == "unique1"
                && pbQuestion_Mark4.Tag.ToString() == "shapes__1_"
                && pbQuestion_Mark6.Tag.ToString() == "shapes__1_"
                && pbQuestion_Mark5.Tag.ToString() == "blocks"
                && pbQuestion_Mark7.Tag.ToString() == "blocks")
            {
                Timer.Stop();
                MessageBox.Show("You Won", "Congratulations", MessageBoxButtons.OK);
            }

        }

        void Reset_Pictures()
        {
            pbQuestion_Mark1.Image = Properties.Resources.question_mark;
            pbQuestion_Mark1.Tag = "Question_Card";
            pbQuestion_Mark1.Enabled = true;

            pbQuestion_Mark2.Image = Properties.Resources.question_mark;
            pbQuestion_Mark2.Tag = "Question_Card";
            pbQuestion_Mark2.Enabled = true;

            pbQuestion_Mark3.Image = Properties.Resources.question_mark;
            pbQuestion_Mark3.Tag = "Question_Card";
            pbQuestion_Mark3.Enabled = true;

            pbQuestion_Mark4.Image = Properties.Resources.question_mark;
            pbQuestion_Mark4.Tag = "Question_Card";
            pbQuestion_Mark4.Enabled = true;

            pbQuestion_Mark5.Image = Properties.Resources.question_mark;
            pbQuestion_Mark5.Tag = "Question_Card";
            pbQuestion_Mark5.Enabled = true;

            pbQuestion_Mark6.Image = Properties.Resources.question_mark;
            pbQuestion_Mark6.Tag = "Question_Card";
            pbQuestion_Mark6.Enabled = true;

            pbQuestion_Mark7.Image = Properties.Resources.question_mark;
            pbQuestion_Mark7.Tag = "Question_Card";
            pbQuestion_Mark7.Enabled = true;

            pbQuestion_Mark8.Image = Properties.Resources.question_mark;
            pbQuestion_Mark8.Tag = "Question_Card";
            pbQuestion_Mark8.Enabled = true;

            pbQuestion_Mark9.Image = Properties.Resources.question_mark;
            pbQuestion_Mark9.Tag = "Question_Card";
            pbQuestion_Mark9.Enabled = true;

            pbQuestion_Mark10.Image = Properties.Resources.question_mark;
            pbQuestion_Mark10.Tag = "Question_Card";
            pbQuestion_Mark10.Enabled = true;
        }

        void Reset_Score()
        {
            Star1.Image = Properties.Resources.Star_Empty;
            Star1.Tag = "Empty_Star";

            Star2.Image = Properties.Resources.Star_Empty;
            Star2.Tag = "Empty_Star";

            Star3.Image = Properties.Resources.Star_Empty;
            Star3.Tag = "Empty_Star";

            Star4.Image = Properties.Resources.Star_Empty;
            Star4.Tag = "Empty_Star";

            Star5.Image = Properties.Resources.Star_Empty;
            Star5.Tag = "Empty_Star";
        }

        private void cbSpeed_SelectedIndexChanged(object sender, EventArgs e)
        {
            string Speed = cbSpeed.SelectedItem.ToString();

            if (Speed == "1x")
                Timer.Interval = 1000;

            else if (Speed == "1.5x")
                Timer.Interval = 750;

            else if (Speed == "2x")
                Timer.Interval = 500;
        }

        private void cbTimer_SelectedIndexChanged(object sender, EventArgs e)
        {
            Total_Sec = int.Parse(cbTimer.SelectedItem.ToString()) * 60;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if(Total_Sec <= 0)
            {
                Timer.Stop();
                MessageBox.Show("You Lost", "Time's up", MessageBoxButtons.OK);
                lblTimer.Text = "00:00";
                return;
            }

            if(Total_Sec <= 5)
            {
                lblTimer.ForeColor = Color.Red;
            }

            Total_Sec--;

            lblTimer.Text = $"{Total_Sec / 60:00}:{Total_Sec % 60:00}";
        }

        private void btnStart_Click_1(object sender, EventArgs e)
        {
            if (Total_Sec <= 0) return;

            Activate_Images();
            lblTimer.Text = $"{Total_Sec / 60:00}:{Total_Sec % 60:00}";
            Timer.Start();
        }

        private void pbQuestion_Mark1_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark1.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark1);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark1;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark1;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark2_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark2.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark2);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark2;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark2;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark3_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark3.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark3);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark3;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark3;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark4_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark4.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark4);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark4;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark4;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark5_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark5.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark5);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark5;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark5;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark6_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark6.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark6);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark6;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark6;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark7_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark7.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark7);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark7;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark7;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark8_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark8.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark8);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark8;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark8;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark9_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark9.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark9);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark9;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark9;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void pbQuestion_Mark10_Click(object sender, EventArgs e)
        {
            if (pbQuestion_Mark10.Tag.ToString() == "Question_Card" && ClickCounter < 2)
            {
                ChangeImage(pbQuestion_Mark10);

                if (ClickCounter == 0)
                {
                    FirstChoice = pbQuestion_Mark10;
                    ClickCounter++;
                }
                else if (ClickCounter == 1)
                {
                    SecondChoice = pbQuestion_Mark10;
                    ClickCounter++;

                    Check_Match();
                }
            }
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            cbTimer.SelectedIndex = 0;
            cbSpeed.SelectedIndex = 0;
            Timer.Stop();
            lblTimer.Text = "00:00";
            lblTimer.ForeColor = Color.Black;

            Reset_Score();
            Reset_Pictures();
            Disable_Images();
        }

        private void WrongMatchTimer_Tick(object sender, EventArgs e)
        {
            WrongMatchTimer.Stop();

            Re_image(FirstChoice);
            Re_image(SecondChoice);

            ClickCounter = 0;
        }
    }
}
