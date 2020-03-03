using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ADRUSCO
{
    class Statistic
    {
        public Dictionary<string,int> Collection { get; set;}
        public Statistic()
        {
            Collection = new Dictionary<string,int>();
        }
        public Statistic(string[] a)
        {
            Collection = new Dictionary<string, int>();
            for(int i=0; i<a.Count();i++)
            {
                if(!Collection.ContainsKey(a[i]))
                {
                Collection.Add(a[i],1);
                }
                else
                {
                    Collection[a[i]]++;
                }
                
            }
        }
        public void Show()
        {
            foreach (var item in Collection)
            {
                Console.WriteLine(" name-{0},how-{1}",item.Value,item.Key);
            }
        }
    }
}
