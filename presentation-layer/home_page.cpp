using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Logic_Layer;

namespace Presentataion_Layer
{
    public partial class home_Page : Form
    {
        public static string instruction_text;

        public home_Page()
        {
            InitializeComponent();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            address n1 = new address();
            n1.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            login_Pin_form l1 = new login_Pin_form();
            l1.Show();
            this.Hide();
        }

        
        private void button5_Click(object sender, EventArgs e)
        {
            All_accounts a1 = new All_accounts();
            a1.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            instruction_text = 
                "YOU CAN CREATE AND OPEN AN ACCOUNT HERE \n\n DEPOSIT OR WITHDRAW MONEY ANYTIME \n\n YOU CAN CHANGE YOUR PIN ANYTIME";
            Instructions i = new Instructions();
            i.Show();
            this.Hide();
        }


    }
}
   
