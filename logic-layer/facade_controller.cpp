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
    public class Facade_Controller
    {
       
       private static Facade_Controller ins;

        public Facade_Controller() 
        { }

        public static Facade_Controller Instance
        {
          get 
          {
             if (ins == null)
             {
                 ins = new Facade_Controller();
             }
             return ins;
          }
        }

 
        public string new_account_query(string a, string b, string c, string d, string e, string f)
        {
            Logic_Handler l1 = new Logic_Handler();
            return l1.new_account_query(a, b, c, d, e, f);
        }


        public static Facade_Controller getFController()
        {
            throw new NotImplementedException();
        }


        public string deposit_query(string x)
        {
            Logic_Handler l = new Logic_Handler();
            return l.deposit_query(x);
        }


        public DataSet ExceuteQuerySet(String Query)
        {
            Logic_Handler c1 = new Logic_Handler();
            return c1.ExceuteQuerySet(Query);
        }


        public DataTable Set_Data_Table(string query)
        {
            Logic_Handler c1 = new Logic_Handler();
            return c1.Set_Data_Table(query);
        }


        public string return_money(string x)
        {
            Logic_Handler l = new Logic_Handler();
            return l.return_money(x);
        }


      
 
    }
}
