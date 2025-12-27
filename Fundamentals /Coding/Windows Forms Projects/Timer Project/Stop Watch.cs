using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tick_Tack_Project
{
    public partial class frmStop_Watch : Form
    {
        public frmStop_Watch()
        {
            InitializeComponent();
        }

        int Sec = 0;
        int Min = 0;
        int Hour = 0;
        int Total_Sec = 0;

        private void cbSeconds_SelectedIndexChanged(object sender, EventArgs e)
        {
            Sec = Convert.ToInt32(cbSeconds.SelectedItem);
        }

        private void cbMinutes_SelectedIndexChanged(object sender, EventArgs e)
        {
            Min = Convert.ToInt32(cbMinutes.SelectedItem);
        }

        private void cbHours_SelectedIndexChanged(object sender, EventArgs e)
        {
            Hour = Convert.ToInt32(cbHours.SelectedItem);
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            Total_Sec = Sec + Min * 60 + Hour * 3600;
            progressBar.Maximum = Total_Sec;
            progressBar.Value = progressBar.Maximum;
            tmr.Enabled = true;
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            tmr.Enabled = false;
        }


        private void tmr_Tick(object sender, EventArgs e)
        {
            if (Total_Sec <= 0)
            {
                tmr.Stop();
                notifyIcon1.Icon = SystemIcons.Information;
                notifyIcon1.BalloonTipTitle = "Note";
                notifyIcon1.BalloonTipText = "Ended Time";
                notifyIcon1.ShowBalloonTip(3000);
                return;
            }

            progressBar.Value--;

            Total_Sec--;

            Hour = Total_Sec / 3600;
            Min = (Total_Sec % 3600) / 60;
            Sec = Total_Sec % 60;

            lblTimer.Text = $"{Hour:00}:{Min:00}:{Sec:00}";
        }

        private void frmStop_Watch_Load(object sender, EventArgs e)
        {
            tmr.Enabled = false;
        }
    }
}
