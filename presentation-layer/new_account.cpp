using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Logic_Layer;
using System.Text.RegularExpressions;
using System.Data.SqlClient;
namespace Presentataion_Layer
{
    public partial class address : Form
    {


        public address()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            home_Page h1 = new home_Page();
            h1.Show();
            this.Hide();
        }

        private bool test_function(string add)
        {
            char[] arr_test = add.ToCharArray();
            bool bool_var = false;
            for (int i = 0; i < arr_test.Length; i++)
            {
                if (char.IsNumber(arr_test[i]))
                {
                    bool_var = true;
                }
            }
            return bool_var;
        }

        private bool name_check()
        {
            char[] arr_test = name_tb.Text.ToCharArray();
            bool bool_var = false;
            for (int i = 0; i < arr_test.Length; i++)
            {
                if (char.IsNumber(arr_test[i]))
                {
                    bool_var = true;
                }
            }
            return bool_var;
        }

        private bool acctno_check()
        {
            char[] arr_test = acctno_tb.Text.ToCharArray();
            bool bool_var = false;
            for (int i = 0; i < arr_test.Length; i++)
            {
                if (!char.IsNumber(arr_test[i]))
                {
                    bool_var = true;
                }
            }
            return bool_var;
        }


        private bool contactno_check()
        {
            char[] arr_test = cntctno_tb.Text.ToCharArray();
            bool bool_var = false;
            for (int i = 0; i < arr_test.Length; i++)
            {
                if (!char.IsNumber(arr_test[i]))
                {
                    bool_var = true;
                }
            }
            return bool_var;
        }



        private void acctno_TextChanged(object sender, EventArgs e)
        {
            if (acctno_check() == true)
            {
                this.errorProvider1.SetError(acctno_tb, "This field must contain only NUMBERS");
            }
            else
            {
                this.errorProvider1.SetError(acctno_tb, "");
            }
        }

        private void cntctno_TextChanged(object sender, EventArgs e)
        {
            if (contactno_check() == true)
            {
                this.errorProvider1.SetError(cntctno_tb, "This field must contain only NUMBERS");
            }
            else
            {
                this.errorProvider1.SetError(cntctno_tb, "");
            }
        }

        private void name_TextChanged(object sender, EventArgs e)
        {
            if (name_check() == true)
            {
                this.errorProvider3.SetError(name_tb, "This feild must contain only letters");
            }
            else
            {
                this.errorProvider3.SetError(name_tb, "");
            }
        }

        private void addrss_TextChanged(object sender, EventArgs e)
        {
            if (test_function(this.addrss_tb.Text) == true)
            {
                this.errorProvider4.SetError(addrss_tb, "NO");
            }
            else
            {
                this.errorProvider4.SetError(addrss_tb, "");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.name_tb.Text == "" || this.acctno_tb.Text == "" ||
                   this.addrss_tb.Text == "" || this.cntctno_tb.Text == "" || this.pin_tb.Text == "")
            {
                MessageBox.Show("FILL ALL BLANKS");
            }

            else if (contactno_check() == true || acctno_check() == true || name_check() == true)
            {
                MessageBox.Show("ERROR IN INPUT FIELDS");
            }
            else
            {
                Facade_Controller f1 = new Facade_Controller();
                string temp;
                double money = 0;
                int a=0;
                try
                {
                    temp = f1.new_account_query(this.name_tb.Text.Trim(), this.acctno_tb.Text.Trim(),
                           this.addrss_tb.Text.Trim(), this.cntctno_tb.Text.Trim(), this.pin_tb.Text.Trim(), money.ToString());
                }
                catch (SqlException)
                {
                    MessageBox.Show("ERROR WHILE SAVING DATA, TRY AGAIN");
                    a = 5;
                }
                if (a!=5)
                {
                    this.errorProvider1.SetError(acctno_tb, "");
                    this.errorProvider2.SetError(cntctno_tb, "");

                    MessageBox.Show("ACCOUNT HAS BEEN CREATED");
                    this.name_tb.Text = ""; this.acctno_tb.Text = "";
                    this.addrss_tb.Text = ""; this.cntctno_tb.Text = "";
                    this.pin_tb.Text = "";
                }
            }
        }

        private void pin_TextChanged(object sender, EventArgs e)
        {

        }
