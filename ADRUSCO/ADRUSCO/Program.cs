using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ADRUSCO
{
    //Программа «Статистика»
    //Подсчитать, сколько раз каждое слово встречается взаданном тексте.
    //Результат записать в коллекцию Dictionary<TKey, TValue>. 
    //Текс использовать из приложения 1.
    //Вывести статистику по тексту в виде таблицы (рисунок 1).
    //Приложение 1.
    //Вот дом, Который построил Джек.
    //А это пшеница,
    //Которая в темном чулане хранится
    //В доме,
    //Который построил Джек.
    //А это веселая птица-синица,
    //Которая часто ворует пшеницу,
    //Которая в темном чулане хранится Вдоме,
    //Который построил Джек.
    
    //Задание 2
    //Изменение свойств объекта класса
    //Создать интерфейс, который уведомляет пользователя программы об изменении значений свойства в классе
    //(в котором реализуется данный интерфейс). 
    //Сигнатура интерфейса:
    //interface IPropertyChanged
    //{
    //event PropertyEventHandler PropertyChanged;
    //}
    //Делегат имеет следующий вид:
    //public delegate void PropertyEventHandler(object sender, PropertyEventArgs e);
    //где, в качестве дополнительного параметра(PropertyEventArgs) выступает имя изменённого свойства.
    //В методе Main() проверить работоспособность созданного интерфейса.
    class Program
    {
        static string[] InList(string b)
        {
            string[] arr = b.Split(new char[] { '!', ',', '.', ' ' }, StringSplitOptions.RemoveEmptyEntries);
            return arr;
        }
        static void Main(string[] args)
        {
            string Text = "Vot dom, Kotoryy postroil Dzhek. A eto pshenitsa, Kotoraya v temnom chulane khranitsya  V dome, Kotoryy postroil Dzhek."
            + "A eto veselaya ptitsa-sinitsa, Kotoraya chasto voruyet pshenitsu,"
            + " Kotoraya v temnom chulane khranitsya Vdome,"
            + "Kotoryy postroil Dzhek.";
            string[] mytext = InList(Text);
            Statistic a = new Statistic(mytext);
            a.Show();
        }
    }
}
