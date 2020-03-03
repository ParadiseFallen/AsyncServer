﻿// Space Invaders.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "KeyHandler_Win 2.0\includeKeyHandler.h"
using namespace std;


struct Coord {
	int x;
	int y;

};

struct Bullet {
	Coord position;
	bool isDeleted = true;

};

struct Bullets {

	Bullet bulletArray[10];
	int counter = 0;
};


struct SpaceShip {

	Coord pos;

};

void addNewBullet(SpaceShip s, Bullets & b) {
	int x = 0;
	do
	{

		x++;
		if (x>=10)
		{
			return;
		}
	} while (!b.bulletArray[x].isDeleted);

	b.bulletArray[x].isDeleted = false;
	b.bulletArray[x].position.x= s.pos.x;
	b.bulletArray[x].position.y = s.pos.y;
	b.counter+=1;

}

//a  1 2 3 4 5
// b 1 2 3 4 


const int HEIGHT = 20; // y
const int WIDTH = 50; // x
int speedGame = 0.5;

char field[HEIGHT][WIDTH] =
{
	"#################################################",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"|                                               |",
	"#################################################",
};

enum KeyToControl
{
	ARROW_LEFT = 75, ARROW_RIGHT = 77, SPACE_SHOOT = 32, EXIT = 27,
};

