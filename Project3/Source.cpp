#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include <iostream>
#include <Windows.h>
#include<time.h>
#include <conio.h>//getch
#include <string.h>
using namespace  std;

enum Keys { Left = 75, Right = 77, Esc = 27, Up = 72, Down = 80 };
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

const int FIGURE_HEIGHT = 4;
const int FIGURE_WIDTH = 4;
const int FIGURE_COUNT = 7;

const int figure1[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure2[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,1,0 },{ 1,0,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure3[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,1,0 },{ 0,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure4[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,0,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure5[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,0,0 },{ 0,1,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure6[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 1,1,1,0 },{ 0,0,1,0 },{ 0,0,0,0 },{ 0,0,0,0 } };
const int figure7[FIGURE_HEIGHT][FIGURE_WIDTH] = { { 0,1,1,0 },{ 1,1,0,0 },{ 0,0,0,0 },{ 0,0,0,0 } };

int col = 40, row = 40;
int xCord = 10;
int yCord = 0;

struct FIGURE
{
	int value[FIGURE_HEIGHT][FIGURE_WIDTH];
	int height;//Высота
	int width;//Ширина
	Color color;
};

struct ITEM_INFO
{
	//int oldX;//Ширина
	//int oldY;//Высота
	int x;//Ширина
	int y;//Высота
	int type;
	FIGURE itemFigure;
};

FIGURE figuresArr[FIGURE_COUNT];
ITEM_INFO item;

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//структура для хранения координат
	SetConsoleCursorPosition(hStdOut, myCoords);//функция позиционирует курсор на окне консоли
}

void drawItem(Color color = LightGray)
{
	for (size_t i = 0; i < FIGURE_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIGURE_WIDTH * 2; j++)
		{
			if (item.itemFigure.value[i][j / 2])
			{
				SetCursor(item.x + j, item.y + i);
				SetColor(LightGray, color);
				cout << " ";
				SetColor(LightGray, Black);
				SetCursor(200, 200);
			}
		}
	}
}

bool checkMove(ITEM_INFO info, int x, int y)
{

	if (x - xCord == 0 || x - xCord == 1 || (x - xCord) + (info.itemFigure.width * 2) == col || (x - xCord) + (info.itemFigure.width * 2) == col - 1)
	{
		return false;
	}

	if (y - col == 0)
	{

	}

	drawItem();
	return true;

}

void setConsole(int width, int height)
{
	HWND hwnd;
	char Title[1024];
	SetConsoleTitle("Pyreshka");
	GetConsoleTitle(Title, 1024); // Узнаем имя окна
	hwnd = FindWindow(NULL, Title); // Узнаем hwnd окна
	MoveWindow(hwnd, 0, 0, width, height, TRUE);//xnew,ynew,wnew,hnew -новые положение x,y, ширина и высота
	CONSOLE_CURSOR_INFO cursor = { 100, false };//число от 1 до 100 размер курсора в процентах; false\true - видимость
	SetConsoleCursorInfo(hStdOut, &cursor);//применение заданных параметров курсора
}


//Выяснение фактической ширины и высоты фигуры.
void getItemValues(FIGURE *ItemFigure)
{
	int width = 0;
	int height = 0;

	for (int i = 0; i < FIGURE_HEIGHT; i++)
	{
		for (int j = 0; j < FIGURE_WIDTH; j++)
		{
			if (ItemFigure->value[i][j] != 0)
			{
				height++;
				break;
			}
		}
	}


	for (int j = 0; j < FIGURE_HEIGHT; j++)
	{
		for (int i = 0; i < FIGURE_WIDTH; i++)
		{
			if (ItemFigure->value[i][j] != 0)
			{
				width++;
				break;
			}
		}
	}

	ItemFigure->width = width;
	ItemFigure->height = height;
}


bool checkEmptySpace(ITEM_INFO info)
{
	bool tmp = 0;
	for (int i = 0; i < FIGURE_HEIGHT; i++)
	{
		if (info.itemFigure.value[i][0] > tmp)
		{
			tmp = info.itemFigure.value[i][0];
		}
	}

	return tmp;
}

bool checkEmptySpace1(ITEM_INFO info)
{
	bool tmp = 0;
	for (int i = 0; i < FIGURE_WIDTH; i++)
	{
		if (info.itemFigure.value[0][i] > tmp)
		{
			tmp = info.itemFigure.value[0][i];
		}
	}

	return tmp;
}


void rotateItem()
{
	ITEM_INFO tempItem = item;
	int temp[FIGURE_HEIGHT][FIGURE_WIDTH];

	for (int i = 0; i < FIGURE_HEIGHT; i++)
	{
		for (int j = 0; j < FIGURE_WIDTH; j++)
		{
			temp[i][j] = tempItem.itemFigure.value[j][(FIGURE_HEIGHT - 1) - i];
		}
	}
	for (int i = 0; i < FIGURE_HEIGHT; i++)
	{
		for (int j = 0; j < FIGURE_WIDTH; j++)
		{
			tempItem.itemFigure.value[i][j] = temp[i][j];
			temp[i][j] = 0;
		}
	}
	while (!checkEmptySpace(tempItem))
	{
		for (int i = 0; i < FIGURE_HEIGHT; i++)
		{
			for (int j = 0; j < FIGURE_WIDTH; j++)
			{
				if (tempItem.itemFigure.value[i][j] == 1)
				{
					temp[i][j - 1] = tempItem.itemFigure.value[i][j];
				}
			}
		}

		for (int i = 0; i < FIGURE_HEIGHT; i++)
			for (int j = 0; j < FIGURE_WIDTH; j++)
			{
				tempItem.itemFigure.value[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
	}

	while (!checkEmptySpace1(tempItem))
	{
		for (int i = 0; i < FIGURE_HEIGHT; i++)
		{
			for (int j = 0; j < FIGURE_WIDTH; j++)
			{
				if (tempItem.itemFigure.value[i][j] == 1)
				{
					temp[i - 1][j] = tempItem.itemFigure.value[i][j];
				}
			}
		}

		for (int i = 0; i < FIGURE_HEIGHT; i++)
			for (int j = 0; j < FIGURE_WIDTH; j++)
			{
				tempItem.itemFigure.value[i][j] = temp[i][j];
				temp[i][j] = 0;
			}
	}

	getItemValues(&tempItem.itemFigure);

	if (!checkMove(tempItem, tempItem.x, tempItem.y))
	{
		return;
	}

	item = tempItem;
}




//Заполнение структуры фигуры
void setFigure(const int temp[FIGURE_HEIGHT][FIGURE_WIDTH], int id)
{
	for (size_t i = 0; i < FIGURE_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIGURE_WIDTH; j++)
		{
			figuresArr[id].value[i][j] = temp[i][j];
		}
	}
	getItemValues(&figuresArr[id]);

	if (id == 0)
	{
		figuresArr[id].color = Magenta;
	}
	else if (id == 1)
	{
		figuresArr[id].color = Blue;
	}
	else if (id == 2)
	{
		figuresArr[id].color = LightRed;
	}
	else if (id == 3)
	{
		figuresArr[id].color = Green;
	}
	else if (id == 4)
	{
		figuresArr[id].color = Yellow;
	}
	else if (id == 5)
	{
		figuresArr[id].color = White;
	}
	else if (id == 6)
	{
		figuresArr[id].color = DarkGray;
	}
}

//Заполнение фигур
void setFigures()
{
	setFigure(figure1, 0);
	setFigure(figure2, 1);
	setFigure(figure3, 2);
	setFigure(figure4, 3);
	setFigure(figure5, 4);
	setFigure(figure6, 5);
	setFigure(figure7, 6);
}

int getRandPos(int type)
{
	int max_value = col - 4 - figuresArr[type].width * 2;
	int n;
	if ((n = rand() % max_value + 2) % 2)
		return ++n;
	return n;
}

ITEM_INFO createItem(int type)
{
	ITEM_INFO info;
	info.itemFigure = figuresArr[type];
	info.x = xCord + getRandPos(type);
	info.y = 0;
	info.type = type;
	return info;
}

//zapolnenie stakan
void SetGlass(int**mas, int row, int col)
{
	int z;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == row - 1 || j == 0 || j == 1 || j == col - 1 || j == col - 2)
			{
				mas[i][j] = Blue;
			}
			else
			{
				mas[i][j] = LightGray;
			}

		}
	}



}

