#include <Windows.h>
#include<iostream>
#include<string>
#include<conio.h>

using namespace std;




//1. �������� �������, ������������ ������ ��� ��� ���������� �� �����.
//2. �������� �������, ������������ ������� ��� ��� ���������� �� �����.
//3. �������� �������, ����������� � �������� ��������� ����� ���� � ������������ ���������� ��� ��� ���.
//4. �������� �������, ����������� 2 ��������� - ����� � �������������� ��� - �� �������� � ���.������� ������ ����������, 
//��������� �� ������� ��� - �� ��������.��������,isDigitsCountCoincides(10, 2) ������ ������� true, ������ ��� � ����� 10 2 �������;
//isDigitsCountCoincides(100, 2) ������ ������� false, ������ ��� � ����� 100 3 �������.


// �������� �� ��������
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

//�������� �� ������� �����
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

	//�������� ��� 1 �������.
	/*cin >> numm;
	evenNumm(numm);
	cout << evenNumm(numm) << endl;*/

	//�������� ��� 2 �������.
	/*cin >> numm;
	easyNumm(numm);
	cout << easyNumm(numm) << endl;*/



	system("pause");
}