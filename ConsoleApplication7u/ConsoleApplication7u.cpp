// ConsoleApplication7u.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()

{
	setlocale(LC_ALL, "RUSSIAN");
	//2
	for (int i = 0; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}

	//3
	for (int i = 1; i < 10; i++)
	{
		for (int j = 10; j > i; j--)
		{
			cout << i;
		}
		cout << endl;
	}
	//4
	int i, j, g;
	cout << "Высота от 2 до 10: ";
	cin >> g;
	while ((g > 10) || (g < 2))
	{
		cout << " Неправильная высота, введите высоту";
		cin >> g;
	}

	for (i = g; i > 0; i--)
	{
		for (g = 0; g < i; g++)
		{
			cout << " ";
		}
		for (j = 11; j > i; j--)
		{
			cout << i;
		}
		cout << endl;
	}





	return 0;
}



