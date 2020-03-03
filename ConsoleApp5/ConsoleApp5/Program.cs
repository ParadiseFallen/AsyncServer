using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.Sql;
using System.Data.OleDb;

namespace ConsoleApp5
{
    class Program
    {
        static  private OleDbConnection myConnection;
        public static string connectString = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=data.accdb";
        static void Main(string[] args)
        {

            using (myConnection = new OleDbConnection(connectString))
            {
              OleDbTransaction  trs=  myConnection.BeginTransaction();
             
            }
            


        }

    }
}

