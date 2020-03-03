using System;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace ConsoleApp3
{
    class Program
    {
        static void Main(string[] args)
        {
            //User petya = new User();
            //UserBase.GiveUserInfo();
            UserBase.Menu();
        }
    }

    internal static class Utility
    {
        internal static void Serialize( Object graph, String name)
        {
            if (graph.GetType().IsSerializable)
            {
                BinaryFormatter ser = new BinaryFormatter();
                using (Stream str = new FileStream(name, FileMode.Create, FileAccess.Write))//Автоматическое закрытие и уничтожение потока
                {
                    ser.Serialize(str, graph);
                }
            }
            else
                throw new ArgumentException("Type is not serializable");


        }
        internal static object Deserialize(string name)
        {
            Object ret;
            BinaryFormatter ser = new BinaryFormatter();
            using (Stream str = new FileStream(name, FileMode.Open))
            {
                ret = ser.Deserialize(str);
            }
            return ret;
        }
    }
}
