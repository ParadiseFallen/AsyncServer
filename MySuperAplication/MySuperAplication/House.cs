using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MySuperAplication
{
    class House
    {
        private Basement MyBasement;
        private Walls[] MyWalls;
        private Door MyDoor;
        private Window[] MyWindow;
        private Roof MyRoof;
        bool IsEnd;
        public House()
        {
            MyBasement = new Basement();
            MyWalls = new Walls[4];
            for (int i = 0; i < MyWalls.Count(); i++)
            {
                MyWalls[i] = new Walls();
            }
            MyDoor = new Door();
            MyWindow = new Window[4];
            for (int i = 0; i < MyWalls.Count(); i++)
            {
                MyWindow[i] = new Window();
            }
            MyRoof = new Roof();
            IsEnd = false;
        }
    }
}