bool SetCursorPosition(short x, short y)
{
	COORD coord = { x, y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawSpaceShip(int x, int y)
{
	SetCursorPosition(y, x);
	field[x][y] = (char)254;
	cout << field[x][y];

	SetCursorPosition(y, x + 1);
	field[x + 1][y] = (char)223;
	cout << field[x + 1][y];

	SetCursorPosition(y - 1, x + 1);
	field[x + 1][y - 1] = (char)223;
	cout << field[x + 1][y - 1];

	SetCursorPosition(y + 1, x + 1);
	field[x + 1][y + 1] = (char)223;
	cout << field[x + 1][y + 1];

}

void deleteSpaceShip(int x, int y)
{
	SetCursorPosition(y, x);
	field[x][y] = ' ';
	cout << field[x][y];

	SetCursorPosition(y, x + 1);
	field[x + 1][y] = ' ';
	cout << field[x + 1][y];

	SetCursorPosition(y - 1, x + 1);
	field[x + 1][y - 1] = ' ';
	cout << field[x + 1][y - 1];

	SetCursorPosition(y + 1, x + 1);
	field[x + 1][y + 1] = ' ';
	cout << field[x + 1][y + 1];

	SetCursorPosition(y - 2, x + 1);
	field[x + 1][y - 2] = ' ';
	cout << field[x + 1][y - 2];
}

void printShip(SpaceShip s, bool erase)
{
	SetCursorPosition(s.pos.x, s.pos.y);
	if (!erase)
	{
		cout << char(254);
	}
	else {
		cout << " ";
	}

	SetCursorPosition(s.pos.x + 1, s.pos.y + 1);
	if (!erase)
	{
		cout << char(254);
	}
	else {
		cout << " ";
	}

	SetCursorPosition(s.pos.x - 1, s.pos.y + 1);
	if (!erase)
	{
		cout << char(254);
	}
	else {
		cout << " ";
	}

	SetCursorPosition(s.pos.x, s.pos.y + 1);
	if (!erase)
	{
		cout << char(254);
	}
	else {
		cout << " ";
	}
	//field[x][y] = ' ';
	//cout << field[x][y];

	//SetCursorPosition(y, x + 1);
	//field[x + 1][y] = ' ';
	//cout << field[x + 1][y];

	//SetCursorPosition(y - 1, x + 1);
	//field[x + 1][y - 1] = ' ';
	//cout << field[x + 1][y - 1];

	//SetCursorPosition(y + 1, x + 1);
	//field[x + 1][y + 1] = ' ';
	//cout << field[x + 1][y + 1];

	//SetCursorPosition(y - 2, x + 1);
	//field[x + 1][y - 2] = ' ';
	//cout << field[x + 1][y - 2];
}


void drawField()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (size_t j = 0; j < WIDTH; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
}

void drawShoot(int y, int x)
{
	SetCursorPosition(x, y);
	field[y][x] = '|';
	cout << field[y][x];
}

void deleteShoot(int y, int x)
{
	SetCursorPosition(x, y);
	field[y][x] = ' ';
	cout << field[y][x];
}

void animationShoot(int y, int x)
{
	y = y - 1;
	drawShoot(y, x);
	deleteShoot(y, x);

	do {
		deleteShoot(y, x);
		y--;
		drawShoot(y, x);
		Sleep(100);
	} while (y != 1);
	deleteShoot(y, x);
}

void printBullet(const Bullet & b, bool erase) {
	SetCursorPosition(b.position.x, b.position.y);
	if (erase)
	{
		cout << " ";
	}
	else {
		cout << "O";
	}
};

void moveBullet(Bullets & b) {

	for (size_t i = 0; i < 10; i++)
	{
		if (b.bulletArray->isDeleted)
		{

			if (b.bulletArray[i].position.y == 1)
			{
				b.bulletArray->isDeleted = true;
				b.counter--;
			}
			else {
				printBullet(b.bulletArray[i], true);
				b.bulletArray[i].position.y -= 1;
				printBullet(b.bulletArray[i], false);
			}
		}

		/*	if (b.bulletArray[i].position.y == 1)
			{
				b.counter--;
				printBullet(b.bulletArray[i], true);

			}
			else
			{

				printBullet(b.bulletArray[i], true);
				b.bulletArray[i].position.y -= 1;
				printBullet(b.bulletArray[i], false);
			}*/

	}



	////drawShoot(y,x);
	//printBullet(b, false);

	//if (!isShoot)
	//{
	//	printBullet(b, true);

	//	b.position.y--;
	//	//	drawShoot(y, x);
	//	if (b.position.y == 1)
	//	{

	//		printBullet(b, true);
	//		//deleteShoot(y, x);
	//		isShoot = false;
	//	}
	//}

}

const int NO_KEY = -1;

int getKey()
{
	if (_kbhit())
	{
		int key = _getch();
		//cout << key;
		return key;
	}
	else
	{
		return NO_KEY;
	}
}

void moveLeft(int y, int& x)
{
	//deleteSpaceShip(y, x);
	//drawSpaceShip(y, x);
	Sleep(speedGame);
	if (x > 2)
	{
		deleteSpaceShip(y, x);
		x--;
		drawSpaceShip(y, x);
	}

	/*else
	{
		x = 2;
		y = 16;

	}*/
}

void moveRight(int y, int& x)
{
	//deleteSpaceShip(y, x);

	//drawSpaceShip(y, x);
	Sleep(speedGame);
	if (x < 46)
	{
		deleteSpaceShip(y, x);
		x++;
		drawSpaceShip(y, x);
	}
	/*if (x >= 47)
	{
		deleteSpaceShip(y, x);
		y = 16;
		x = 46;
		drawSpaceShip(y, x);
	}*/
}
void moveRight(SpaceShip & s)
{
	//deleteSpaceShip(y, x);

	//drawSpaceShip(y, x);
	Sleep(speedGame);
	if (s.pos.x < 46)
	{
		printShip(s, true);
		s.pos.x++;
		printShip(s, false);
	}
	/*if (x >= 47)
	{
		deleteSpaceShip(y, x);
		y = 16;
		x = 46;
		drawSpaceShip(y, x);
	}*/
}
void moveLeft(SpaceShip & s)
{
	//deleteSpaceShip(y, x);
	//drawSpaceShip(y, x);
	Sleep(speedGame);
	if (s.pos.x > 2)
	{
		printShip(s, true);
		s.pos.x--;
		printShip(s, false);
	}

	/*else
	{
		x = 2;
		y = 16;

	}*/
}
void controlGame()
{
	//int y, x;
	char key;
	bool exit = false;
	//y = 16;
	//x = 24;
	bool isShooted = false;
	//	Bullet bullet;
	SpaceShip ship;
	ship.pos.x = 24;
	ship.pos.y = 16;
	Bullets BulletS;
	printShip(ship, false);
	do {
		//if (isShooted)
		//{
		//	if (bullet.position.y != 1)
			//{
		if (BulletS.counter > 0)
		{

 			moveBullet(BulletS);
		}
		//}
		//else {

		//	printBullet(bullet, true);
			//isShooted = false;
		//}

	//}
		if (_kbhit())
		{


			//			deleteSpaceShip(y, x);

			switch (keyHandler())
			{
			case(ARROW_LEFT):
				//x--;
				moveLeft(ship);

				break;
			case (ARROW_RIGHT):
				moveRight(ship);
				//x++;

				break;
			case (SPACE_SHOOT):
				//animationShoot(y, x);if	
				//if (!isShooted)
				//{
				addNewBullet(ship, BulletS);
				//	bullet.position.x = ship.pos.x;
				//bullet.position.y = ship.pos.y - 1;
				//isShooted = true;
			//	}

			}
			Sleep(20);
			//		drawSpaceShip(y, x);

		}
		Sleep(200);

	} while (!exit);
}


int main()
{
	drawField();
	controlGame();
	system("pause");
}