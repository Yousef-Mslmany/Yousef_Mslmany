using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Encryption_Decryption_Project
{
    public partial class frmEncryption_Decryption_Project : Form
    {
        public frmEncryption_Decryption_Project()
        {
            InitializeComponent();
        }

        string Placeholder_Org = "Enter text encrypted or choose file encrypted";
        string Placeholder_Dec = "Enter text decrypted or choose file decrypted";

        void Encryption()
        {
            txtDecryption2.Clear();
            for (int i = 0; i < txtOriginal_Text.TextLength; i++)
            {
                if (txtOriginal_Text.Text[i] == '\r')
                    continue;

                if (txtOriginal_Text.Text[i] == '\n')
                {
                    txtDecryption2.Text += "\r\n";
                    continue;
                }

                txtDecryption2.Text += (char)(txtOriginal_Text.Text[i] + 2);
            }
        }

        void Decryption()
        {
            txtOriginal_Text2.Clear();
            for (int i = 0; i < txtDecryption.TextLength; i++)
            {
                if (txtDecryption.Text[i] == '\r')
                    continue;

                if (txtDecryption.Text[i] == '\n')
                {
                    txtOriginal_Text2.Text += "\r\n";
                    continue;
                }

                txtOriginal_Text2.Text += (char)(txtDecryption.Text[i] - 2);
            }
        }

        void Reset(TextBox txt_Original, TextBox txt_Decryption)
        {
            if(txt_Original.Text == txtOriginal_Text.Text)
            {
                txt_Original.Clear();
                txtOriginal_Text.Text = Placeholder_Org;
                txtOriginal_Text.ForeColor = Color.LightGray;
                txt_Decryption.Clear();
                return;
            }

            if (txt_Original.Text == txtDecryption.Text)
            {
                txt_Original.Clear();
                txtDecryption.Text = Placeholder_Dec;
                txtDecryption.ForeColor = Color.LightGray;
                txt_Decryption.Clear();
                return;
            }
        }

        void Is_Not_Text()
        {
            MessageBox.Show("You Should Enter Text", "Warring", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        void SaveFile(TextBox txt)
        {
            SaveTextFile.InitialDirectory = @"C:\";
            SaveTextFile.Title = "Save Text to File";
            SaveTextFile.Filter = "txt files (*.txt) | *.txt | All files (*.*) | *.*";
            SaveTextFile.DefaultExt = "txt";
            SaveTextFile.FilterIndex = 1;
            SaveTextFile.FileName = "Text.txt";
            if (SaveTextFile.ShowDialog() == DialogResult.OK)
            {
                File.WriteAllText(SaveTextFile.FileName, txt.Text);
                MessageBox.Show("Text Saved Successfully", "Note", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        void OpenFile()
        {
            OpenTextFile.InitialDirectory = @"C:\";
            OpenTextFile.Title = "Open File to get Text";
            OpenTextFile.Filter = "txt files (*.txt) | *.txt | All files (*.*) | *.*";
            OpenTextFile.DefaultExt = "txt";
            OpenTextFile.FilterIndex = 0;
            OpenTextFile.FileName = "Text.txt";
            if (OpenTextFile.ShowDialog() == DialogResult.OK)
            {
                txtDecryption.ForeColor = Color.Black;
                txtDecryption.Text = File.ReadAllText(OpenTextFile.FileName);
            }
        }

        private void frmEncryption_Decryption_Project_Load(object sender, EventArgs e)
        {
            txtOriginal_Text.Text = Placeholder_Org;
            txtOriginal_Text.ForeColor = Color.LightGray;

            txtDecryption.Text = Placeholder_Dec;
            txtDecryption.ForeColor = Color.LightGray;
        }

        private void txtDecryption_Enter(object sender, EventArgs e)
        {
            if (txtDecryption.Text == Placeholder_Dec)
            {
                txtDecryption.Text = "";
                txtDecryption.ForeColor = Color.Black;
            }
        }

        private void txtOriginal_Text_Enter(object sender, EventArgs e)
        {
            if(txtOriginal_Text.Text == Placeholder_Org)
            {
                txtOriginal_Text.Text = "";
                txtOriginal_Text.ForeColor = Color.Black;
            }
        }

        private void txtOriginal_Text_Leave(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtOriginal_Text.Text))
            {
                txtOriginal_Text.Text = Placeholder_Org;
                txtOriginal_Text.ForeColor = Color.LightGray;
            }
        }

        private void txtDecryption_Leave(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(txtDecryption.Text))
            {
                txtDecryption.Text = Placeholder_Dec;
                txtDecryption.ForeColor = Color.LightGray;
            }
        }

        private void btnEncryption_Click(object sender, EventArgs e)
        {
            if(txtOriginal_Text.Text == Placeholder_Org)
            {
                Is_Not_Text();
                return;
            }
            Encryption();
        }

        private void btnDecryption_Click(object sender, EventArgs e)
        {
            if (txtDecryption.Text == Placeholder_Dec)
            {
                Is_Not_Text();
                return;
            }
            Decryption();
        }

        private void btnReset_En_Click(object sender, EventArgs e)
        {
            Reset(txtOriginal_Text, txtDecryption2);
        }

        private void btnReset_De_Click(object sender, EventArgs e)
        {
            Reset(txtDecryption, txtOriginal_Text2);
        }

        private void btnSave_1_Click(object sender, EventArgs e)
        {
            SaveFile(txtDecryption2);
        }

        private void openFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFile();
        }

        private void btnSave_2_Click(object sender, EventArgs e)
        {
            SaveFile(txtOriginal_Text2);
        }
    }
}
