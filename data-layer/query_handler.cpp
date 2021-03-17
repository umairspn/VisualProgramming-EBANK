using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using Data_Layer;

namespace Data_Layer
{
    public class my_query_builder
    {
       
        public string new_account_query(string a, string b, string c, string d, string e, string f)
        {
            string query = @"insert into umairtable (name,account_no,address,contact_no,pin,money) values ('" + a + "', '" + b + "','" + c + "','" + d + "','" + e + "','" + f + "' )";
            return query;
        }

        public string all_account_query()
        {
            string query = "select * from umairtable "; 
            return query;
        }


    }
}

