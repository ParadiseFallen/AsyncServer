using System;
using System.Security;

namespace ConsoleApp3
{
    [Serializable][Obsolete("ЭТА СРАНЬ УСТАРЕЛА!!!",true)]
    class User
    {
        String Login;
        String passWord;
        String FirstName;
        String LastName;
        UInt32 Age;
        public User()
        {
            
            CreateLogin();
            passWord = Password();
            FirstName = "f";
            LastName = "l";
            Age = 0;
            UserBase.AddUser(this);
        }
        void CreatePassword()
        {
            
                passWord = Password();
           
        }
       // public static String EnterPassword()
        //{
        //    String pass;
        //    Console.WriteLine("Enter password:");
        //    while (true)
        //    {

        //        ConsoleKeyInfo k = Console.ReadKey(true);
        //        if (k.Key == ConsoleKey.Enter && pass.Length != 0)
        //        {
        //            break;
        //        }
        //        else if (k.Key != ConsoleKey.Delete || k.Key != ConsoleKey.Backspace)
        //        {
        //            Console.Write("*");
        //            pass+=k.
        //        }
        //    }
        //    return pass;
        //}
        public static String Password()
        {
            String pass;
            Console.WriteLine("Enter password:");
            do
            {
                pass = Console.ReadLine();
            } while (pass.Length<4);
            return pass;
        }
        private void CreateLogin()
        {
            Console.Clear();
            Console.WriteLine("Enter login with minimum 4 symbol");
            String tempLogin;
            while (true)
            {
                tempLogin = Console.ReadLine();
                if (!UserBase.dict.ContainsKey(tempLogin) && UserBase.IsCorrectLogin(tempLogin))
                {
                    Login = tempLogin;
                    break;
                }
            }
        }

        public override string ToString()
        {
            return String.Format("{0} {1} {2} {3}", Login, Age, FirstName, LastName);
        }
        public String login
        {
            get => Login;
        }
        public String pass
        {
            get => passWord;
        }
    }
}
