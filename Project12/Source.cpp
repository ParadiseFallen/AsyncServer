#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <ctime>
#include<time.h>
#include<io.h>
#include<string>
#include <windows.h>
#include <mmsystem.h>
#include <cstring>
#include<vector>
#include<fstream>
#include <conio.h>
#include<chrono>
#pragma comment(lib,"WINMM.lib")
using namespace std::chrono;
using namespace std;
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//дискриптор активного окна

void setColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void setCursor(int x, int y)
{
	COORD myCoords = { x,y };
	SetConsoleCursorPosition(hStdOut, myCoords);
}
int show7() {
	string mas[11] = { " .----------------. ", "| .--------------. |","| |   _______    | |","| |  |  ___  |   | |","| |  |_/  / /    | |","| |      / /     | |","| |     / /      | |","| |    /_/       | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(40, i);
		cout << mas[i];
	}
	return 0;
}

int show6() {
	string mas[11] = { " .----------------. ","| .--------------. |","| |    ______    | |","| |  .' ____ \\   | |","| |  | |____\\_|  | |","| |  | '____`'.  | |","| |  | (____) |  | |","| |  '.______.'  | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(50, 10 + i);
		cout << mas[i];
	}
	return 0;
}
int show5() {
	string mas[11] = { " .----------------.","| .--------------. |","| |   _______    | |","| |  |  _____|   | |","| |  | |____     | |","| |  '_.____''.  | |","| |  | \\____) |  | |","| |   \\______.'  | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(30, 10 + i);
		cout << mas[i];
	}
	return 0;
}

int show4() {
	string mas[11] = { " .----------------. ","| .--------------. |","| |   _    _     | |","| |  | |  | |    | |","| |  | |__| |_   | |","| |  |____   _|  | |","| |      _| |_   | |","| |     |_____|  | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(40, 20 + i);
		cout << mas[i];
	}
	return 0;
}

int show3() {
	string mas[11] = { " .----------------.","| .--------------. |","| |    ______    | |","| |   / ____ `.  | |","| |   `'  __) |  | |","| |   _ | __ '.  | |","| |  | \\____) |  | |","| |   \\______.'  | |","| |              | |","| '--------------' |", " '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(50, 30 + i);
		cout << mas[i];
	}
	return 0;
}

int show2() {
	string mas[11] = { " .----------------.","| .--------------. |","| |    _____     | |","| |   / ___ `.   | |","| |  |_/___) |   | |","| |   .'____.'   | |","| |  / /____     | |","| |  |_______|   | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(30, 30 + i);
		cout << mas[i];
	}
	return 0;
}
int show1() {
	string mas[11] = { " .----------------.","| .--------------. |","| |     __       | |","| |    /  |      | |","| |    `| |      | |","| |     | |      | |","| |    _| |_     | |","| |   |_____|    | |","| |              | |","| '--------------' |"," '----------------'" };
	for (size_t i = 0; i < 11; i++)
	{
		setCursor(40, 40 + i);
		cout << mas[i];
	}
	return 0;
}

int game()// классики
{
	int score = 0;
	int(*func[7])() = { show1,show2,show3,show4,show5, show6,show7 };
	for (size_t i = 0; i < 7; i++)
	{
		func[i]();
	}
	int keyforend = 1;
	int buf;
	int key = 0;
	int er = 0;
	auto startSat = steady_clock::now();
	do
	{
		setCursor(20, 0);
		cout << "Счет : " << score;
		setCursor(20, 1);
		cout << "Количество ошибок: " << er;
		key = 0;
		buf = 1 + rand() % 7;
		setColor(Black, White);
		func[buf - 1]();
		setColor(White, Black);
		if (steady_clock::now() <= startSat + 60s) {
			Sleep(1500);
		}
		else if (steady_clock::now() > startSat + 60s && steady_clock::now() <= startSat + 120s) {
			Sleep(1000);
		}
		else
		{
			Sleep(500);
		}
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			if (buf == 1)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}

		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			if (buf == 2)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_NUMPAD3))
		{
			if (buf == 3)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_NUMPAD4))
		{
			if (buf == 4)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_NUMPAD5))
		{
			if (buf == 5)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_NUMPAD6))
		{
			if (buf == 6)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_NUMPAD7))
		{
			if (buf == 7)
			{
				key = 1;
				score += 10;
				setColor(Black, Blue);
				func[buf - 1]();
				Sleep(500);
				setColor(White, Black);
			}
		}
		else if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
		if (key == 0)
		{
			er++;
		}
		if (er == 4)
		{
			keyforend = 0;
			break;

		}
		func[buf - 1]();


	} while (keyforend != 0);
	return score;
}






