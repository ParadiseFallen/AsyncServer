using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ANDRUSCO
{
    abstract internal class Alive
    {
        protected internal Int32 X { get; set; }
        protected internal Int32 Y { get; set; }
        protected internal Boolean Live { get; set; }
        protected internal ConsoleColor ColorSimbol { set; get; }
        protected internal Char Simbol { get;set; }
        protected internal Int32 CounterLive {get;set; }
        public void GoDie()
        {
            Live = false;
        }
        public virtual void Eat() { }
        protected internal Alive( Int32 KX, Int32 KY)
        {
            X = KX;
            Y = KY;
            CounterLive = 0;
            Live = true;
        }
        public void Show()
        {
            Console.SetCursorPosition(X,Y);
            ConsoleColor buf = Console.ForegroundColor;
            Console.ForegroundColor = ColorSimbol;
            Console.Write("{0}",Simbol);
            Console.ForegroundColor = buf;
        }
    }

}
