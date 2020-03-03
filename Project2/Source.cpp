#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}

/*Опистаь класс Rectangle, в котором будут следующие поля:
высота
ширина
цвет
координаты начала вывода x,y

Описать следующий набор методов:
0)реализовать булевый метод для проверки корректности введённых данных
1)ввод для каждого поля - ОТДЕЛЬНЫЙ МЕТОД ДЛЯ КАЖДОГО ПОЛЯ!! Реализовать проверки на корректность введённых значений
2)установка значений в поле - в методе должна быть проверка корректности устанавливаемого значения
3)возвращение значения поля
4)отображение прямоугольника с указанными параметрами на указанных координатах
5)реализовать метод, отвечающий за смещение прямоугольника на одну единицу вверх/вниз/влево/вправо. Это ОДИН метод.
6)реализовать метод, отвечающий за перемещение прямоугольника по консоли - тут будет в цикле вызываться метод для смещения.*/

class Rectangle1
{
	int height, weight, x, y;
	Color cvet;

public:

	void inputHeight()
	{
		int h;
		do
		{
			cout << "Enter height : ";
			cin >> h;
		} while (inputCheck(h) == false);
		setHeight(h);
	}
	void inputWeight()
	{
		int w;
		do
		{
			cout << "Enter weight : ";
			cin >> w;
		} while (inputCheck(w) == false);
		setWeight(w);
	}
	void inputX()
	{
		int Cordx;
		do
		{
			cout << "Enter x cordinate : ";
			cin >> Cordx;
		} while (inputCheck(Cordx) == false);
		setX(Cordx);
	}
	void inputY()
	{
		int Cordy;
		do
		{
			cout << "Enter y cordinate : ";
			cin >> Cordy;
		} while (inputCheck(Cordy) == false);
		setY(Cordy);
	}
	void inputColor()
	{
		int color;
		do
		{
			cout << "Enter color (1 - Blue, 2 - Green, 3 - Cyan, 4 - Red, 5 - Purple ) : ";
			cin >> color;
		} while (inputCheck(color) == false);
		setcolor(color);
	}
	bool inputCheck(int Check)
	{
		if (Check < 1 || Check > 5)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	void setHeight(int h)
	{
		height = h;
	}
	void setWeight(int w)
	{
		weight = w;
	}
	void setX(int Cordw)
	{
		x = Cordw;
	}
	void setY(int Cordy)
	{
		y = Cordy;
	}
	void setcolor(int color)
	{
		cvet = (Color)color;
	}

	int GetHeight()
	{
		return height;
	}
	int GetWeight()
	{
		return weight;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	Color GetColor()
	{
		return cvet;
	}

	void ShowObj()
	{
		int Ycheck = y;
		for (size_t i = 0; i < height; i++)
		{
			SetColor(cvet, cvet);
			SetCursor(x, Ycheck);
			for (size_t j = 0; j < weight; j++)
			{
				cout << "#";
			}
			Ycheck++;
		}
		cout << "\n";
	}
	void Move()
	{
		int i_input;
		Color ColorCheck = cvet;

		i_input = _getch();//функция возвращает код нажатой клавиши
		switch (i_input)
		{
		case 72://вверх
		{
			if (y < 2)
			{
				cvet = (Color)arr[0][x];
				ReGenerateUpAndCoutIt();
				ShowObj();
				break;
			}
			else
			{
				cvet = (Color)0;
				ShowObj();//отрисовываем объект на  старых координатах цветом фона
				y--;
			}
			cvet = (Color)ColorCheck;
			ShowObj();//отрисовка объекта на новых координатах

		} break;
		case 80://вниз
		{
			if (y > 18-height)
			{
				cvet = (Color)arr[19][x];
				ReGenerateDownAndCoutIt();
				ShowObj();
				break;
			}
			else
			{
				cvet = (Color)0;
				ShowObj();
				y++;
			}
			cvet = (Color)ColorCheck;
			ShowObj();
		} break;
		case 75://влево
		{
			if (x < 2)
			{
				cvet = (Color)Left;
				ReGenerateLeftAndCout();
				ShowObj();
				break;
			}
			else
			{
				cvet = (Color)0;
				ShowObj();
				x--;
			}
			cvet = (Color)ColorCheck;
			ShowObj();
		}break;
		case 77://вправо
		{
			if (x > 38-weight)
			{
				cvet = (Color)Right;
				ReGenerateRightAndCout();
				ShowObj();
				break;
			}
			else
			{
				cvet = (Color)0;
				ShowObj();
				x++;
			}
			cvet = (Color)ColorCheck;
			ShowObj();
		}break;
		}
	}
	void MoveCycle()
	{
		do
		{
			Move();
		} while (true);
	}

	private :

	int arr[20][40]; // Массива поля
	int Down = 1 + rand() % 9;
	int Up = 1 + rand() % 9;
	int Right = 1 + rand() % 9;
	int Left = 1 + rand() % 9;

	public:

	void MakeAGlass()
	{
		for (size_t i = 0; i < 20; i++)
		{
			for (size_t j = 0; j < 40; j++)
			{
				if (j==0)
				{
					arr[i][j] = Left;
				}
				else if (j==39)
				{
					arr[i][j] = Right;
				}
				else if(j!=0 && j!=39 && i == 0)
				{
					arr[i][j] = Up;
				}
				else if (j != 0 && j != 39 && i == 19)
				{
					arr[i][j] = Down;
				}
				else
				{
					arr[i][j] = 0;
				}
			}
		}
	}

	void ShowGlass()
	{
		SetCursor(0, 0);
		for (size_t i = 0; i < 20; i++)
		{
			for (size_t j = 0; j < 40; j++)
			{
				SetColor((Color)arr[i][j], (Color)arr[i][j]);
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}

	void ReGenerateDownAndCoutIt()
	{
		Down = 1 + rand() % 9;
		for (size_t j = 0; j < 39; j++)
		{
			if (j!=0 && j!=39)
			{
				SetColor((Color)Down, (Color)Down);
				SetCursor(j, 19);
				arr[19][j] = Down;
				cout << arr[19][j];
			}
		}
	}

	void ReGenerateUpAndCoutIt()
	{
		Up = 1 + rand() % 9;
		for (size_t j = 0; j < 39; j++)
		{
			if (j != 0 && j != 39)
			{
				SetColor((Color)Up, (Color)Up);
				SetCursor(j, 0);
				arr[0][j] = Up;
				cout << arr[0][j];
			}
		}
	}

	void ReGenerateLeftAndCout()
	{
		Left = 1 + rand() % 9;
		for (size_t i = 0; i < 20; i++)
		{
				SetColor((Color)Left, (Color)Left);
				SetCursor(0, i);
				arr[i][0] = Up;
				cout << arr[i][0];
		}
	}

	void ReGenerateRightAndCout()
	{
		Right = 1 + rand() % 9;
		for (size_t i = 0; i < 20; i++)
		{
			SetColor((Color)Right, (Color)Right);
			SetCursor(39, i);
			arr[i][39] = Up;
			cout << arr[i][39];
		}
	}
};

void main()
{
	srand(time(NULL));
	Rectangle1 rect;
	rect.inputHeight();
	rect.inputWeight();
	rect.inputX();
	rect.inputY();
	rect.inputColor();
	system("cls");
	rect.ShowObj();
	rect.MakeAGlass();
	rect.ShowGlass();
	rect.MoveCycle();
}