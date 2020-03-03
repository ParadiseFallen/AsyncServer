using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//Описать базовый класс Человек.
//поля:
//имя
//возраст
//пол
//вес
//методы:
//get set
//отбразить все данные
//гулять???
//Описать класс наследник Ребёнок
//поля:
//количество молочных зубов
//прививочная карта
//методы:
//делать прививку
//показать все данные
//Описать класс наследник Студент
//поля:
//название вуза
//курс
//стипендия
//методы:
//подготовка к сессии
//оплатить экзамен
//создать список объектов классов наследников. Осуществить возможность взаимодействия.
namespace ConsoleApp1
{
    class Program
    {
        static void Main()
        {
            List<People> myList = new List<People> { new Child(), new Student()};
            myList[0].Show();
            Console.WriteLine();
            myList[1].Show();
        }

    }
}
