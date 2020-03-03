#include <iostream>
#include <Windows.h>
#include<conio.h>
#include <time.h>
using namespace  std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, escepushka = 27 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}

void showRectangle(int pozX, int pozY, Color myColor)
{
	SetColor(myColor, myColor);
	for (size_t i = 0; i < 10; i++)
	{
		SetCursor(pozX, pozY + i);
		for (size_t j = 0; j < 5; j++)
		{
			cout << "+";
		}
	}
}

void granni_okna(Color up, Color down, Color left, Color right)
{
	int X = 25, Y = 160;
	SetCursor(0, 0);

	for (size_t i = 0; i < X; i++)
	{
		for (size_t j = 0; j < Y; j++)
		{
			if (i == 0)
			{
				SetColor(up, up);
				cout << " ";
			}
			else if (i == X - 1)
			{
				SetColor(down, down);
				cout << " ";
			}
			else if (j == 0 || j == 1)
			{
				SetColor(left, left);
				cout << " ";
			}
			else if (j == Y - 1 || j == Y - 2)
			{
				SetColor(right, right);
				cout << " ";
			}
			else
			{
				SetColor(Black, Black);
				cout << " ";
			}
		}

	}
	SetColor(Black, Black);
}





void main()
{
	srand(time(NULL));
	setlocale(0, "");
	int pozX = 15, pozY = 12;
	for (size_t i = 0; i < 10; i++)
	{
		SetCursor(pozX, pozY + i);
		for (size_t j = 0; j < 5; j++)
		{
			cout << "+";
		}
	}
	Color up = (Color)(1 + rand() % 15), down = (Color)(1 + rand() % 15), left = (Color)(1 + rand() % 15), right = (Color)(1 + rand() % 15);
	int poz;
	Color color = Red;

	granni_okna(up, down, left, right);
	do
	{
		poz = _getch();//возращает код нажатой клавиши
		showRectangle(pozX, pozY, Black);
		switch (poz)
		{
		case Left:
			if (pozX == 2)
			{
				left = (Color)(1 + rand() % 15);
				granni_okna(up, down, left, right);
				break;
			}

			color = Red;
			pozX--;
			break;
		case Right:
			if (pozX == 152)
			{
				right = (Color)(1 + rand() % 15);
				granni_okna(up, down, left, right);
				break;
			}
			color = Yellow;
			pozX++;
			break;
		case Down:
			if (pozY == 14)
			{
				down = (Color)(1 + rand() % 15);
				granni_okna(up, down, left, right);
				break;
			}
			pozY++;
			break;
		case Up:
			if (pozY == 1)
			{
				up = (Color)(1 + rand() % 15);
				granni_okna(up, down, left, right);
				break;
			}
			pozY--;
			break;
		default:
			break;
		}

		showRectangle(pozX, pozY, color);
	} while (poz != escepushka);//пока не нажали Esc

	SetColor(White, Black);
	cout << "\n";
	system("pause");
}