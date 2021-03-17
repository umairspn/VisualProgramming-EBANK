using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using Logic_Layer;
namespace Presentataion_Layer
{
    public partial class Withdraw_Money : Form
    {
        public Withdraw_Money()
        {
            InitializeComponent();
        }

        int count = 0;

        private void back_btn_Click(object sender, EventArgs e)
        {
            Account_Details a1 = new Account_Details();
            a1.Show();
            this.Hide();
        }


        private void withdraw_btn_Click(object sender, EventArgs e)
        {
            if (count < 5)
            {
                try
                {
                    Facade_Controller f1= new Facade_Controller();
                    string a = "select * from umairtable where (pin) = ('" + login_Pin_form.passing_Text + "')";
                    int m1 = int.Parse(withdraw_txt.Text);
                    int m2 = int.Parse(f1.return_money(a));
                    if(m1>50000)
                    {
                        MessageBox.Show("YOU CANNOT WITHDRAW MORE THAN 50000 IN ONE TRANSACTION");
                    }
                    else if(m2>m1)
                    {
                        m2 = m2 - m1;
                        MessageBox.Show(this.withdraw_txt.Text + "$  SUCCESSFULLY WITHDRAWN");
                        count++;
                        withdraw_txt.Text = "";
                    }
                    else
                    {
                        MessageBox.Show("YOU DONT HAVE ENOUGH BALANCE");
                    }

                    string b = "UPDATE umairtable set money = '"+ m2.ToString() +"' WHERE pin = ('" + login_Pin_form.passing_Text + "')";
                    f1.deposit_query(b);

                }
                    catch (FormatException)
                    {
                        MessageBox.Show("ERROR 101: ENTER DIGITS ONLY");
                    }

            }
            else
            {
                MessageBox.Show("MAXIMUM LIMIT REACHED");
            }
        }
    }
}
