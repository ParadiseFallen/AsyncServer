#include <iostream>
#include <Windows.h>
#include <time.h>

enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
enum Direction { Vertikal = 1, Horizontal = 2, Ugol = 3 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(Color text, Color background)
{

	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

using namespace std;


void funk1(int znach)	/*1. Функция принимает в себя число любой разрядности и выводит на экран большую цифру из тех, которые содержаться в числе.*/
{
	int max = 0;
	while (znach!=0)
	{
		if (znach%10>max)
		{
			max = znach % 10;
		}
		znach /= 10;
	}
	cout << "Наибольшая цифра в числе = " << max<<"\n";
}

void func2(int nach,int kon)  /*2. Функция принимает в себя два числа - начало и конец диапазона.Распечатывает все простые числа в этом диапазоне.*/
{
	if (nach<0)
	{
		nach *= -1;
	}
	else if (kon<0)
	{
		kon *= -1;
	}
	else if (kon<nach)
	{
		int vspom;
		vspom=kon;
		kon = nach;
		nach = vspom;
	}

	int vspom2;

	for (size_t i = nach; i < kon; i++)
		
	{
		vspom2 = 0;
		for (size_t j = 2; j < i; j++)
		{
			if (i%j==0)
			{
				vspom2 += 1;
			}
		}

		if (vspom2==0)
		{
			cout << " " << i;
		}

	}
	
}

void func3(int znach) /*3. Функция принимает в себя число.Выводит на экран все делители этого числа.*/
{

	for (size_t i = 1; i <= znach; i++)
	{
		if (znach%i==0)
		{
			cout << i << "\n";
		}
	}

}

void func4(int znach)
{
	int vspom4;
	for (size_t i = znach+1; ; i++)
	{
		vspom4 = 0;
		for (size_t j = 2; j < i; j++)
		{
			if (i%j==0)
			{
				vspom4 += 1;
			}
		}
		if (vspom4==0)
		{
			cout << "Ближайшее справа " << i << "\n";
			break;
		}
	}

	for (size_t i = znach - 1; ; i--)
	{
		vspom4 = 0;
		for (size_t j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				vspom4 += 1;
			}
		}
		if (vspom4 == 0)
		{
			cout << "Ближайшее слева " << i << "\n";
			break;
		}
	}


}

void func6(int znach)
{
	int summ6=0;
	while (znach!=0)
	{
		summ6 += znach % 10;
		znach /= 10;
	}
	cout << "Сумма цифр в числе = " << znach << "\n";
}

void main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));




	/*int znach1;
	cout << " Функция принимает в себя число любой разрядности и выводит на экран большую цифру из тех, которые содержаться в числе \n Введите число\n";
	cin >> znach1;
			funk1(znach1);*/

	/*int znach1, znach2;
	cout << "2. Функция принимает в себя два числа - начало и конец диапазона. Распечатывает все простые числа в этом диапазоне.\n";
		cout << "Введите начало и конец диапазона\n";
	cin >> znach1 >> znach2;
	func2(znach1, znach2);
	*/

	//int znach3;
	//cout << "3. Функция принимает в себя число. Выводит на экран все делители этого числа.\n Введите число\n";
	//cin >> znach3;
	//func3(znach3);


	//int znach4;
	//cout << "4. Функция принимает в себя число. Выводит на экран левое и правое ближайшие простые к нему числа.\n Введите число\n";
	//cin >> znach4;
	//func4(znach4);

	int znach6;
	cout << "Описать функцию, которая принимает в себя число любой рязрядности и выводит на экран сумму цифр в нём\n Введите число\n";
	cin >> znach6;
	func6(znach6);


	system("pause");
}