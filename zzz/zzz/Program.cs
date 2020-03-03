using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;//ПРОСТРАНСТВО ИМЕН СОДЕРЖАЩЕЕ БИНАРНЫЙ ФОРМАТЕР
using System.Runtime.Serialization.Formatters.Soap;
namespace zzz
{
    class Program
    {
        static void Main(string[] args)
        {
            //СЕРИАЛИЗАЦИЯ --- ЭТО СОХРАНЕНИЕ СОСТОЯНИЯ ОБЪЕКТА В ПАМЯТИ
            Point ptr = new Point(21,42,"test-test");
            Serialize(ptr, "test.dat");
            Point nPtr= (Point)Deserialize("test.dat");
            Console.WriteLine(nPtr.ToString());
            SoapFormatter(nPtr, "newtest.soap");
          
            .
        }
        static void Serialize(Object graph,String name)
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
        static void SoapFormatter(Object graph,String name)
        {
            if (graph.GetType().IsSerializable)
            {
                SoapFormatter ser = new SoapFormatter();
                using (Stream str = new FileStream(name, FileMode.Create, FileAccess.Write))//Автоматическое закрытие и уничтожение потока
                {
                    ser.Serialize(str, graph);
                }
            }
            else
                throw new ArgumentException("Type is not serializable");
        }
        static object Deserialize(string name)
        {
            Object ret;
            BinaryFormatter ser = new BinaryFormatter();
            using (Stream str = new FileStream(name,FileMode.Open))
            {
                ret=ser.Deserialize(str);
            }
            return ret;
        }
    }
    static class Utility
    {
        public static void Serialize(this Object graph, String name)
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
    }
    [Serializable]
    class Point
    {
        String name;
        Int32 X;
        Int32 Y;
        public Point()
        {
            X = 0;
            Y = 0;
            name = "unknown";
        }
        public Point(Int32 x,Int32 y,String n)
        {
            X = x;
            Y = y;
            name = n;
        }
        public override string ToString()
        {
            return string.Format("X={0} Y={1} Str={2}", X, Y,name);
        }
    }
}
