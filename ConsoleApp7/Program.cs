using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp7
{

    class Wrap
    {
        public int MyProperty { get; set; }
    }
    class Smb
    {
        private Wrap _val;
        public Wrap Value { get { return _val; } set { _val = value; } }

        public event Action doSmb
        {
            add { doSmb2 += value; }
            remove { doSmb2 -= value; }
        }
        public Action doSmb2;

    }
    

    class Program
    {
        static void Main(string[] args)
        {
            Smb a = new Smb() { Value = new Wrap() { MyProperty = 5} };
            Smb b = new Smb() { Value = a.Value };
            a.Value.MyProperty += 100;
            Console.WriteLine(a.Value.MyProperty);
            Console.WriteLine(b.Value.MyProperty);
            Console.WriteLine();


            a.doSmb2 = null;


        }
    }
}
