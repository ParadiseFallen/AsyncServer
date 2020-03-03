using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ANDRUSCO
{
    class Grass : Alive
    {
        public Grass(Int32 KX, Int32 KY) : base(KX, KY)
        {
            ColorSimbol = ConsoleColor.Green;
            Simbol = '|';
        }
    }
}
