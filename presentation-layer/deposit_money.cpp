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
using System.Data.SqlClient;
namespace Presentataion_Layer
{

    public partial class Deposit_Money : Form
    {
        public Deposit_Money()
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

        private void deposit_btn_Click(object sender, EventArgs e)
        {
            
            if (count < 5)
            {
                try
                {
                    Facade_Controller f1 = new Facade_Controller();
                    string a = "select * from umairtable where (pin) = ('" + login_Pin_form.passing_Text + "')";
                    int m1 = int.Parse(deposit_txt.Text);
                    int m2 = int.Parse(f1.return_money(a));
                    //int result = 0;
                    //result+=(m1 + m2);
                    m2 = m2 + m1;
                    count++;                    
                    string b = "UPDATE umairtable set money = '"+m2.ToString()+"' WHERE pin = ('" + login_Pin_form.passing_Text + "')";
                    f1.deposit_query(b);

                    MessageBox.Show(deposit_txt.Text + "$  SUCCESSFULLY ADDED TO YOUR ACCOUNT");
                }
                catch(FormatException)
                {
                    MessageBox.Show("ERROR 101: ENTER DIGITS ONLY");
                }
                catch(SqlException)
                { MessageBox.Show("ERROR 101: TRY AGAIN"); }
                catch(NoNullAllowedException)
                { }
                catch(OverflowException)
                { MessageBox.Show("TOO MUCH AMOUNT"); }
            }
            else
            {
                MessageBox.Show("MAXIMUM LIMIT REACHED ");
            }

        }

        private void Deposit_Money_Load(object sender, EventArgs e)
        {
            //textBox1.Visible = false;
        }
        

        }        
    }
