using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Text;
using System.Threading.Tasks;
using System.Security;
using System.Runtime.InteropServices;
using System.IO;

namespace ConsoleApp3
{
    [Serializable]
    static class UserBase
    {
        static String[] menu;
        static Dictionary<String, User> userBase;
        static Action[] m;
        static UserBase()
        {
            menu = new String[]
            {
                "Добавить юзера","Добавить юзера из файла","Записать в файл","Показать пользователя","Записать базу","Считать базу"
            };
            m = new Action[]
            {
                NewUser,NewUserFromFile,WriteOnFile,GiveUserInfo,SafeAll,ReadBase
            };
            userBase = new Dictionary<string, User>();

        }
        private static void ReadBase()
        {
            if (File.Exists("Base.dat"))
            {
                userBase=(Dictionary<String,User>)Utility.Deserialize("Base.dat");
            }
        }
        public static void Menu()
        {
            Int32 CordY = 5;
            ConsoleKeyInfo k;
            do
            {
                for (int i = 0; i < menu.Length; i++)
                {
                    Console.SetCursorPosition(Console.WindowWidth / 2, 5 + i);
                    if (CordY == (5 + i))
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                    }
                    else
                    {
                        Console.ForegroundColor = ConsoleColor.Yellow;
                    }
                    Console.Write(menu[i]);
                }
                k = Console.ReadKey(true);
                switch (k.Key)
                {
                    case ConsoleKey.UpArrow:
                        if (CordY <= 5) break;
                        else
                        {
                            CordY--;
                        }
                        break;
                    case ConsoleKey.DownArrow:
                        if (CordY >= 10) break;
                        else
                        {
                            CordY++;
                        }
                        break;
                    default:
                        break;
                }
                for (int i = 0; i < m.Length; i++)
                {
                    if (k.Key == ConsoleKey.Enter && CordY == (i + 5))
                    {
                        m[i].Invoke();
                    }
                }
            } while (k.Key != ConsoleKey.Escape);
        }
        private static void NewUserFromFile()
        {
            Console.Clear();
            Console.WriteLine("From file");
            String path = Console.ReadLine();
            User obj = (User)Utility.Deserialize(path);
            AddUser(obj);
            Console.Clear();

        }
        private static void NewUser()
        {
            Console.Clear();
            User obj = new User();
        }
        private static void WriteOnFile()
        {
            Console.Clear();
            String Login = Console.ReadLine();
            if (userBase.ContainsKey(Login))
            {
                Utility.Serialize(userBase[Login], Login + ".dat");
            }
        }
        private static void SafeAll()
        {
            Utility.Serialize(userBase, "Base.dat");
        }
        public static void AddUser(User obj)
        {
            if (userBase.ContainsKey(obj.login))
            {
                return;
            }
            else
            {
                userBase.Add(obj.login, obj);
            }
        }
        public static void GiveUserInfo()
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.Clear();
            Boolean stop = false;
            Console.WriteLine("Enter login:");
            String login = Console.ReadLine();
            if (userBase.ContainsKey(login))
            {
                do
                {
                    Console.Clear();
                    Console.WriteLine("Enter password");
                    if (userBase[login].pass.Equals(Console.ReadLine()))
                    {
                        Console.ForegroundColor = ConsoleColor.White;
                        Console.Clear();
                        Console.WriteLine(userBase[login].ToString());
                        Console.ReadKey();
                        Console.Clear();
                        stop = true;
                    }
                } while (!stop);

            }
        }
        unsafe public static Boolean CheckSecureString(SecureString str, SecureString str2)
        {

            if (str.Length == str2.Length)
            {
                Char* fromFirst = (Char*)Marshal.SecureStringToCoTaskMemUnicode(str);
                Char* fromSecond = (Char*)Marshal.SecureStringToCoTaskMemUnicode(str2);
                for (int i = 0; i < str.Length; i++)
                {
                    if (fromFirst[i] != fromSecond[i]) return false;
                }
                return true;
            }
            return false;
        }
        static public Boolean IsCorrectLogin(String login)
        {

            if (login != null)
            {
                String pattern = @"^[A-Z]+[\w]";
                Regex re = new Regex(pattern);

                if (re.IsMatch(login) && login.Count() > 4)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
                return false;
        }
        public static Dictionary<String, User> dict
        {
            get => userBase;
        }

    }
}
