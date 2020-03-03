#include<iostream>
#include<Windows.h>
#include<time.h>

enum Color {Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White};

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	/*����� 2:������� ������������� ������ �� 20 ���������.
		��������� ������ ���������� ���������� � ��������� �� - 20 �� 20.

		1.����� ����������� ������������� ����� � �������;

	2.����� ������������(������� ����� ���� � ����) ������������� ����� � �������;

	3.����� ������� � �������� � ������� �������, ������������ ���������, ���������� �������������.
		������� ������� ���������� �������� � ���������.

		4. ����� ������� � �������� �� �� ������� � �������� �� �������.������� ��������� ������ �� �����, ���������� ������ ���������� ����� ������.*/

		/*const int size = 20;
		int massiv[size] = {};
		int Ot, Do;
		int min = 21, max = 1, poz, pozz;
		for (int i = 0; i < size; i++)
		{
			massiv[i] = -20 + rand() % 40;
			setColor(Blue, White);
			cout << "[" << i << "] = " << massiv[i] << "\n";
		}
		for (int i = 0; i < size; i++)
		{
			if (min > massiv[i])
			{
				min = massiv[i];
				poz = i;
			}
			if (max < massiv[i])
			{
				max = massiv[i];
				pozz = i;
			}

		}
		setColor(LightRed, Black);
		cout << "������� - " << min << " �� ������� = " << poz << "\n";
		setColor(LightGreen, Black);
		cout << "�������� - " << max << " �� ������� = " << pozz << "\n\n";

		setColor(LightMagenta, Black);
		cout << "� ������� � ";
		cin >> Ot;
		cout << "�� ������� � ";
		cin >> Do;

		int min1 = 21, poz1;
		int max1 = 0, poz2;
		for (int i = Ot; i <= Do; i++)
		{
			if (min1 > massiv[i])
			{
				min1 = massiv[i];
				poz1 = i;
			}
			if (max1 < massiv[i])
			{
				max1 = massiv[i];
				poz2 = i;
			}
		}
		setColor(LightCyan, Black);
		cout << "\n������� - " << min1 << " �� ������� " << poz1 << "\n";
		setColor(DarkGray, Black);
		cout << "�������� - " << max1 << " �� ������� " << poz2 << "\n\n";

		int z = min;
		int x = max;

		for (int i = 0; i < size; i++)
		{
			if (massiv[i] == min)
			{
				setColor(Black, Yellow);
				massiv[i] = x;

			}

			else if (massiv[i] == max)
			{
				setColor(Black, Yellow);
				massiv[i] = z;

			}
			else
			{
				setColor(White, LightBlue);
			}
				cout << "[" << i << "] = " << massiv[i] << "\n";
		}

		setColor(White, Black);
		cout << "\n";*/


		/*5.����� ������� � ����� ���������, �� ������ ����, ������� ������; ������ ���� double*/
	/*const int razmer = 10;
	int massiv_celoe[razmer] = {};
	double massiv_drob[razmer] = {};
	double massiv[razmer] = {};
	double minim = 1;
	int pozic;
	for (int i = 0; i < razmer; i++)
	{
		massiv_celoe[i] = 0 + rand() % 10;//����� �����
		massiv_drob[i] = 1 + rand() % 19;//������� �����
		massiv_drob[i] /= 1000;//0.123
		massiv[i] = massiv_celoe[i] + massiv_drob[i];
		cout << "[" << i << "] = " << massiv[i] << "\n";
		if (minim > massiv_drob[i])
		{
			minim = massiv_drob[i];
			pozic = i;
		}
	}
	setColor(LightMagenta, Black);
	cout << "������� � ����� ��������� ������� ������ �� ������� " << pozic << "\n";
	setColor(White, Black);*/

	//6 * .����� ����������� ������������������ �� ������������� ��������, ����� ������� �����������;
	//const int razmer = 20;
	//double massiv[razmer] = {};
	//int x;
	//int sum = 0;
	//int sum_max = 0;
	//int kol = 0, kol2;

	//
	//for (int i = 0; i < razmer; i++)
	//{
	//	massiv[i] = -20 + rand() % 41;
	//	/*cout << massiv[i] << "\n";*/
	//}
	////massiv[17] = 20, massiv[18] = 20, massiv[19] = 20;
	//for (int i = 0; i < razmer; i++)
	//{
	//	/*massiv[i] = -20 + rand() % 41;*/
	//	cout << massiv[i] << "\n";
	//}
	//int key = 0;
	//for (int i = 0; i < razmer; i++)
	//{
	//	if (massiv[i] >= 0)
	//	{
	//		sum += massiv[i];
	//		kol++;
	//	}
	//	if (massiv[i] < 0 || i == razmer - 1)
	//	{
	//		if (i == razmer - 1)
	//		{
	//			key = 1;
	//		}
	//		if (sum > sum_max)
	//		{
	//			sum_max = sum;
	//			x = i ;
	//			kol2 = kol;
	//		}
	//		sum = 0;
	//		kol = 0;
	//	}
	//}
	//cout << "================================\n";
	//if (key == 1)
	//{
	//	cout << "ASDSAD2\n\n";
	//	for (int i = x - kol2; i < x; i++)
	//	{
	//		cout << massiv[i] << "\n";
	//	}
	//	
	//}
	//else
	//{
	//	for (int i = x - kol2+1; i <= x; i++)
	//	{
	//		cout << massiv[i] << "\n";
	//	}
	//}
	//cout <<"SUMA = "<< sum_max << "\n";

	//7 * .����� ����� ������� ����������� ������������������ ������������� ��������;
	const int razmer = 20;
	double massiv[razmer] = {};
	int x;
	int sum = 0;
	int sum_max = 0;
	int kol = 0, kol2;

	
	for (int i = 0; i < razmer; i++)
	{
		massiv[i] = -20 + rand() % 41;
		cout << massiv[i] << "\n";
	}

	for (int i = 0; i < razmer; i++)
	{
		if (massiv[i] < 0)
		{
			kol++;
		}
		if (massiv[i] > 0)
		{
			x = i;
			kol2 = kol;
		}
		kol = 0;
	}
	cout << "MAX\n";
	for (int i = x - kol2; i < x; i++)
	{
		cout << massiv[i] << "\n";
	}
	system("pause");
}