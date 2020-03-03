using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Child : People
    {
        private List<string> VaccinationCard { set; get; }
        private int BabeTeeth;

        public Child():base()
        {
            teeth = 5;
            VaccinationCard = new List<string>();
        }
        public Child(string n, int a, bool s, double w, int t):base(n, a, s, w)
        {
            BabeTeeth = t;
        }
        public override void Show()
        {
            base.Show();
            Console.WriteLine("Зубов-{0}",BabeTeeth);
            foreach (var item in VaccinationCard)
            {
                Console.WriteLine("Прививка-",item);
            }
        }
        public int teeth
        {
            get
            {
                return BabeTeeth;
            }
            set
            {
                if (value>0 && value<28)
                {
                    BabeTeeth = value;
                }
            }
        }

        public override void GoParty()
        {
            Console.WriteLine("Сосать соску");
        }
    }
}
