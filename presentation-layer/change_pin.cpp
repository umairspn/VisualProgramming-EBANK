using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Data.SqlClient;
using Logic_Layer;
namespace Presentataion_Layer
{
    public partial class change_Pin : Form
    {
        public change_Pin()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Account_Details a1 = new Account_Details();
            a1.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Facade_Controller f1 = new Facade_Controller();
            string a = "select pin from umairtable where (pin) = ('" + login_Pin_form.passing_Text + "')";

            if (f1.Set_Data_Table(a).Rows.Count == 1)
            {
                MessageBox.Show("SUCCESSFULL LOGIN");
            }
            else if (f1.Set_Data_Table(a).Rows.Count >0)
            {
                MessageBox.Show("");
            }
            else
            {
                MessageBox.Show("INVALID PIN, TRY AGAIN");
            }



    catch (IndexOutOfRangeException)
                {
                    MessageBox.Show("ERROR 101: THE CURRENT INDEX IS OUT OF RANGE, TRY AGAIN");
                }
            }
            
            }
            
            

        private void change_Pin_Load(object sender, EventArgs e)
        {
            label4.Text = login_Pin_form.passing_Text;
        }

        private void newPin_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
}