class Tamagochi {
	Color color;
	string name;
	time_t startGame;
	time_t endGame;
	time_t timeGame;
	string state; //s=sleep, a=awake
	int satiety; //сытость
	int joy; //радость
	int health;
	string type;
public:
	virtual void eat(string*) = 0;
	virtual void showObj(int, int) = 0;
	void setState(string s) {
		state = s;
	}
	string getState() {
		return state;
	}
	void setStart(time_t r) {
		startGame = r;
	}
	time_t getSrartG() {
		return startGame;
	}
	void setTimeGame(time_t s) {
		timeGame = s;
	}
	void setEndGame(time_t e) {
		endGame = e;
	}
	time_t getEndGame() {
		return endGame;
	}
	time_t getTimeGame()
	{
		return timeGame;
	}
	void setColorT(Color c) {
		color = c;
	}
	Color getColor() {
		return color;
	}
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}

	void setSatiety(int s) {
		satiety = s;
	}
	int getSat() {
		return satiety;
	}
	void setJoy(int j) {
		joy = j;
	}
	int getJoy() {
		return joy;
	}
	void setHealth(int h) {
		health = h;
	}
	int getHealth() {
		return health;
	}

	Tamagochi(string n, Color c)
	{
		setState("a");
		setTimeGame(0);
		setColorT(c);
		setName(n);
		setSatiety(100);
		setHealth(100);
		setJoy(100);
	}
	void menuEat() {
		FILE *myF;
		int i_input;
		system("cls");
		int ky = 7;
		do
		{
			if (ky == 7)
			{
				setCursor(40, 7);
				setColor(Black, White);
				cout << "Выбрать еду из меню";
				setCursor(40, 8);
				setColor(White, Black);
				cout << "Играть в Угадай еду";
			}
			if (ky == 8)
			{
				setCursor(40, 7);
				setColor(White, Black);
				cout << "Выбрать еду из меню";
				setCursor(40, 8);
				setColor(Black, White);
				cout << "Играть в Угадай еду";
			}
			i_input = _getch();
			switch (i_input)
			{
			case 80:
				if (ky < 8)
				{
					ky++;
				}
				break;
			case 72:
				if (ky > 7)
				{
					ky--;
				}
				break;
			}
		} while (i_input != 13);

		if (ky == 7)
		{
			string mas[3];
			eat(mas);
			int ky = 7, i_input;
			system("cls");
			do
			{
				if (ky == 7)
				{
					setCursor(40, 7);
					setColor(Black, White);
					cout << mas[0];
					setCursor(40, 8);
					setColor(White, Black);
					cout << mas[1];
					setCursor(40, 9);
					cout << mas[2];
				}
				else	if (ky == 8)
				{
					setCursor(40, 7);
					setColor(White, Black);
					cout << mas[0];
					setCursor(40, 8);
					setColor(Black, White);
					cout << mas[1];
					setColor(White, Black);
					setCursor(40, 9);
					cout << mas[2];
				}
				else if (ky == 9) {
					setCursor(40, 7);
					setColor(White, Black);
					cout << mas[0];
					setCursor(40, 8);
					cout << mas[1];
					setColor(Black, White);
					setCursor(40, 9);
					cout << mas[2];
					setColor(White, Black);
				}

				i_input = _getch();
				switch (i_input)
				{
				case 80:
					if (ky < 9)
					{
						ky++;
					}
					break;
				case 72:
					if (ky > 7)
					{
						ky--;
					}
					break;
				}
			} while (i_input != 13);
			setSatiety(getSat() + 5 + rand() % 16);
			if (getSat() > 100)
			{
				setSatiety(100);
			}

		}
		else if (ky == 8)
		{
			gameEat();
		}

	}
	void gameEat()
	{
		system("cls");
		FILE *myF;
		fopen_s(&myF, "food.txt", "r+");
		char* us = new char[100];
		string mas[4];
		string buf[3];
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'М')
			{
				buf[i] = (string)us;
				i++;
			}
		}
		fclose(myF);
		mas[0] = buf[rand() % 3];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'Р')
			{
				buf[i] = (string)us;
				i++;
			}
		}
		fclose(myF);
		fopen_s(&myF, "food.txt", "r+");
		mas[1] = buf[rand() % 3];
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'К')
			{
				buf[i] = (string)us;
				i++;
			}
		}
		fclose(myF);
		mas[2] = buf[rand() % 3];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'С')
			{
				buf[i] = (string)us;
				i++;
			}
		}
		fclose(myF);
		mas[3] = buf[rand() % 3];
		int i_input;
		int ky = 7;
		do {
			if (ky == 7)
			{
				setCursor(40, 7);
				setColor(Black, White);
				cout << mas[0].c_str() + 1;
				setCursor(40, 8);
				setColor(White, Black);
				cout << mas[1].c_str() + 1;
				setCursor(40, 9);
				cout << mas[2].c_str() + 1;
				setCursor(40, 10);
				cout << mas[3].c_str() + 1;
			}
			else	if (ky == 8)
			{
				setCursor(40, 7);
				setColor(White, Black);
				cout << mas[0].c_str() + 1;
				setCursor(40, 8);
				setColor(Black, White);
				cout << mas[1].c_str() + 1;
				setColor(White, Black);
				setCursor(40, 9);
				cout << mas[2].c_str() + 1;
				setCursor(40, 10);
				cout << mas[3].c_str() + 1;
			}
			else if (ky == 9) {
				setCursor(40, 7);
				setColor(White, Black);
				cout << mas[0].c_str() + 1;
				setCursor(40, 8);
				cout << mas[1].c_str() + 1;
				setColor(Black, White);
				setCursor(40, 9);
				cout << mas[2].c_str() + 1;
				setColor(White, Black);
				setCursor(40, 10);
				cout << mas[3].c_str() + 1;
			}
			else if (ky == 10)
			{
				setCursor(40, 7);
				setColor(White, Black);
				cout << mas[0].c_str() + 1;
				setCursor(40, 8);
				cout << mas[1].c_str() + 1;
				setCursor(40, 9);
				cout << mas[2].c_str() + 1;
				setColor(Black, White);
				setCursor(40, 10);
				cout << mas[3].c_str() + 1;
				setColor(White, Black);
			}
			i_input = _getch();
			switch (i_input)
			{
			case 80:
				if (ky < 10)
				{
					ky++;
				}
				break;
			case 72:
				if (ky > 7)
				{
					ky--;
				}
				break;
			}
		} while (i_input != 13);

		if (type[0] == mas[ky - 7].c_str()[0])
		{
			system("cls");
			setCursor(40, 7);
			cout << "Вы угадали еду, поздравляю!!";
			setSatiety(getSat() + 5 + rand() % 16);
			if (getSat() > 100)
			{
				setSatiety(100);
			}
		}
		else
		{
			system("cls");
			setCursor(40, 7);
			cout << "Вы не угадали еду, попробуйте в следующий раз";
		}
	}

	void play() {
		int k = game();
		setJoy(getJoy() + k / 2);
		if (getJoy() > 100)
		{
			setJoy(100);
		}
	}
	void heal() {
		system("cls");
		int i_input;
		setCursor(40, 7);
		cout << "Тыкните любую клавишу чтобы лечить животное ";
		i_input = _getch();
		setHealth(getHealth() + (5 + rand() % 16));
		setJoy(getJoy() - (0 + rand() % 10));
		if (getHealth() > 100)
		{
			setHealth(100);
		}
	}
	void moov(int key, int &kx) {

		int buf = kx;
		int keyforch = 0;
		switch (key)
		{
		case 0:
			if (kx > 2)
			{
				keyforch = 1;
				kx--;
			}
			break;
		case 1:
			if (kx < 59)
			{
				keyforch = 1;
				kx++;
			}
			break;
		}
		if (keyforch == 1)
		{
			setColor(Black, Black);
			showObj(buf, buf);
			setColor(Color(getColor()), Black);
			showObj(kx, buf);
			setColor(White, Black);
		}

	}
	void setType(string t)
	{
		type = t;
	}
	string getType() {
		return type;
	}
	virtual void say() = 0;
};
class Bear : public Tamagochi {
public:
	Bear(string n, Color c) :Tamagochi(n, c) { setType("Медведь"); };
	virtual void eat(string mas[]) {
		FILE *myF;
		char *us = new char[100];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'М')
			{
				mas[i] = (string)us;
				mas[i].erase(0, 1);
				i++;
			}
		}
		fclose(myF);
	}

	virtual void say() {
		//PlaySound("bear.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	virtual void showObj(int kx, int buf) {
		vector<string> mas;
		mas.push_back(" __         __");
		mas.push_back("/  \\.-'''-./  \\");
		mas.push_back("\\    -   -    /");
		mas.push_back(" |   o   o   |");
		mas.push_back(" \\  .-'''-.  /");
		mas.push_back("  '-\\__Y__/-'");
		mas.push_back("     `---`");
		for (size_t i = 0; i < mas.size(); i++)
		{
			setCursor(kx, i + 1);
			cout << mas[i];
		}
	}
};

