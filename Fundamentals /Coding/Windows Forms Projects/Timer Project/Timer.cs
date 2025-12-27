using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tick_Tack_Project
{
    public partial class frmTimer : Form
    {
        public frmTimer()
        {
            InitializeComponent();
        }

        Stopwatch timer = new Stopwatch();

        private void btnStart_Click(object sender, EventArgs e)
        {
            timer.Start();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            timer.Stop();
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            timer.Reset();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
           lblTimer.Text = timer.Elapsed.ToString(@"hh\:mm\:ss\.ff");
        }


    }
}
