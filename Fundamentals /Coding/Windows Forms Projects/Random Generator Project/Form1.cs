using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Random_Generator_Project
{
    public partial class frmRandom_Generator : Form
    {
        public frmRandom_Generator()
        {
            InitializeComponent();
        }

        Random rnd = new Random();

        enum Character_case
        {
            Capital_Letter,
            Small_Letter
        }

        Character_case Selected_Case = Character_case.Capital_Letter;

        void Generate_letters()
        {
            if (Selected_Case == Character_case.Capital_Letter)
            {
                txtResult.Clear();
                char letter = ' ';

                for (int i = 0; i < numericUpDown.Value; i++)
                {
                    letter = (char)rnd.Next('A', 'Z' + 1);
                    txtResult.Text += letter.ToString();
                }
            }

            if (Selected_Case == Character_case.Small_Letter)
            {
                txtResult.Clear();
                char letter = ' ';

                for (int i = 0; i < numericUpDown.Value; i++)
                {
                    letter = (char)rnd.Next('a', 'z' + 1);
                    txtResult.Text += letter.ToString();
                }
            } 
        }

        void Generate_Numbers()
        {
            txtResult.Clear();
            int Number = 0;

            for (int i = 0; i < numericUpDown.Value; i++)
            {
                Number = rnd.Next(1, 10);
                txtResult.Text += Number.ToString();
            }
        }

        void Generate_Special_Character()
        {
            txtResult.Clear();
            string SpecialCharacter = "!@#$%^&*()_-+=<>?";
            char OneCharacter = ' ';

            for (int i = 0; i < numericUpDown.Value; i++)
            {
                OneCharacter = SpecialCharacter[rnd.Next(SpecialCharacter.Length)];
                txtResult.Text += OneCharacter.ToString();
            }
        }

        void Generate_Mix_Character()
        {
            txtResult.Clear();
            string Capital_Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            string Small_Letters = "abcdefghijklmnopqrstuvwxyz";
            string Number = "123456789";
            string SpecialCharacter = "!@#$%^&*()_-+=<>?";
            string All = Capital_Letters + Small_Letters + Number + SpecialCharacter;

            char OneCharacter = ' ';

            for (int i = 0; i < numericUpDown.Value; i++)
            {
                OneCharacter = All[rnd.Next(All.Length)];
                txtResult.Text += OneCharacter.ToString();
            }

        }

        void FinalResult()
        {
            if(rbLetters.Checked)
            {
                Generate_letters();
                return;
            }

            if(rbNumbers.Checked)
            {
                Generate_Numbers();
                return;
            }

            if(rbSpecial_Character.Checked)
            {
                Generate_Special_Character();
                return;
            }

            if (rbMix.Checked)
            {
                Generate_Mix_Character();
                return;
            }
        }

        private void frmRandom_Generator_Load(object sender, EventArgs e)
        {
            rbLetters.Checked = true;
            Selected_Case = Character_case.Capital_Letter;

        }

        private void btnGenerate_Click(object sender, EventArgs e)
        {
            FinalResult();
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            rbLetters.Checked = true;
            numericUpDown.Value = 0;
            txtResult.Clear();
            btnGenerate.Focus();
            Selected_Case = Character_case.Capital_Letter;
        }

        private void Small_Letter_Click(object sender, EventArgs e)
        {
            Selected_Case = Character_case.Small_Letter;
        }

        private void Capital_Letter_Click(object sender, EventArgs e)
        {
            Selected_Case = Character_case.Capital_Letter;
        }
    }
}
