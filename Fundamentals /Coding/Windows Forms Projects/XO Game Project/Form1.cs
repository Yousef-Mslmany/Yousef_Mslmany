using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tic___Tac___Toe_Game.Properties;

namespace Tic___Tac___Toe_Game
{
    public partial class frmTic_Tac_Toe_Game : Form
    {
        public frmTic_Tac_Toe_Game()
        {
            InitializeComponent();
        }

        Image X = Image.FromFile(@"C:\X.png");
        Image O = Image.FromFile(@"C:\O.png");
        Image Q = Image.FromFile(@"C:\Question_Mark.png");

        private void Tic_Tac_Toe_Game_Load(object sender, EventArgs e)
        {
            pb_Choice1.Image = Q;
            pb_Choice2.Image = Q;
            pb_Choice3.Image = Q;
            pb_Choice4.Image = Q;
            pb_Choice5.Image = Q;
            pb_Choice6.Image = Q;
            pb_Choice7.Image = Q;
            pb_Choice8.Image = Q;
            pb_Choice9.Image = Q;

            lblTurn.Text = "Player 1";
            lblWinner.Text = "In Progress";
        }

        private void Tic_Tac_Toe_Game_Paint(object sender, PaintEventArgs e)
        {
            Color White = Color.FromArgb(255, 255, 255, 255);
            Pen pen = new Pen(White);
            pen.Width = 10;

            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(pen, 500, 450, 500, 125);
            e.Graphics.DrawLine(pen, 700, 450, 700, 125);
            e.Graphics.DrawLine(pen, 385, 225, 800, 225);
            e.Graphics.DrawLine(pen, 385, 350, 800, 350);
        }

        void HighlightWin(PictureBox a, PictureBox b, PictureBox c)
        {
            Color winColor = Color.Yellow;

            a.BackColor = winColor;
            b.BackColor = winColor;
            c.BackColor = winColor;
        }

        void ResetColors()
        {
            pb_Choice1.BackColor = Color.Transparent;
            pb_Choice2.BackColor = Color.Transparent;
            pb_Choice3.BackColor = Color.Transparent;
            pb_Choice4.BackColor = Color.Transparent;
            pb_Choice5.BackColor = Color.Transparent;
            pb_Choice6.BackColor = Color.Transparent;
            pb_Choice7.BackColor = Color.Transparent;
            pb_Choice8.BackColor = Color.Transparent;
            pb_Choice9.BackColor = Color.Transparent;
        }

        bool CheckWin(Image symbol)
        {

            if (pb_Choice1.Image == symbol && pb_Choice2.Image == symbol && pb_Choice3.Image == symbol)
            {
                HighlightWin(pb_Choice1, pb_Choice2, pb_Choice3);
                return true;
            }

            if (pb_Choice4.Image == symbol && pb_Choice5.Image == symbol && pb_Choice6.Image == symbol)
            {
                HighlightWin(pb_Choice4, pb_Choice5, pb_Choice6);
                return true;
            }

            if (pb_Choice7.Image == symbol && pb_Choice8.Image == symbol && pb_Choice9.Image == symbol)
            {
                HighlightWin(pb_Choice7, pb_Choice8, pb_Choice9);
                return true;
            }

            if (pb_Choice1.Image == symbol && pb_Choice4.Image == symbol && pb_Choice7.Image == symbol)
            {
                HighlightWin(pb_Choice1, pb_Choice4, pb_Choice7);
                return true;
            }

            if (pb_Choice2.Image == symbol && pb_Choice5.Image == symbol && pb_Choice8.Image == symbol)
            {
                HighlightWin(pb_Choice2, pb_Choice5, pb_Choice8);
                return true;
            }

            if (pb_Choice3.Image == symbol && pb_Choice6.Image == symbol && pb_Choice9.Image == symbol)
            {
                HighlightWin(pb_Choice3, pb_Choice6, pb_Choice9);
                return true;
            }

            if (pb_Choice1.Image == symbol && pb_Choice5.Image == symbol && pb_Choice9.Image == symbol)
            {
                HighlightWin(pb_Choice1, pb_Choice5, pb_Choice9);
                return true;
            }

            if (pb_Choice3.Image == symbol && pb_Choice5.Image == symbol && pb_Choice7.Image == symbol)
            {
                HighlightWin(pb_Choice3, pb_Choice5, pb_Choice7);
                return true;
            }

            return false;
        }

        bool Draw()
        {
            
            if (CheckWin(X) || CheckWin(O))
                return false;

            if (pb_Choice1.Image == Q ||
                pb_Choice2.Image == Q ||
                pb_Choice3.Image == Q ||
                pb_Choice4.Image == Q ||
                pb_Choice5.Image == Q ||
                pb_Choice6.Image == Q ||
                pb_Choice7.Image == Q ||
                pb_Choice8.Image == Q ||
                pb_Choice9.Image == Q)
                return false;

            return true;
        }

        bool Winner()
        {
            if(CheckWin(X))
            {
                lblTurn.Text = "Game Over";
                lblWinner.Text = "Player 1";
                MessageBox.Show("Winner Player 1", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }

            if(CheckWin(O))
            { 
                lblTurn.Text = "Game Over";
                lblWinner.Text = "Player 2";
                MessageBox.Show("Winner Player 2", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }

            if (Draw())
            {
                lblTurn.Text = "Game Over";
                lblWinner.Text = "Draw";
                MessageBox.Show("Draw", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return true;
            }

            return false;
        }

        void UpdateTurn()
        {
            if (lblTurn.Text == "Player 1")
            {
                lblTurn.Text = "Player 2";
            }
            else
            {
                lblTurn.Text = "Player 1";
            }
        }

        void UpdatePicture(PictureBox pb_Choice)
        {
            if (pb_Choice.Image == X || pb_Choice.Image == O)
            {
                MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (lblTurn.Text == "Player 1")
                pb_Choice.Image = X;
            else
                pb_Choice.Image = O;

            if(!Winner())
               UpdateTurn();
        }

        private void pb_Choice1_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice1);
        }

        private void pb_Choice2_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice2);
        }

        private void pb_Choice3_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice3);
        }

        private void pb_Choice4_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice4);
        }

        private void pb_Choice5_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice5);
        }

        private void pb_Choice6_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice6);
        }

        private void pb_Choice7_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice7);
        }

        private void pb_Choice8_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice8);
        }

        private void pb_Choice9_Click(object sender, EventArgs e)
        {
            UpdatePicture(pb_Choice9);
        }

        private void btnRestartGame_Click(object sender, EventArgs e)
        {
            ResetColors();

            pb_Choice1.Image = Q;
            pb_Choice2.Image = Q;
            pb_Choice3.Image = Q;
            pb_Choice4.Image = Q;
            pb_Choice5.Image = Q;
            pb_Choice6.Image = Q;
            pb_Choice7.Image = Q;
            pb_Choice8.Image = Q;
            pb_Choice9.Image = Q;
            lblTurn.Text = "Player 1";
            lblWinner.Text = "In Progress";
        }
    }
}
