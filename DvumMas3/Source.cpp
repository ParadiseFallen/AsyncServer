#include<iostream>
#include<time.h>
#include <windows.h>//GetStdHandle
using namespace std;
enum Color { Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//�������� ���������� ��������� ����
void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


//3. ������� �������, ������� ��������� � ���� ��� �����(double) � ������ �������������� ��������.
//������� ������� �� ����� ��������� ���������� ������ ��������.(�����������)



//4. ������� �������.������� ��������� � ���� ����� ������, ������, 
//�����������(�����������, �������������, ��� ����� 45) � ����.





void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

		/*������� ��������� ������������� ������ 4 ������ �� 6 ��������.
		��������� ��� ���������� ���������� � ���������������� ���������.

		1. ����� ������, � ������� ������ ����� ���������� �����.
		2. ����� ������, � ������� ���������� ���������� ������ ��������.
		3. ����� ������, ������� �������������� ������������� �������� ��� ������� ����������.
*/

	const int row = 4, col = 6;
	int mas[row][col];

	int Start, End, min = mas[0][0], max = mas[0][0], pozmin = 0, pozmax = 0, kol = 0, sum = 0;

	cout << " ������� ����� ��� ������ ��������� ... \n";
	cin >> Start;
	cout << " ������� �������� ����� ��������� ... \n";
	cin >> End;

	int z = 0;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			mas[i][j] = Start + rand() % End + 1;
			
			
		}
	}
	
	//1. ����� ������, � ������� ������ ����� ���������� �����.
	/*for (size_t i = 0; i < row; i++)
	{
		min = mas[i][0];
		max = mas[i][0];
		for (size_t j = 0; j < col; j++)
		{
		if (mas[i][j] > min)
		{
			min = mas[i][j];
			pozmin = i;
		}
			else if (mas[i][j] < max)
		{
			max = mas[i][j];
			pozmax = i;
		}
			sum += mas[i][0];
			
		}
		cout << "[" << i << "]\t" << sum << "\n";
	}
	cout << " max sum row = " << sum << "\n";
*/
	//2. ����� ������, � ������� ���������� ���������� ������ ��������.

	/*min = mas[0][0];
	max = mas[0][0];
	sum = 0;
	pozmin = 0;
	pozmax = 0;
	for (size_t i = 0; i < row; i++)
	{
		min = mas[i][0];
		max = mas[i][0];
		for (size_t j = 0; j < col; j++)
		{
			if (mas[i][j] > min && mas[i][j] % 2 == 0)
			{
				min = mas[i][j];
				pozmin = i;
			}
			else if (mas[i][j] < max && mas[i][j] % 2 == 0)
			{
				max = mas[i][j];
				pozmax = i;
			}
			kol += mas[i][0];
		}
		cout << "[" << i << "]" << kol << "\n";
	}
	cout << " max kol = " << kol << "\n";
*/
	//3. ����� ������, ������� �������������� ������������� �������� ��� ������� ����������.
	sum = 0;
	kol = 0;
	min = mas[0][0];
	max = mas[0][0];
	pozmin = 0;
	pozmax = 0;
	
	for (size_t i = 0; i < row; i++)
	{
		min = mas[i][0];
		max = mas[i][0];
		for (size_t j = 0; j < col; j++)
		{
			if (mas[i][j] < min && min < 0)
			{
				min = mas[i][j];
				pozmin = i;
			}
			else if (mas[i][j] > max && max < 0)
			{
				max = mas[i][j];
				pozmax = j;
			}
			
			kol++;
			sum += mas[i][0];
			
			
		}
		
		
	}
		if (kol < 0)
		{
			cout << " avg = " << sum / kol << "\n";
		}
		else
		{
			cout << " �������� �� ������� \n";
		}




	system("pause");
}