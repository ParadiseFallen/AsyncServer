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


void funk1(int znach)	/*1. ������� ��������� � ���� ����� ����� ����������� � ������� �� ����� ������� ����� �� ���, ������� ����������� � �����.*/
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
	cout << "���������� ����� � ����� = " << max<<"\n";
}

void func2(int nach,int kon)  /*2. ������� ��������� � ���� ��� ����� - ������ � ����� ���������.������������� ��� ������� ����� � ���� ���������.*/
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

void func3(int znach) /*3. ������� ��������� � ���� �����.������� �� ����� ��� �������� ����� �����.*/
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
			cout << "��������� ������ " << i << "\n";
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
			cout << "��������� ����� " << i << "\n";
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
	cout << "����� ���� � ����� = " << znach << "\n";
}

void main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));




	/*int znach1;
	cout << " ������� ��������� � ���� ����� ����� ����������� � ������� �� ����� ������� ����� �� ���, ������� ����������� � ����� \n ������� �����\n";
	cin >> znach1;
			funk1(znach1);*/

	/*int znach1, znach2;
	cout << "2. ������� ��������� � ���� ��� ����� - ������ � ����� ���������. ������������� ��� ������� ����� � ���� ���������.\n";
		cout << "������� ������ � ����� ���������\n";
	cin >> znach1 >> znach2;
	func2(znach1, znach2);
	*/

	//int znach3;
	//cout << "3. ������� ��������� � ���� �����. ������� �� ����� ��� �������� ����� �����.\n ������� �����\n";
	//cin >> znach3;
	//func3(znach3);


	//int znach4;
	//cout << "4. ������� ��������� � ���� �����. ������� �� ����� ����� � ������ ��������� ������� � ���� �����.\n ������� �����\n";
	//cin >> znach4;
	//func4(znach4);

	int znach6;
	cout << "������� �������, ������� ��������� � ���� ����� ����� ����������� � ������� �� ����� ����� ���� � ��\n ������� �����\n";
	cin >> znach6;
	func6(znach6);


	system("pause");
}