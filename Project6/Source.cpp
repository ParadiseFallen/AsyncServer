#include <Windows.h>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;




//1. Написать функцию, определяющую четное или нет переданное ей число.
//2. Написать функцию, определяющую простое или нет переданное ей число.
//3. Написать функцию, принимающую в качестве параметра номер года и определяющую високосный год или нет.
//4. Написать функцию, принимающую 2 аргумента - число и предполагаемое кол - во разрядов в нем.Функция должна определять, 
//правильно ли указано кол - во разрядов.Например,isDigitsCountCoincides(10, 2) должна вернуть true, потому что в числе 10 2 разряда;
//isDigitsCountCoincides(100, 2) должна вернуть false, потому что в числе 100 3 разряда.


// проверка на четность
bool evenNumm(int numm)
{

	if (numm % 2 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//проверка на простое число
bool easyNumm(int numm)
{
	if (numm == 2 || numm == 1)
	{
		return false;
	}
	for (int i = 2; i < sqrt(numm); i++)
	{
		if (numm % i == 0)
		{
			return false;
		}

	}
	return true;

}

bool lofr



void main()
{

	int numm;

	//проверка для 1 задания.
	/*cin >> numm;
	evenNumm(numm);
	cout << evenNumm(numm) << endl;*/

	//проверка для 2 задания.
	/*cin >> numm;
	easyNumm(numm);
	cout << easyNumm(numm) << endl;*/



	system("pause");
}