#include<iostream>
#include<windows.h>//SetConsoleOutputCP 
using namespace std;
void main()
{
	//setlocale(LC_ALL, "rus");

	SetConsoleOutputCP(1251);//����� ���������
	SetConsoleCP(1251);//���� ���������

	//char sOcenk;
	//	cout << "������� ������  ";
	//	cin >> sOcenk;
	//if (sOcenk == 'A' || sOcenk=='a' || sOcenk == '5')//������ ����� ��������� ��� ����������,� ������� ���������� �����������
	//{
	//	cout << "��������\n";
	//}
	//     else if (sOcenk == 'B' || sOcenk == 'b' ||sOcenk == '4')
	//	 {cout << "��������\n"; }
 // 
	//	 else if (sOcenk == 'C' || sOcenk == 'c' || sOcenk == '3')
	//	 {cout << "��������\n"; }

	//	 else if (sOcenk == 'D' || sOcenk == 'd' || sOcenk == '2')
	//	 {cout << "��������\n"; }

	//	 else if (sOcenk == 'E' || sOcenk == 'e' || sOcenk == '1')
	//	 {cout << "����� �����\n"; }
	//	 else {
	//		 cout << "������ ������������ ������\n";
	//	 }


	//int dlin;
	//char tip;
	//double result;

	//cout << "������� ����� � �����������   \n ";
	//cin >> dlin;
	//cout << "�������: m - ��� �������� � ����������\n	M - ��� �������� � �����\n   d - ��� �������� � ���������\n  D - ��� �������� � �����\n   k - ��� �������� � ��������� \n";
	//cin >> tip;
	//	if (tip=='m')
	//	{
	//		result = 10 * dlin;

	//		cout << dlin << "santimetrov eto" << result << " millimetrov";
	//	}
	//	else if (tip=='M')
	//	{
	//		result =  dlin/100;

	//		cout << dlin << "santimetrov eto" << result << " metrov";
	//	}
	//	    else if (tip == 'd')
	//	    {
	//		     result = dlin / 10;
	//			 cout << dlin << "santimetrov eto" << result << " decimetrov";
	//	     }
	//		else if (tip == 'D')
	//		{
	//			result = dlin / 2.54;
	//			cout << dlin << "santimetrov eto" << result << " duimov";
	//		}
	//		else if (tip == 'k')
	//		{
	//			result = dlin / 1000/100;
	//			cout << dlin << "santimetrov eto" << result << " kilometrov";
	//		}
	//		else {
	//			cout << "������ ������������ ������\n";
	//		}

	//char bukva;
	//cout << "����� �� ��������� \n ";
	//cin >> bukva;
	//if (bukva >'A' && bukva <'Z')
	//{
	//	cout << "������� �����\n";
	//}
	//else
	//{
	//	cout << "��������� �����\n";
	//}

	//char bukva2;
	//cout << "������� ����� �� ��������� \n ";
	//cin >> bukva2;

	//cout << "������ ������� ";

	//if (bukva2 >'A' && bukva2 <'Z')
	//{
	//	bukva2 = bukva2 + 'a' - 'A';
	//	cout << "� ����� ��������\n"<<bukva2 << "\n";
	//}
	//else
	//{
	//	bukva2 = bukva2 - 'a' - 'A';
	//		cout << "� ����� ��������\n" << bukva2<<"\n";
	//}

	//int w1, h1, w2, h2, s1, s2;
	//
	//cout << "������� ������ � ������ 1-�� ��������������\n";
	//	cin >> w1>> h1;
	//	cout << "������� ������ � ������ 2-�� ��������������\n";
	//	cin >> w2>>h2;
	//s1 = w1 * h1;
	//s2 = w2 * h2;
	//if (s1 > s2)
	//{
	//	cout << "������� ������� �������������� ������ ��  " << s1 - s2 << " cm2\n";
	//}
	//cout << "������� ������� �������������� ������ ��  " << s2 - s1 << " cm2\n";



//4. ����� ������� �� ��� ����������.���������� ��� �������� - �.�.��� �� ��� ��� ��� �� ��� ����� ���� �����.

//double a4, b4, c4, max4;
//
//cout << "������� ��� ����������: a, b, c\n";
//cin >> a4>> b4>>c4;
//
//if (a4 > b4 && a4 > c4)
//{
//	cout << " ������������ ���������� a =" << a4<<"\n";
//}
//else if (b4 > a4 && b4 > c4)
//{
//	cout << " ������������ ���������� b =" << b4 << "\n";
//}
//else if (c4 > a4 && c4 > b4)
//{
//	cout << " ������������ ���������� c =" << c4 << "\n";
//}
//else if
// �� ���������



// SWITCH

//0. ������������ ������� ����� � ������.
//�� ������� ���� :
//�������
//1 - ��� �������� � �����
//2 - ��� �������� � ����
//3 - ��� �������� � �������
//����� ����� ������� �����������, �������� ���������� �� ��� ����������.
//� ����������� �� ���������� ������, ������� ��������� � ������� :
//... ������ ��� ... (��������� ������)


//double grn;
//int varkurs;
//cout << "������� ����� � ������� \n";
//cin >> grn;
//cout << "������� \n 1 - ��� �������� � ����� \n2 - ��� �������� � ����\n3 - ��� �������� � ������� \n";
//cin >> varkurs;
//
//switch (varkurs)
//{
//case 1:
//	cout << grn<<" ������ ���"<<grn/0.42<<" ������\n";
//	break;
//case 2:
//	cout << grn << " ������ ���" << grn * 1/32 << " ����\n";
//	break;
//case 3:
//	cout << grn << " ������ ���" << grn * 1 / 26 << " ����\n";
//	break;
//
//default: 
//	cout << "������������ ��������\n";
//	break;
//
//
//}
//
//1. �������� ��������� "�����������".������������ ������ ��� ����� � ������ �������������� ��������.
//� ����������� �� ���������� ��������, ����� ������������, ����������, ���������� ��� ��������.� ������ �������, ����������� �������������� ��� ������� ������� �� ����.

double a1, b1;
char simv;

cout << "������� ��� ����� � ������ �������������� ��������   ";
cin >> a1 >> b1 >> simv;
switch (simv)
{
case ('+'):
	cout << "��������� �������� ��������� �����:"<<a1<<"+"<<b1<<"="<<a1+b1<<"\n";
	break;
case ('-'):
	cout << "��������� ��������� ��������� �����:" << a1 << "-" << b1 << "=" << a1 - b1 << "\n";
	break;
default: 
	cout << "����� ���-�� �� ��";
	break;

}


		 system("pause");
}

