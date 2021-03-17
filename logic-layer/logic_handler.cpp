using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.Common;
using System.Data.Odbc;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Configuration;
using System.Web;
using System.Data.OleDb;
using Data_Layer;

namespace Logic_Layer
{
    class Logic_Handler
    {
      

        public string new_account_query(string a, string b, string c, string d, string e, string f)
        {
            Data_Handler ob = new Data_Handler();
            string temp= ob.new_account_query(a,b,c,d,e,f);
            return temp;
        }


        public DataSet ExceuteQuerySet(String Query)
        {
            ConnectToDatabase c1 = new ConnectToDatabase();
            return c1.ExceuteQuerySet(Query);
        }

        public DataTable Set_Data_Table(string query)
        {
            ConnectToDatabase c1 = new ConnectToDatabase();
            return c1.Set_Data_Table(query);
        }


        public string return_money(string x)
        {
            Data_Handler h = new Data_Handler();
            return h.return_money(x);
        }

        public string deposit_query(string x)
        {
            Data_Handler h1 = new Data_Handler();
            return h1.deposit_query(x);
        }



        

    }
}