class Fish : public Tamagochi {
public:
	Fish(string n, Color c) :Tamagochi(n, c) { setType("Рыбка"); };
	virtual void say() {
		//PlaySound("fish.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	virtual void eat(string mas[]) {
		FILE *myF;
		char *us = new char[100];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'Р')
			{
				mas[i] = (string)us;
				mas[i].erase(0, 1);
				i++;
			}
		}
		fclose(myF);
	}

	virtual void showObj(int kx, int buf) {
		vector<string> mas;
		if (kx > buf)
		{
			mas.push_back("_          _.*'\\      ");
			mas.push_back("\\'-._..-*`     ``'*-. ");
			mas.push_back(" )        ;    ((  * >");
			mas.push_back("/.`'*--.__)_.`_.-*`   ");
		}
		else
		{
			mas.push_back("      /'*._         _ ");
			mas.push_back("  .-*'`    `*-.._.-'/ ");
			mas.push_back("< * ))     ;       (  ");
			mas.push_back("  `*-._`._(__.--*'`.\\");
		}
		for (size_t i = 0; i < mas.size(); i++)
		{
			setCursor(kx, i + 1);
			cout << mas[i];
		}
	}
};

class Dog :public Tamagochi {
public:
	Dog(string n, Color c) :Tamagochi(n, c) { setType("Собака"); };

