
#include "iostream"
#include <time.h>
#include "pch.h"
using namespace std;


int main()
{
	enum food_menu {
		Krab_salat = 1, Steyk_govyadina, burger, kola, fanta, voda, sprite
	};
	setlocale(LC_ALL, "RUSSIAN");

	//Меню с едой.
	int f1, f2, f3, f4, f5, f6, f7;
	char inps;

	f1 = 190;
	f2 = 150;
	f3 = 300;
	f4 = 99;
	f5 = 49;
	f6 = 95;
	f7 = 55;


	int number_food;

	bool user = true;

	int cost_zakaz = 0;
	int money;

	while (user = true) {
		cout << "\n Меню \n ";
		cout << "Выберите ваш заказ: \n " << Krab_salat << " - Салат с крабом " << "(" << f1 << ")$" << " \n " << Steyk_govyadina << " - Стейк из говядины  " << "(" << f2 << ")$" << " \n " << burger << " - Бургер  " << "(" << f3 << ")$" << " \n " << kola << " - Кола  " << "(" << f4 << ")$" << " \n " << fanta << " - Фанта  " << "(" << f5 << ")$" << " \n " << voda << " - Вода  " << "(" << f6 << ")$" << " \n " << sprite << " - Спрайт  " << "(" << f7 << ")$" << " \n";
		cout << "Введите номер вашего выбора: ";
		cin >> number_food;


		switch (number_food) {
		case Krab_salat:
			if (money >= f1) {
				cout << "\n Вы выбрали - Салат с крабом  -" << f1 << "$\n";
				cout << "Ваш баланс: " << money - f1 << "$" << endl;
				money = money - f1;
				cost_zakaz = cost_zakaz + f1;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case Steyk_govyadina:
			if (money >= f2) {
				cout << "\n Вы выбрали - Стейк из говядины  -" << f2 << "$\n";
				cout << "Ваш баланс: " << money - f2 << "$" << endl;
				money = money - f2;
				cost_zakaz = cost_zakaz + f2;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case burger:
			if (money >= f3) {
				cout << "\n Вы выбрали - Бургер  -" << f3 << "$\n";
				cout << "Ваш баланс: " << money - f3 << "$" << endl;
				money = money - f3;
				cost_zakaz = cost_zakaz + f3;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case kola:
			if (money >= f4) {
				cout << "\n Вы выбрали - Кола  -" << f4 << "$\n";
				cout << "Ваш баланс: " << money - f4 << "$" << endl;
				money = money - f4;
				cost_zakaz = cost_zakaz + f4;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case fanta:
			if (money >= f5) {
				cout << "\n Вы выбрали - Фанта  -" << f5 << "$\n";
				cout << "Ваш баланс: " << money - f5 << "$" << endl;
				money = money - f5;
				cost_zakaz = cost_zakaz + f5;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case voda:
			if (money >= f6) {
				cout << "\n Вы выбрали - Вода  -" << f6 << "$\n";
				cout << "Ваш баланс: " << money - f6 << "$" << endl;
				money = money - f6;
				cost_zakaz = cost_zakaz + f6;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		case sprite:
			if (money >= f7) {
				cout << "\n Вы выбрали - Спрайт -" << f7 << "$\n";
				cout << "Ваш баланс: " << money - f7 << "$" << endl;
				money = money - f7;
				cost_zakaz = cost_zakaz + f7;
			}
			else {
				cout << "Вы не можете себе позволить это!";
			}
			break;
		default:
			cout << "\n Вы выбрали неправильный заказ \n";
			break;
		}
		cout << "\n Хотите еще что нибудь выбрать?  (y/n): ";
		cin >> inps;

		while ((inps != 'n') && (inps != 'y')) {
			cout << "\n Хотите еще что нибудь выбрать? (y/n) : ";
			cin >> inps;
		}

		if (inps == 'n') {
			cout << "Стоимость вашего заказа: " << cost_zakaz << endl;
			cout << "Спасибо за заказ! \n";
			break;
		}

	}
	system("Pause");
	return 0;
}
