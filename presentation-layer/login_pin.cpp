using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Logic_Layer;
using System.IO;
using Presentataion_Layer;
//using Data_Layer;


namespace Presentataion_Layer
{
    public partial class login_Pin_form : Form
    {
        public static string passing_Text;                  //static string.




        public login_Pin_form()
        {
            InitializeComponent();
        }



        private void button2_Click(object sender, EventArgs e)
        {
            home_Page h1 = new home_Page();
            h1.Show();
            this.Hide();
        }



        public void button1_Click(object sender, EventArgs e)
        {
            passing_Text = tbpin.Text;                              
            Account_Details a1 = new Account_Details();
            Facade_Controller f1 = new Facade_Controller();
            string a = "select * from umairtable where (pin) = ('" + passing_Text + "')";
           

            if (f1.Set_Data_Table(a).Rows.Count == 1)
            {
                MessageBox.Show("SUCCESSFULL LOGIN");
                a1.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("INVALID PIN, TRY AGAIN");
            }



            this.tbpin.Text = "";
        }
    }
}

