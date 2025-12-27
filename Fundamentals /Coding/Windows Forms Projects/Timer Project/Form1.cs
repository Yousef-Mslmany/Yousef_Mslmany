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
    public partial class frmTick_Tack : Form
    {
        public frmTick_Tack()
        {
            InitializeComponent();
        }

        private void btnCurrent_Clock_Click(object sender, EventArgs e)
        {
            Form frm = new frmCurrent_Clock();
            frm.Show();
        }

        private void btnTimer_Click(object sender, EventArgs e)
        {
            Form frm = new frmTimer();
            frm.Show();
        }

        private void btnStop_Watch_Click(object sender, EventArgs e)
        {
            Form frm = new frmStop_Watch();
            frm.Show();
        }
    }
}
