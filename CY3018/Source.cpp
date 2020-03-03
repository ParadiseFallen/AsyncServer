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

	/*����� 1:������� ������ ���� double �� 20 ���������.
		��������� ������ ���������� ���������� � ��������� �� - 20 �� 20. ����� ������ ���� � �������� ������� ������ - �� ������ ��� ������.

		1.��������� ����� ���� ������� ������;

	2.�������� � �������� ������(������� ��� ������ �� �������, ��� � ��������) ��� ��������, ����� ����� ������� ����� 13.
		������� �������� ������ �� ����� - ������ ����������� ��������;

	3.�������� � �������� ������(������� ��� ������ �� �������, ��� � ��������) ������� ���� ���������, ������� ����� ������� ������;*/

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
	cout << "\n����� ���� ������� ������ = " << sum1 << "\n";
	
	system("pause");
}