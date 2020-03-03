using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {

        static string Perevod(int i)
        {
            string[] n_day = { "Ponidelnik", "Vtornik", "Sreda", "Chetverg", "Pyatnica", "Subota", "Nedelya"};
            string temp = n_day.ElementAt(i-1);
            return temp;
        }
        static void Main(string[] args)
        {
            int[] mass = new int[100];
            Random rand = new Random ();
            for (int i = 0; i < mass.Length; i++)
            {
                mass[i] = rand.Next(0, 9);
            }
            Console.WriteLine("Now is:",Perevod(mass[2]));
        }
    }
}