//Движение фигуры лево право
void MoveFigure()
{
	int input = 0;

	input = _getch();

	switch (input)
	{
	case Left:
		if (!checkMove(item, item.x - 1, item.y))
		{
			return;
		}
		item.x -= 2;

		break;
	case Right:

		if (!checkMove(item, item.x + 1, item.y))
		{
			return;
		}
		item.x += 2;

		break;
	case Up:

		rotateItem();
		break;

	}


	drawItem(item.itemFigure.color);
}


//vivodim stakan
void DrawGlass(int**mas, int row, int col, int xCord, int yCord)
{
	for (int i = 0; i < row; i++)
	{
		SetCursor(xCord, yCord + i);
		for (int j = 0; j < col; j++)
		{
			SetColor((Color)mas[i][j], (Color)mas[i][j]);
			cout << " ";
		}
	}
	SetColor(White, Black);
}


void OptionMenu(char**str1, int i_input, int z, char**str, int x)
{

	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			SetColor(Black, White);
			cout << str1[i] << "\n";

		}
		else
		{
			SetColor(White, Black);
			cout << str1[i] << "\n";
		}


	}

	switch (i_input)
	{
	case Right:
		i_input = 0;
		if (z == 2)
		{
			break;
		}
		else
			z++;
		system("cls");
		for (size_t i = 0; i < 3; i++)
		{
			if (i == z)
			{
				SetColor(Black, White);
			}
			else
				SetColor(White, Black);
			cout << str1[i] << "\n";
		}
		SetColor(White, Black);
		break;
	case Down:

		i_input = 0;
		if (x == 2)
		{
			break;
		}
		else
			x++;
		system("cls");
		for (size_t i = 0; i < 3; i++)
		{
			if (i == x)
			{
				SetColor(Black, White);
			}
			else
				SetColor(White, Black);
			cout << str1[i] << "\n";
		}
		SetColor(White, Black);
		break;
	default:
		break;
	}


}

