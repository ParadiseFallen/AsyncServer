#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include<io.h>
using namespace  std;



struct log
{
	char login[10];
	char password[20];
}user;

//void setData(char *data)
//{
//	
//
//
//	
//}

void main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	char *data = new char[100];
	FILE* myF;
	fopen_s(&myF, "userDarta.txt", "w");
	cout << "Login: ";
	cin >> user.login;
	cout << "Password: ";
	cin >> user.password;
	fputs(data, myF);
	fopen_s(&myF, "userDarta.txt", "r");
	
	












	system("pause");
}