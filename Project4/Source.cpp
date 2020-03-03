#include<iostream>
#include<Windows.h>
#include<time.h>


enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	//	for (int i = 0; i <= 10; i++)
	//	{
	//
	//		SetColor(Black, Yellow);
	//		cout << i<< "\t";
	//
	//		for (int j = 1; j <= 10; j++)
	//		{
	//			if (i == 0)
	//			{
	//				SetColor(Black, Yellow);
	//				cout << j << "\t";
	//			}
	//			else
	//			{
	//				SetColor(White, Black);
	//				cout << j * i;
	//
	//					cout << "\t";
	//			}
	//		}
	//		cout << endl;
	//	}
	////1. Нарисовать красный квадрат с одинокой жёлтой точкой в центре.
	//	//Пользователь задаёт высоту и ширину.
	//	int h, w;
	//	cin >> h >> w;
	//
	//	if (h <= 0 || w <= 0)
	//	{
	//		cout << "Высота или ширина равна нулю \n";
	//	}
	//	else
	//	{
	//		if (h % 2 == 0 || w % 2 == 0)
	//		{
	//			if (h % 2 == 0)
	//			{
	//				h++;
	//			}
	//			else if (w % 2 == 0)
	//			{
	//				w++;
	//			}
	//		}
	//	
	//			for (int i = 1; i <= h; i++)
	//			{
	//				for (int j = 1; j <= w; j++)//на каждой итерации внешнего цикла вложенный сделает 5 итераций
	//				{
	//					if (h / 2 + 1 == i && w / 2 + 1 == j)
	//					{
	//						SetColor(Red, Yellow);
	//						cout << "  ";
	//					}
	//					else
	//					{
	//						SetColor(Black, Red);
	//						cout << "  ";
	//					}
	//				}
	//				SetColor(White, Black);
	//				cout << "\n";
	//			}
	//	}
	////2. Нарисовать прямоугольник - обводка одного цвета,	
	//	//заливка другого. Пользователь задаёт высоту-ширину.
	//
	//	cin >> h >> w;
	//	for (int i = 1; i <= h; i++)
	//	{	
	//		for (int j = 1; j <= w; j++)
	//		{
	//			if (i % 2 == 0)
	//			{
	//				SetColor(Black, Yellow);
	//				cout << " ";
	//			}
	//			else
	//			{
	//				SetColor(Black, Magenta);
	//				cout << " ";
	//			}
	//			
	//		}
	//		cout << "\n";
	//	}
	//	SetColor(White, Black);

	/*4. Нарисовать прямоугольник с концентрическими обводками разного цвета.
	Цвет обводки генерируем случайным образом.Рядом не могут находиться две обводки одного цвета.*/

	int h = 15, w = 15;
	int imin = 1, imax = h;
	int jmin = 1, jmax = w;

	int color;

	
	color = rand() % 16;
	for (int i = 1; i <= h; i++)
	{
		color = rand() % 16;

		for (int j = 1; j <= w; j++)
		{
			if (i == imin || i == imax)
			{
				SetColor(Black, (Color)color);
				cout << "i=" << i;
			}
			else if (j == jmax || j ==jmin)
			{
				SetColor(Black, (Color)color);
				cout << "i=" << i;
			}
			/*if (i == imin || i == imax)
			{
				SetColor(Black, (Color)color);
				cout <<"i="<< i;
			}*/
			
		/*	else if (j == jmin || j == jmax)
			{
				SetColor(Black, (Color)color);
				cout <<"j="<<j;
			}*/
		}
		
		imin++;
		imax--;
		jmin++;
		jmax--;
		
		
		cout << "\n";
	}



	system("pause");
}