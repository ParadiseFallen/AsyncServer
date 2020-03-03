using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Student : People
    {
        private string NameVus { get; set; }
        private byte Course;
        private bool Scholarship { get; set; }//стипуха
        public Student() : base()
        {
            NameVus = "PDTU";
            Course = 1;
            Scholarship = true;
        }
        public Student(string vus,byte c,bool stipuxa,string n, int a, bool s, double w) : base(n, a, s, w)
        {
            NameVus = vus;
            Course = c;
            Scholarship = stipuxa;
        }
        public override void GoParty()
        {
            if (Scholarship)
            {
            Console.WriteLine("Бухаем и снова загораем");
            }
            else
            {
                Console.WriteLine("Грустим дома под 'Пошлую Молли'");
            }
        }
        public override void Show()
        {
            base.Show();
            Console.WriteLine("Что за вуз-{0}, Курс-{1}, Стипуха-{2}",NameVus,Course,Scholarship);
        }
        public byte course
        {
            set
            {
                if (value>0 && value<6)
                {
                    Course = value;
                }
                else
                {
                    Course = 1;
                }
            }
            get
            {
                return Course;
            }
        }
        public void Sessia()
        {
            if(Scholarship)
            {
                Console.WriteLine("И так сойдет");
            }
            else
            {
                Console.WriteLine("Проклятье, я должен сдать сессию");
            }
        }
        public void BuyEx()
        {
            if (Scholarship)
            {
                Console.WriteLine("Изи заплачу");
            }
            else
            {
                Console.WriteLine("ЫЫЫЫЫЫЫЫ, проклятье");
            }
        }
    }
}
