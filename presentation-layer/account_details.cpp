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
           
    public partial class All_accounts : Form
    {
        Facade_Controller f1 = new Facade_Controller();

        public All_accounts()
        {
            InitializeComponent();
        }

        private void btn11_Click(object sender, EventArgs e)
        {
            try
            {
                string a = "select * from umairtable";
                f1.ExceuteQuerySet(a);
                data_grid.DataSource = f1.ExceuteQuerySet(a).Tables[0];
            }
            catch(IndexOutOfRangeException)
            {
                MessageBox.Show("ERROR 101 FOUND");
            }
            catch(NullReferenceException)
            { 
                MessageBox.Show("ERROR 101 FOUND"); 
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            home_Page h1 = new home_Page();
            h1.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            data_grid.DataSource = null;
            data_grid.Rows.Clear();
        }

        private void data_grid_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            { }
            catch(FormatException)
            {}
        }
    }
}

