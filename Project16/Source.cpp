#include <iostream>
#include <Windows.h>
#include<conio.h>
using namespace  std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, escepushka = 27 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class rectang
{
	int height;
	int widht;
	int cordx;
	int coordy;
	Color cvet;

public:

	bool check(inp)
	{if(inp>0)	
	}

}


//class Box
//{
//	//умолчанию будут private
//	int height;
//	int width;
//	int deep;
//
//public://будут доступны с любого места где был создан объект такого типа
//
//	void inputHeight()
//	{
//		int h;
//		cout << "введите высоту: ";
//		cin >> h;
//		setHeight(h);//вызываем  метод для установки значения в поле класса
//	}
//	void setHeight(int height_)
//	{
//		if (height_ > 1)
//		{
//			height = height_;
//		}
//	}
//	void setWidth(int width_)
//	{
//		if (width_ > 1)
//		{
//			width = width_;
//		}
//	}
//	void setDeep(int deep_)
//	{
//		if (deep_ > 1)
//		{
//			deep = deep_;
//		}
//	}
//	int getHeight()
//	{
//		return height;
//	}
//
//	void showBox()
//	{
//		cout << "height=" << height << "\twidth=" << width << "\tdeep=" << deep << "\n";
//	}
//	void openBox()
//	{
//		cout << "OPEN BOX\n";
//	}
//};
//void main()
//{
//	setlocale(LC_ALL, "rus");
//
//	Box myBox;
//	myBox.setDeep(10);
//	myBox.setHeight(12);
//	myBox.setWidth(15);
//	myBox.showBox();
//
//	Box box1;
//	box1 = myBox;//копирование объектов происходит целиком. Исключение - если в объекте происходит динамическое выделение памяти
//	box1.showBox();
//
//	Box mb;
//	mb.setHeight(myBox.getHeight());

	system("pause");
}