	virtual void eat(string mas[]) {
		FILE *myF;
		char *us = new char[100];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'С')
			{
				mas[i] = (string)us;
				mas[i].erase(0, 1);
				i++;
			}

		}
		fclose(myF);
	}
	virtual void say() {
		//PlaySound("dog.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	virtual void showObj(int kx, int buf) {
		vector<string> mas;
		mas.push_back("             .--~~,__ ");
		mas.push_back(":-....,-------`~~'._.'");
		mas.push_back("  `-,,,  ,_      ;'~U'");
		mas.push_back("   _,-' ,'`-__; '--.  ");
		mas.push_back("  (_/'~~      ''''(;  ");
		for (size_t i = 0; i < mas.size(); i++)
		{
			setCursor(kx, i + 1);
			if (kx < buf)
			{
				reverse(mas[i].begin(), mas[i].end());
			}
			cout << mas[i];
		}
	}
};
class Cat : public Tamagochi {
public:
	Cat(string n, Color c) :Tamagochi(n, c) { setType("Кошка"); };
	virtual void eat(string mas[]) {
		FILE *myF;
		char *us = new char[100];
		fopen_s(&myF, "food.txt", "r+");
		for (size_t i = 0; i < 3; )
		{
			fgets(us, 100, myF);
			if (us[0] == 'К')
			{
				mas[i] = (string)us;
				mas[i].erase(0, 1);
				i++;
			}
		}
		fclose(myF);
	}
	virtual void say() {
		//PlaySound("cat.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	virtual void showObj(int kx, int buf) {
		vector<string> mas;
		mas.push_back(" |\\_/|");
		mas.push_back(" (. .)");
		mas.push_back("  =w= (\\");
		mas.push_back(" / ^ \// ");
		mas.push_back("(|| ||)");
		mas.push_back(",""_""_ .");
		for (size_t i = 0; i < mas.size(); i++)
		{
			setCursor(kx, i + 1);
			cout << mas[i];
		}
	}
};

class User {
	vector<Tamagochi*> myCreatures;
	string name;
public:
	void setVect(vector<Tamagochi*> obj) {
		myCreatures = obj;
	}
	void setName(string n) {
		name = n;
	}
	void setCreatures(Tamagochi *obj) {
		myCreatures.push_back(obj);
	}
	string getName() {
		return name;
	}
	vector<Tamagochi*> getCreatures() {
		return myCreatures;
	}
};

string dismem(string &str) {
	int num;
	string buf = "";
	num = str.find("%");
	buf.append(str, 0, num);
	str.erase(0, num + 1);
	return buf;
}

int menuforNewUs() {
	system("cls");
	setCursor(40, 6);
	setColor(White, Black);
	cout << "Кем вы хотите играть?";
	int ky = 7;
	setCursor(40, 9);
	cout << "Рыбка";
	setCursor(40, 10);
	cout << "Медведь";
	int i_input;
	do
	{
		if (ky == 7)
		{
			setCursor(40, 7);
			setColor(Black, White);
			cout << "Собака";
			setCursor(40, 8);
			setColor(White, Black);
			cout << "Кошка";
		}
		else	if (ky == 8)
		{
			setCursor(40, 7);
			cout << "Cобака";
			setCursor(40, 8);
			setColor(Black, White);
			cout << "Кошка";
			setColor(White, Black);
			setCursor(40, 9);
			cout << "Рыбка";
		}
		else if (ky == 9) {
			setCursor(40, 8);
			cout << "Кошка";
			setColor(Black, White);
			setCursor(40, 9);
			cout << "Рыбка";
			setColor(White, Black);
			setCursor(40, 10);
			cout << "Медведь";
		}
		else if (ky == 10)
		{
			setCursor(40, 9);
			cout << "Рыбка";
			setColor(Black, White);
			setCursor(40, 10);
			cout << "Медведь";
			setColor(White, Black);
		}
		i_input = _getch();
		switch (i_input)
		{
		case 80:
			if (ky < 10)
			{
				ky++;
			}
			break;
		case 72:
			if (ky > 7)
			{
				ky--;
			}
			break;
		}
	} while (i_input != 13);
	return ky - 6;
}

int setc() {
	system("cls");
	setCursor(40, 6);
	cout << "Животное какого цвета вы хотите?";
	int i_input;
	int ky = 7;
	setCursor(40, 9);
	cout << "Берюзового";
	setCursor(40, 10);
	cout << "Красного";
	do
	{
		if (ky == 7)
		{
			setCursor(40, 7);
			setColor(Black, White);
			cout << "Голубого";
			setColor(White, Black);
			setCursor(40, 8);
			cout << "Зеленого";
		}
		else if (ky == 8)
		{
			setCursor(40, 7);
			cout << "Голубого";
			setColor(Black, White);
			setCursor(40, 8);
			cout << "Зеленого";
			setCursor(40, 9);
			setColor(White, Black);
			cout << "Берюзового";
		}
		else if (ky == 9)
		{
			setCursor(40, 8);
			cout << "Зеленого";
			setCursor(40, 9);
			setColor(Black, White);
			cout << "Берюзового";
			setColor(White, Black);
			setCursor(40, 10);
			cout << "Красного";
		}
		if (ky == 10)
		{
			setCursor(40, 9);
			cout << "Берюзового";
			setCursor(40, 10);
			setColor(Black, White);
			cout << "Красного";
			setColor(White, Black);
		}
		i_input = _getch();
		switch (i_input)
		{
		case 80:
			if (ky < 10)
			{
				ky++;
			}
			break;
		case 72:
			if (ky > 7)
			{
				ky--;
			}
			break;
		}
	} while (i_input != 13);
	return ky - 6;
}


