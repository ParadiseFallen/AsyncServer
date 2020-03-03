using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ANDRUSCO
{
    internal sealed class Rabbyt : Alive
    {
        public Rabbyt(Int32 KX, Int32 KY) : base(KX, KY)
        {
            ColorSimbol =ConsoleColor.White;
            Simbol ='R';
        }
    }
}
