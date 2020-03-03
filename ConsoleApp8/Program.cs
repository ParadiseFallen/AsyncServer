using CSScriptLibrary;
using Microsoft.CSharp;
using System;
using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp8
{

    static public class Test
    {
        static public int SInt { get; set; } = 0;
    }

    class Program
    {


        static void Main(string[] args)
        {
            //var product = CSScript.CreateFunc<int>(@"using ConsoleApp8;
            //                             int any()
            //                             {
            //                                 Test.SInt =100;
            //                                 Console.WriteLine(Test.SInt);
            //                                 return 0;
            //                             }");

            //var t = Tuple.Create<int, int>(1, 5);
            var b = (g:6,b: 5);
            
            Console.WriteLine(b.g);
            Console.WriteLine(b);
            Console.ReadKey();
        }
    }
}