//выбор несуществуюшего животного
void setNotExAnimal(Tamagochi* &obj) {
	string name;
	system("cls");
	int k = menuforNewUs();
	system("cls");
	setCursor(40, 7);
	cout << "Введите имя животного: ";
	setCursor(40, 8);
	cin >> name;
	int color = setc();
	switch (k) {
	case 1:
		obj = new Dog(name, Color(color));
		break;
	case 2:
		obj = new Cat(name, Color(color));
		break;
	case 3:
		obj = new Fish(name, Color(color));
		break;
	case 4:
		obj = new Bear(name, Color(color));
		break;
	}
}
//выбор существуюшего животного
void setExisAnimal(User &user, Tamagochi* &obj, int &ky, int &keyforend) {
	system("cls");
	if (user.getCreatures().size() > 0)
	{
		int keyforNewAn = 0;
		setCursor(25, 6);
		cout << "Выберите животное: ";
		setCursor(46, 6);
		cout << "Здоровье";
		setCursor(56, 6);
		cout << "Сытость";
		setCursor(65, 6);
		cout << "Радость";
		if (user.getCreatures().size() < 4)
		{
			setCursor(9, 8);
			cout << "Создать новое";
			setCursor(12, 9);
			cout << "животное";
		}
		for (size_t i = 0; i < user.getCreatures().size(); i++)
		{
			setCursor(25, 7 + i);
			cout << user.getCreatures()[i]->getType();
			setCursor(46, 7 + i);
			cout << user.getCreatures()[i]->getHealth();
			setCursor(56, 7 + i);
			cout << user.getCreatures()[i]->getSat();
			setCursor(65, 7 + i);
			cout << user.getCreatures()[i]->getJoy();
		}
		int i_input;
		setCursor(22, 7);
		cout << "->";
		do
		{
			if (keyforNewAn == 0)
			{
				setCursor(6, 8);
				cout << "  ";
			}
			if (keyforNewAn == 1)
			{
				setCursor(22, 7);
				cout << "  ";
				setCursor(22, 8);
				cout << "  ";
				setCursor(22, 9);
				cout << "  ";
				setCursor(22, 10);
				cout << "  ";
				setCursor(6, 8);
				cout << "->";
			}
			else if (ky == 7)
			{
				setCursor(22, 7);
				cout << "->";
				setCursor(22, 8);
				cout << "  ";
			}
			else if (ky == 8)
			{
				setCursor(22, 7);
				cout << "  ";
				setCursor(22, 8);
				cout << "->";
				setCursor(22, 9);
				cout << "  ";
			}
			else if (ky == 9)
			{

				setCursor(22, 8);
				cout << "  ";
				setCursor(22, 9);
				cout << "->";
				setCursor(22, 10);
				cout << "  ";
			}
			else if (ky == 10)
			{
				setCursor(22, 9);
				cout << "  ";
				setCursor(22, 10);
				cout << "->";
			}
			i_input = _getch();
			switch (i_input)
			{
			case 80:
				if (ky < user.getCreatures().size() + 6)
				{
					ky++;
				}
				break;
			case 72:
				if (ky >= 8)
				{
					ky--;
				}
				break;
			case 75:
				if (keyforNewAn == 0)
				{
					keyforNewAn = 1;
				}
				break;
			case 77:
				if (keyforNewAn == 1)
				{
					keyforNewAn = 0;
				}
				break;
			}

		} while (i_input != 13);
		if (keyforNewAn == 1)
		{
			setNotExAnimal(obj);
			keyforend = 1;
		}
		else
		{
			obj = user.getCreatures()[ky - 7];
		}
	}
	else
	{
		setNotExAnimal(obj);
		keyforend = 1;
	}
}


