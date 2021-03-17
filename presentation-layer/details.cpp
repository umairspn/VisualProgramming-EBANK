using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Presentataion_Layer;
using Logic_Layer;

namespace Presentataion_Layer
{
    public partial class Account_Details : Form
    {
       
        
        public Account_Details()
        {
            InitializeComponent();
        }

        private void bb5_Click(object sender, EventArgs e)
        {
            home_Page p1 = new home_Page();
            p1.Show();
            this.Hide();
        }


        private void bb1_Click(object sender, EventArgs e)
        {
            dataGridView1.Visible = true;
            string a = "select * from umairtable where (pin) = ('" + login_Pin_form.passing_Text + "')";
            Facade_Controller f1 = new Facade_Controller();
            dataGridView1.DataSource = f1.ExceuteQuerySet(a).Tables[0];
        }

        private void bb2_Click(object sender, EventArgs e)
        {
            Deposit_Money d1 = new Deposit_Money();
            d1.Show();
            this.Hide();
        }

        private void bb3_Click(object sender, EventArgs e)
        {
            Withdraw_Money w1 = new Withdraw_Money();
            w1.Show();
            this.Hide();
        }

        private void bb4_Click(object sender, EventArgs e)
        {
            change_Pin p1 = new change_Pin();
            p1.Show();
            this.Hide();
        }

        private void Account_Details_Load(object sender, EventArgs e)
        {
            dataGridView1.Visible = false;
        }
      
    
    
    }
  }

