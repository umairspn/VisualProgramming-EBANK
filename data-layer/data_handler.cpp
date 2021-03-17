using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Data_Layer;
using System.Data.SqlClient;

namespace Data_Layer
{
    public class Data_Handler
    {
        public string new_account_query(string a, string b, string c, string d, string e, string f)
        {
            ConnectToDatabase cc = new ConnectToDatabase();
            cc.ConnectToDB();
            try
            {
                my_query_builder q = new my_query_builder();
                SqlCommand command = new SqlCommand(q.new_account_query(a, b, c, d, e, f), cc.DB_Connection);
                command.ExecuteNonQuery();
            }
            catch (InvalidOperationException)
            {
                cc.ConnectToDB();                          //in case, there is no connection established.
            }
            return "SUCCESSFULL";
        } 



        public string return_money(string x)
        {

            ConnectToDatabase cc = new ConnectToDatabase();
            cc.ConnectToDB();
            SqlCommand comd = new SqlCommand(x, cc.DB_Connection);
            string str = Convert.ToString(comd.ExecuteScalar());
            return str;
        }


        public string deposit_query(string x)
        {
            ConnectToDatabase cc = new ConnectToDatabase();
            cc.ConnectToDB();
            try
            {
                my_query_builder q = new my_query_builder();
                SqlCommand command = new SqlCommand(x, cc.DB_Connection);
                command.ExecuteNonQuery();   
            }
            catch (InvalidOperationException)
            {
                cc.ConnectToDB();                          //in case, there is no connection established.
            }
            return "SUCCESSFULL";
        }


    }
}