void avtorization(User &user, Tamagochi* &obj, string nameUs) {
	FILE *myF;
	string buf, buf2;
	char* mystr = new char[300];
	int key = 0;
	fopen_s(&myF, "users.txt", "r+");
	if (_filelength(_fileno(myF)) > 0) {
		while (!feof(myF))
		{
			fgets(mystr, 300, myF);
			buf2 = (string)mystr;
			buf = dismem(buf2);
			if (buf == nameUs)
			{
				key = 1;
				user.setName(buf);
				buf = dismem(buf2);
				if (buf == "cat")
				{
					obj = new Cat(dismem(buf2), Color(atoi(dismem(buf2).c_str())));
					obj->setHealth(atoi(dismem(buf2).c_str()));
					obj->setSatiety(atoi(dismem(buf2).c_str()));
					obj->setJoy(atoi(dismem(buf2).c_str()));
					obj->setTimeGame(atoi(dismem(buf2).c_str()));
					obj->setEndGame(atoi(dismem(buf2).c_str()));
					obj->setState(dismem(buf2));
					user.setCreatures(obj);
				}
				else if (buf == "dog")
				{
					obj = new Dog(dismem(buf2), Color(atoi(dismem(buf2).c_str())));
					obj->setHealth(atoi(dismem(buf2).c_str()));
					obj->setSatiety(atoi(dismem(buf2).c_str()));
					obj->setJoy(atoi(dismem(buf2).c_str()));
					obj->setTimeGame(atoi(dismem(buf2).c_str()));
					obj->setEndGame(atoi(dismem(buf2).c_str()));
					obj->setState(dismem(buf2));
					user.setCreatures(obj);
				}
				else if (buf == "bear")
				{
					obj = new Bear(dismem(buf2), Color(atoi(dismem(buf2).c_str())));
					obj->setHealth(atoi(dismem(buf2).c_str()));
					obj->setSatiety(atoi(dismem(buf2).c_str()));
					obj->setJoy(atoi(dismem(buf2).c_str()));
					obj->setTimeGame(atoi(dismem(buf2).c_str()));
					obj->setEndGame(atoi(dismem(buf2).c_str()));
					obj->setState(dismem(buf2));
					user.setCreatures(obj);
				}
				else if (buf == "fish")
				{
					obj = new Fish(dismem(buf2), Color(atoi(dismem(buf2).c_str())));
					obj->setHealth(atoi(dismem(buf2).c_str()));
					obj->setSatiety(atoi(dismem(buf2).c_str()));
					obj->setJoy(atoi(dismem(buf2).c_str()));
					obj->setTimeGame(atoi(dismem(buf2).c_str()));
					obj->setEndGame(atoi(dismem(buf2).c_str()));
					obj->setState(dismem(buf2));
					user.setCreatures(obj);
				}
			}
		}
	}
	fclose(myF);
	int keyforend = 0;
	if (key == 0)
	{
		user.setName(nameUs);
		setNotExAnimal(obj);
	}

	else if (key == 1)
	{
		for (;;)
		{
			int ky = 7;
			setExisAnimal(user, obj, ky, keyforend);
			time_t rawtime;
			time(&rawtime);
			string a = "a";
			string s = "s";
			if (keyforend == 1)
			{
				break;
			}
			if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 24 && obj->getState() == s)
			{
				system("cls");
				setCursor(40, 7);
				cout << "Это животное уже умерло";
				Sleep(2000);
				vector<Tamagochi*> buf = user.getCreatures();
				buf.erase(buf.begin() + (ky - 7));
				user.setVect(buf);
			}
			else if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 12 && obj->getState() == a)
			{
				system("cls");
				setCursor(40, 7);
				cout << "Это животное уже умерло";
				Sleep(2000);
				vector<Tamagochi*> buf = user.getCreatures();
				buf.erase(buf.begin() + (ky - 7));
				user.setVect(buf);
			}
			else {
				vector<Tamagochi*> buf = user.getCreatures();
				buf.erase(buf.begin() + (ky - 7));
				user.setVect(buf);
				break;
			}
		}
	}
}