void Menu(int numm, int i_input, int z, char**str, char**mas, int row, int col, int x, char**str1)
{

	//Вывод menu 
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			SetColor(Black, White);
			cout << "[ " << str[i] << " ]" << "\n";

		}
		else
		{
			SetColor(White, Black);
			cout << str[i] << "\n";
		}


	}
	do
	{
		i_input = _getch();


		switch (i_input)
		{
			//Перемещение menu в низ
		case Down:

			i_input = 0;
			if (z == 2)
			{
				break;
			}
			else
				z++;
			system("cls");
			for (size_t i = 0; i < 3; i++)
			{
				if (i == z)
				{
					SetColor(Black, White);
					cout << "[ " << str[i] << " ]" << "\n";
				}
				if (i != z)
				{
					SetColor(White, Black);
					cout << str[i] << "\n";
				}

			}
			SetColor(White, Black);
			break;
		case Up:
			//	z = 2;
			i_input = 0;
			if (z == 0)
			{
				break;
			}
			else
				z--;
			system("cls");

			for (size_t i = 0; i < 3; i++)
			{
				if (i == z)
				{
					SetColor(Black, White);
					cout << "[ " << str[i] << " ]" << "\n";
				}
				if (i != z)
				{
					SetColor(White, Black);
					cout << str[i] << "\n";
				}

			}
			SetColor(White, Black);
			break;
		case 13:

			//Начало игры
			if (z == 0)
			{
				/*system("cls");
				for (size_t i = 0; i < row; i++)
				{
				for (size_t j = 0; j < col; j++)
				{
				if ((i >= 1 && i <= row - 2) && (j >= 1 && j <= col - 2))
				{
				cout << " ";
				}
				else
				{
				mas[i][j] = '*';
				cout << mas[i][j];
				}
				}
				cout << endl;
				}*/

			}
			//изменение стакана
			if (z == 1)
			{


				system("cls");
				OptionMenu(str1, i_input, z, str, x);
				/*for (int i = 0; i < row; i++)
				{
				for (int j = 0; j < col; j++)
				{
				if ((i >= 1 && i <= row - 2) && 				(j >= 1 && j <= col - 2))
				{
				cout << " ";
				}
				else
				{
				mas[i][j] = '*';
				cout << mas[i][j];
				}
				}
				cout << endl;
				}
				*/
				numm = 1;
				break;

			}

			//выход из игры
			if (z == 2)
			{
				numm = 1;
			}



			break;
		}

	} while (numm != 1);

}

//Поток
static void THREAD()
{
	while (true)
	{
		MoveFigure();
	}
}

// движение фигуры самой по себе.
void itemLoop()
{
	Sleep(250);

	checkMove(item, item.x, item.y + 1);

	item.y++;
	drawItem(item.itemFigure.color);


}

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	setConsole(1000, 700);

	int col1 = 0;
	int row1 = 0;
	int col2 = 2, row2 = 2;

	setFigures();

	int **mas = new int*[row];
	for (size_t i = 0; i < row; i++)
	{
		mas[i] = new int[col];
	}
	//доп массив для замены
	char **temp = new char*[row];
	for (size_t i = 0; i < row; i++)
	{
		temp[i] = new char[col];
	}

	//главное меню
	const char *str[3] = { "Начать игру" ,"Опции", "Выйти из игры" };
	//опции меню
	const char *str1[3] = { "Размер стакана" ,"Скорость игры", "Назад" };

	int kx = 10, ky = 10;
	int i_input = 0;
	int numm = 0;
	int z = 0;
	int x = 0;
	int poz = rand() % 4;

	CreateThread(NULL, NULL, LPTHREAD_START_ROUTINE(THREAD), NULL, 0, 0);

	item = createItem(rand() % FIGURE_COUNT);

	//Menu(numm,i_input,z,str,mas,row,col,x,str1);
	SetGlass(mas, row, col);
	DrawGlass(mas, row, col, xCord, yCord);
	while (true)
	{
		itemLoop();
	}






	SetCursor(200, 5);
	//system("pause");
}