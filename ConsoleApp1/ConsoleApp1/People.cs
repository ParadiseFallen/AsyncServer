using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class People
    {
        public string Name { get; private set; }
        private int Age;
        public bool Sex { get; private set; }
        private double Weight;

        public People()
        {
            Name = "Jopa";
            age = 10;
            Sex = false;
            weight = 10;
        }
        public People(string n, int a, bool s, double w)
        {
            Name = n;
            age = a;
            Sex = s;
            weight = w;
        }

        public int age
        {
            get
            {
                return Age;
            }
            set
            {
                if (value < 100 && value>0)
                {
                    Age = value;
                }
                else
                {
                    age = 1;
                }
            }
        }
        public double weight
        {
            get
            {
                return Weight;
            }
            set
            {
                if (value < 350 && value>0)
                {
                    Weight = value;
                }
                else
                {
                    Weight = 50;
                }
            }
        }

        public virtual void Show()
        {
            Console.WriteLine(" Имя-{0}, Возраст-{1}, Пол-{2}, Вес-{3}", Name, this.age, Sex, this.weight);
        }
        public virtual void GoParty()
        {

        }
    }
}
