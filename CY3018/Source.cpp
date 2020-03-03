#include<iostream>
#include<time.h>
#include<Windows.h>

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	/*ЧАСТЬ 1:Описать массив типа double из 20 элементов.
		Заполнить массив случайными значениями в диапазоне от - 20 до 20. Числа должны быть с красивой дробной частью - не больше трёх знаков.

		1.Посчитать сумму всех дробных частей;

	2.Записать в итоговый массив(создать его такого же размера, как и исходный) все элементы, целая часть которых равна 13.
		Вывести итоговый массив на экран - только заполненные элементы;

	3.Записать в итоговый массив(создать его такого же размера, как и исходный) позиции всех элементов, дробная часть которых чётная;*/

	const int size = 20;
	double massiv1[size] = {};
	double massiv1_0[size] = {};
	double massiv1_1[size] = {};
	double sum1 = 0;
	
	for (int i = 0; i < size; i++)
	{
		massiv1_0[i] = -15 + rand() % 30;
		setColor(Yellow ,Black);
			cout << massiv1_0[i] << "\n";
		massiv1_1[i] = 0 + rand() % 101;
		massiv1_1[i] /= 1000;
		setColor(Green, Black);
			cout << massiv1_1[i] << "\n";
			sum1 += massiv1_1[i];
		massiv1[i] = massiv1_0[i] + massiv1_1[i];
	}
	for (int i = 0; i < size; i++)
		{
		setColor(Cyan, Black);
			cout << massiv1[i] << "\t";
		}
	setColor(Magenta, Black);
	cout << "\nсумма всех дробных частей = " << sum1 << "\n";
	
	system("pause");
}