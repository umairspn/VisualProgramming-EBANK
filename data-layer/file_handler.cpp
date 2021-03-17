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

namespace Data_Layer
{
    public class ConnectToDatabase
    {

        public SqlConnection DB_Connection;
        private SqlDataAdapter DataAdapter;
        public DataSet ResultSet;
        private SqlCommand QueryCommand;
        private SqlDataReader QueryResultReader;
        public ConnectToDatabase()
        { }


        public void ConnectToDB()
        {
            DB_Connection = new SqlConnection(@"Data Source=(LocalDB)\v11.0;AttachDbFilename=C:\Users\M\Desktop\Umair Assignment 2\three_tier_architecture\Data_Layer\umair_database.mdf;Integrated Security=True");
            DB_Connection.Open();
            ResultSet = new DataSet();
        }

        public DataSet ExceuteQuerySet(String Query)
        {
            ConnectToDB();
            try
            {
                DataAdapter = new SqlDataAdapter(Query, DB_Connection);
                DataAdapter.Fill(ResultSet);
                DataAdapter.Dispose();
            }
            catch(SqlException)
            { }
            catch(ArgumentNullException)
            { }

            return ResultSet;
        }

        public SqlDataReader ExceuteQuery(String Query)
        {
            QueryCommand = new SqlCommand(Query, DB_Connection);
            QueryResultReader = QueryCommand.ExecuteReader();
            QueryCommand.Dispose();
            return QueryResultReader;
        }

        public int UpdateQuery(String Query)
        {

            QueryCommand = new SqlCommand(Query, DB_Connection);
            int Result = QueryCommand.ExecuteNonQuery();
            QueryCommand.Dispose();

            return Result;

        }

        public int UpdateQuerySet(DataSet ds, String Query)
        {
            DataAdapter = new SqlDataAdapter(Query, DB_Connection);
            DataAdapter.Fill(ResultSet);
            ResultSet = ds.Copy();
            int Result = DataAdapter.Update(ResultSet);
            DataAdapter.Dispose();
            return Result;
        }

        public object SpecificQuery(String Query)
        {
            QueryCommand = new SqlCommand(Query, DB_Connection);
            object Result = QueryCommand.ExecuteScalar();
            QueryCommand.Dispose();
            return Result;
        }

        public void CloseConnection()
        {
            DB_Connection.Close();
        }


        public DataTable Set_Data_Table(string query)
        {
            ConnectToDB();
            SqlDataAdapter ss = new SqlDataAdapter(query, DB_Connection);
            DataTable dt = new DataTable();
            try
            {
            ss.Fill(dt);
            }
           catch(SqlException)
            { }
            catch(ArgumentNullException)
            { }
            return dt;
        }
        }
    }