bool menu(Tamagochi* &obj, User &user) {
	system("cls");
	int keyforend = 0;
	time_t rawtime;
	int ky = 7;
	setCursor(40, 6);
	cout << "Меню";
	if (obj->getState() == "a")
	{
		setCursor(39, 9);
		cout << "Лечить";
		setCursor(39, 10);
		cout << "Спать";
		setCursor(31, 11);
		cout << "Выбрать другое животное";
		setCursor(39, 12);
		cout << "Выход";
		int i_input;
		do
		{
			if (ky == 7)
			{
				setColor(Black, White);
				setCursor(39, 7);
				cout << "Кормить";
				setColor(White, Black);
				setCursor(39, 8);
				cout << "Играть";
			}
			else	if (ky == 8)
			{
				setCursor(39, 7);
				cout << "Кормить";
				setCursor(39, 9);
				cout << "Лечить";
				setColor(Black, White);
				setCursor(39, 8);
				cout << "Играть";
				setColor(White, Black);
			}
			else if (ky == 9)
			{
				setCursor(39, 8);
				cout << "Играть";
				setCursor(39, 10);
				cout << "Cпать";
				setCursor(39, 9);
				setColor(Black, White);
				cout << "Лечить";
				setColor(White, Black);
			}
			else if (ky == 10)
			{
				setCursor(39, 9);
				cout << "Лечить";
				setCursor(31, 11);
				cout << "Выбрать другое животное";
				setCursor(39, 10);
				setColor(Black, White);
				cout << "Cпать";
				setColor(White, Black);
			}
			else if (ky == 11)
			{
				setCursor(39, 12);
				cout << "Выход";
				setCursor(39, 10);
				cout << "Спать";
				setCursor(31, 11);
				setColor(Black, White);
				cout << "Выбрать другое животное";
				setColor(White, Black);
			}
			else if (ky == 12)
			{
				setCursor(31, 11);
				cout << "Выбрать другое животное";
				setCursor(39, 12);
				setColor(Black, White);
				cout << "Выход";
				setColor(White, Black);
			}
			i_input = _getch();
			switch (i_input)
			{
			case 80:
				if (ky < 12)
				{
					ky++;
				}
				break;
			case 72:
				if (ky > 7)
				{
					ky--;
				}
				break;
			}
		} while (i_input != 13);
		switch (ky)
		{
		case 7:
			obj->menuEat();
			break;
		case 8:
			obj->play();
			break;
		case 9:
			obj->heal();
			break;
		case 10:
			obj->setState("s");
			break;
		case 11:
			time(&rawtime);
			obj->setEndGame(rawtime);
			obj->setTimeGame(obj->getTimeGame() + (obj->getEndGame() - obj->getSrartG()));
			user.setCreatures(obj);
			for (;;)
			{
				ky = 7;
				setExisAnimal(user, obj, ky, keyforend);
				time(&rawtime);
				string a = "a";
				string s = "s";
				if (keyforend == 1)
				{
					break;
				}
				if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 24 && obj->getState() == s)
				{
					system("cls");
					setCursor(40, 7);
					cout << "Это животное уже умерло";
					Sleep(2000);
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
				}
				else if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 12 && obj->getState() == a)
				{
					system("cls");
					setCursor(40, 7);
					cout << "Это животное уже умерло";
					Sleep(2000);
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
				}
				else {
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
					break;
				}
			}
			obj->setStart(time(&rawtime));
			break;
		case 12:
			time(&rawtime);
			obj->setEndGame(rawtime);
			obj->setTimeGame(obj->getTimeGame() + (obj->getEndGame() - obj->getSrartG()));
			user.setCreatures(obj);
			return true;
			break;
		}
	}
	else if (obj->getState() == "s")
	{
		int i_input;
		ky = 7;
		setCursor(39, 9);
		cout << "Выход";
		do
		{
			if (ky == 7)
			{
				setColor(Black, White);
				setCursor(38, 7);
				cout << "Разбудить";
				setColor(White, Black);
				setCursor(31, 8);
				cout << "Выбрать другое животное";
			}
			else if (ky == 8)
			{
				setCursor(38, 7);
				cout << "Разбудить";
				setCursor(39, 9);
				cout << "Выход";
				setColor(Black, White);
				setCursor(31, 8);
				cout << "Выбрать другое животное";
				setColor(White, Black);
			}
			else if (ky == 9) {
				setCursor(31, 8);
				cout << "Выбрать другое животное";
				setCursor(39, 9);
				setColor(Black, White);
				cout << "Выход";
				setColor(White, Black);
			}
			i_input = _getch();
			switch (i_input)
			{
			case 80:
				if (ky < 9)
				{
					ky++;
				}
				break;
			case 72:
				if (ky > 7)
				{
					ky--;
				}
				break;
			}
		} while (i_input != 13);
		switch (ky) {
		case 7:
			obj->setState("a");
			break;
		case 8:
			time(&rawtime);
			obj->setEndGame(rawtime);
			obj->setTimeGame(obj->getTimeGame() + (obj->getEndGame() - obj->getSrartG()));
			user.setCreatures(obj);
			for (;;)
			{
				ky = 7;
				setExisAnimal(user, obj, ky, keyforend);
				time(&rawtime);
				string a = "a";
				string s = "s";
				if (keyforend == 1)
				{
					break;
				}
				if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 24 && obj->getState() == s)
				{
					system("cls");
					setCursor(40, 7);
					cout << "Это животное уже умерло";
					Sleep(2000);
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
				}
				else if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 12 && obj->getState() == a)
				{
					system("cls");
					setCursor(40, 7);
					cout << "Это животное уже умерло";
					Sleep(2000);
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
				}
				else {
					vector<Tamagochi*> buf = user.getCreatures();
					buf.erase(buf.begin() + (ky - 7));
					user.setVect(buf);
					break;
				}
			}
			obj->setStart(time(&rawtime));
			break;
		case 9:
			time(&rawtime);
			obj->setEndGame(rawtime);
			obj->setTimeGame(obj->getTimeGame() + (obj->getEndGame() - obj->getSrartG()));
			user.setCreatures(obj);
			return true;
			break;
		}
	}
	return false;
}
void writeonEnd(User &user) {
	cout << "dfgdfgdfgd";
	vector<string>  buf;
	string buf2;
	string buf3;
	char* mystr = new char[300];
	FILE *myF;
	cout << "\ndsfdsfdsf";
	fopen_s(&myF, "users.txt", "r+");
	cout << "\ndsfdsfdsf";
	if (_filelength(_fileno(myF)) > 0) {
		while (!feof(myF))
		{
			fgets(mystr, 300, myF);
			buf2 = (string)mystr;
			buf3 = buf2;
			if (user.getName() != dismem(buf2))
			{
				buf.push_back(buf3);
			}
		}
	}
	fclose(myF);
	ofstream k("users.txt");
	for (size_t i = 0; i < buf.size(); i++)
	{
		k << buf[i];
	}
	buf2 = buf[buf.size() - 1];
	if (buf2.find("\n") == -1)
	{
		k << "\n";
	}
	for (size_t i = 0; i < user.getCreatures().size(); i++)
	{
		k << user.getName() << "%";
		if (user.getCreatures()[i]->getType() == "Рыбка")
		{
			k << "fish%";
		}
		else if (user.getCreatures()[i]->getType() == "Кошка")
		{
			k << "cat%";
		}
		else if (user.getCreatures()[i]->getType() == "Собака")
		{
			k << "dog%";
		}
		else if (user.getCreatures()[i]->getType() == "Медведь")
		{
			k << "bear%";
		}

		int c = user.getCreatures()[i]->getColor();
		k << user.getCreatures()[i]->getName() << "%" << c << "%" << user.getCreatures()[i]->getHealth() << "%" << user.getCreatures()[i]->getSat() << "%" << user.getCreatures()[i]->getJoy() << "%" << user.getCreatures()[i]->getTimeGame() << "%" << user.getCreatures()[i]->getEndGame() << "%" << user.getCreatures()[i]->getState() << "%";
		if (user.getCreatures().size() - i >= 2)
		{
			k << "\n";
		}
	}
	k.close();
}
void menuForResp(Tamagochi* &obj, User &user) {
	system("cls");
	int ky = 7;
	int i_input;
	do
	{
		if (ky == 7)
		{
			setCursor(40, 7);
			setColor(Black, White);
			cout << "Возродить это животное";
			setColor(White, Black);
			setCursor(40, 8);
			cout << "Выбрать другое животное";
		}
		else if (ky == 8)
		{
			setCursor(40, 7);
			cout << "Возродить это животное";
			setColor(Black, White);
			setCursor(40, 8);
			cout << "Выбрать другое животное";
			setColor(White, Black);
		}
		i_input = _getch();
		switch (i_input)
		{
		case 80:
			if (ky < 8)
			{
				ky++;
			}
			break;
		case 72:
			if (ky > 7)
			{
				ky--;
			}
			break;
		}
	} while (i_input != 13);
	time_t rawtime;
	int keyforend = 0;
	switch (ky)
	{
	case 7:
		obj->setHealth(100);
		obj->setJoy(100);
		obj->setSatiety(100);
		break;
	case 8:
		ky = 7;
		setExisAnimal(user, obj, ky, keyforend);
		time(&rawtime);
		string a = "a";
		string s = "s";
		if (keyforend == 1)
		{
			break;
		}
		if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 24 && obj->getState() == s)
		{
			system("cls");
			setCursor(40, 7);
			cout << "Это животное уже умерло";
			Sleep(2000);
			vector<Tamagochi*> buf = user.getCreatures();
			buf.erase(buf.begin() + (ky - 7));
			user.setVect(buf);
		}
		else if ((rawtime / 3600) - (obj->getEndGame() / 3600) >= 12 && obj->getState() == a)
		{
			system("cls");
			setCursor(40, 7);
			cout << "Это животное уже умерло";
			Sleep(2000);
			vector<Tamagochi*> buf = user.getCreatures();
			buf.erase(buf.begin() + (ky - 7));
			user.setVect(buf);
		}
		else {
			vector<Tamagochi*> buf = user.getCreatures();
			buf.erase(buf.begin() + (ky - 7));
			user.setVect(buf);
			break;
		}

		obj->setStart(time(&rawtime));
		break;
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	string nameUs;
	Tamagochi* obj = new Cat("buf", Color(4));
	User user;
	setCursor(40, 7);
	cout << "Введите ваш логин\n";
	setCursor(40, 8);
	cin >> nameUs;
	avtorization(user, obj, nameUs);
	//menu(obj, user);
	//writeonEnd(user);
	time_t rawtime;
	auto startSat = steady_clock::now();
	auto startJoy = steady_clock::now();
	auto startHealth = steady_clock::now();
	obj->setStart(time(&rawtime));
	int kx = 0;
	int r;
	system("cls");
	for (;;)
	{
		if (GetAsyncKeyState(VK_LEFT)) {
			obj->moov(0, kx);
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			obj->moov(1, kx);
		}
		else
		{
			r = rand() % 2;
			if (r == 1)
			{
				obj->moov(rand() % 2, kx);

			}
		}
		if (GetAsyncKeyState(0x4D/*m*/)) {
			if (menu(obj, user))
			{
				break;
			}
			system("cls");
			setColor(Color(obj->getColor()), Black);
			obj->showObj(kx, kx);
			setColor(White, Black);
		}
		if (GetAsyncKeyState(0x53/*s*/))
		{
			obj->say();
		}
		if (steady_clock::now() - startSat >= 10min)
		{
			obj->setSatiety(obj->getSat() - 7);
		}
		if (steady_clock::now() - startHealth >= 30min)
		{
			obj->setHealth(obj->getHealth() - 15);
		}
		if (steady_clock::now() - startJoy >= 15min)
		{
			obj->setJoy(obj->getJoy() - 30);
		}
		if (obj->getSat() <= 5)
		{
			obj->setHealth(obj->getHealth() - 5);
		}
		if (obj->getHealth() <= 0)
		{
			menuForResp(obj, user);
			system("cls");
		}
		setCursor(10, 8);
		cout << "   ";
		setCursor(0, 8);
		cout << "Здоровье: " << obj->getHealth();
		setCursor(29, 8);
		cout << "   ";
		setCursor(20, 8);
		cout << "Радость: " << obj->getJoy();
		setCursor(49, 8);
		cout << "   ";
		setCursor(40, 8);
		cout << "Сытость: " << obj->getSat();
		setCursor(65, 8);
		cout << "   ";
		setCursor(60, 8);
		cout << "Имя: " << obj->getName();
		Sleep(1000);
	}
	writeonEnd(user);
}