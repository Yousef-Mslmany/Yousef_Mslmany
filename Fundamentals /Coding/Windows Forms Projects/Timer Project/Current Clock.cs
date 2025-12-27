using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Timers;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tick_Tack_Project
{
    public partial class frmCurrent_Clock : Form
    {
        public frmCurrent_Clock()
        {
            InitializeComponent();
        }

        private void tmrCurrent_Clock_Tick(object sender, EventArgs e)
        {
            lblCurrent_Clock.Text = DateTime.Now.ToString("hh:mm:ss tt");
        }

        private void lblCurrent_Clock_Click(object sender, EventArgs e)
        {

        }

        private void lblCurrnt_Clock_Click(object sender, EventArgs e)
        {

        }
    }
}
