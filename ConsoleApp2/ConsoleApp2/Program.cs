using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            Func<int, bool>[] g = new Func<int, bool>[] { fun };     
        }

        static bool fun(int numb)
        {
            for (int i = 2; i <= numb; i++)
                if (numb % i == 0)
                    return false;
            return true;
        }
        static bool fun2(int numb)
        {
            int chek=0;
            do
            {
                chek++;
                numb /= 10;
            } while (numb > 0);
            if (chek == 3)
                return true;
            return false;
        }
        static bool fun3(int numb)
        {
            string arr = numb.ToString();
            if (arr.Contains("0") || arr.Contains("6") || arr.Contains("8") || arr.Contains("9"))
                return true;
            return false;
        }
        static bool fun4(int numb)
        {
            string arr = numb.ToString();
            char[]array = arr.ToCharArray();
            Array.Reverse(array);
            String rev = new string(array);
            if(array.Equals(arr))
        }
    }
}
