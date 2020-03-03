

#include "pch.h"
#include <iostream>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	enum Menu {
		Gam, Pizza, Panini, What, Cola, Shaverma, Shoes

	};
	int number;

	bool user;
	user = true;
	while (user=true) {
		cout << Gam << " - Гамбургер" << endl;
		cout << Pizza << " - Пицца" << endl;
		cout << Panini << " - Панини" << endl;
		cout << What << " - Вяленые пальчики" << endl;
		cout << Cola << " - Кола" << endl;
		cout << Shaverma << " - Шаверма" << endl;
		cout << Shoes << " - Сапог" << endl;
	cout << "Ведите номер блюда:" << endl;
	cin >> number; 

	switch (number)
	{
	case Gam:
		cout <<"Вы выбрали - " << "Гамбургер" << endl;
		cout << "Стоимость заказа: 8" << endl;
		break;
	case Pizza:
		cout << "Вы выбрали - " << "Пиццу" << endl;
		cout << "Стоимость заказа: 15" << endl;
		break;
	case Panini:
		cout << "Вы выбрали - " << "Панини" << endl;
		cout << "Стоимость заказа: 5" << endl;
		break;
	case What:
		cout << "Вы выбрали - " << "Вяленые пальчики" << endl;
		cout << "Стоимость заказа: 100" << endl;
		break;
	case Cola:
		cout << "Вы выбрали - " << "Колу" << endl;
		cout << "Стоимость заказа: 3" << endl;
		break;
	case Shaverma:
		cout << "Вы выбрали - " << "Шаверму" << endl;
		cout << "Стоимость заказа: 50" << endl;
		break;
	case Shoes:
		cout << "Вы выбрали - " << "Сапог" << endl;
		cout << "Стоимость заказа: 20" << endl;
		break;
		
		


	default:
		cout << "Такого в меню нет" << endl;
		break;
		
	}

	char answer;
	cout << "Если вы завершили выбор заказов, то можете выйти из програмы(y / n)" << endl;
	cin >> answer;


	while ((answer = 'y') && (answer = 'n')) {
		break;


	}
	}
	char answer;
	cout << "Если вы завершили выбор заказов, то можете выйти из програмы(y / n)" << endl;
	cin >> answer;


	while ((answer = 'y') && (answer = 'n')) {
		break;
	
	
	}

	return 0;
}



