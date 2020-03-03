// ConsoleApplication7taerttt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//ЗАДАНИЕ
//Использовать перечисление enum
//Использовать switch
//7 продуктов
// вывести пользователю подсказку
// в виде
// 1 - ПИЦЦА
// 2 - ГАМБУРГЕР
// Введите ваш выбор: 2
// Вы выбрали гамбургер
//СУММА заказа: 40,55 грн


#include "pch.h"
#include <iostream>
using namespace std;
enum Products { PIZZA, Colla, Gamburger, EXIT };

int main()
{
	cout << PIZZA << "- PiZZA" << endl;
	cout << Colla << "- Colla" << endl;
	cout << Gamburger << "- Gamburger" << endl;
	cout << EXIT << "- EXIT" << endl;
	int eda;
	double som = 0;
	bool ok;
	ok = true;
	while (ok)
	{


		cout << "viberi edy " << endl;
		cin >> eda;

		switch (eda) {
		case PIZZA:
			cout << "Wi wibrali pizzy" << endl;
			som = som + 44.88;
			break;
		
		case Colla:
			cout << "Wi wibrali Colla" << endl;
			som = som + 22.80;
			break;

		case Gamburger:
			cout << "Wi wibrali Gamburger" << endl;
			som = som + 99.68;
			break;

		case EXIT:
			ok = false;
		
			break;
		
		default:
			cout << "TAKOGO NEMA" << endl;
			break;
		}
	}
	cout << "Cymma Zakaza :"<< som << endl;







}


