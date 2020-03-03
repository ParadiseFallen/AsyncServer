/*
Описать класс БАНК, который будет работаться с динамическим массивом клиентов. Каждый клиент представляет собой набор полей - имя, id и денежный балланс.
Реализовать работу используя кольцевую очередь с приоритетом.
Когда клиент попадает в "обработку" ему начисляются прценты. к пример 2%. Выводится сообщение - "имя клиента начисленны проценты".
1 вариант: После чего клиент отправляется в хвост очереди
2 вариант: запоминаем id обработанных клиентов и при выборе следующего наивысшего приоритета пропускаем "обработанных" клиентов.

Реализовать методы:
Показа очереди
Добавления элемента в очередь
Удаления элемента очереди на тот случай. если его балланс стал равен 0
Изменение балланса пользователя - имитировать растраты и пополнение счёта. Добавляется и отнимается случайное значение.
Начисление роцентов, согласно приоритету - т.е. у кого больший денежный балланс - того "обрабатывают" первым.
*/
#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

const unsigned char SPEC_SYMB = 224;
const unsigned char ENTER = 13;
const unsigned char ESC = 27;
const unsigned char SPACE = 32;
const unsigned char BSPACE = 8;
const unsigned char UP = 72;
const unsigned char RIGHT = 77;
const unsigned char DOWN = 80;
const unsigned char LEFT = 75;

const double percent = 2.0;

HANDLE ha = GetStdHandle(STD_OUTPUT_HANDLE);

void setPos(const short x, const short y)
{
	COORD ca = { x, y };
	SetConsoleCursorPosition(ha, ca);
}

void setCol(const short f, const short b)
{
	SetConsoleTextAttribute(ha, (WORD)(b << 4) | f);
}

int getAsyncKey()
{
	if (_kbhit())
	{
		return _getch();
	}
	return 0;
}

struct Client
{
	string	name;
	long	id;
	double	money;
};

class Bank
{
	vector<Client>	clients;
	const size_t	x, y;

public:
	Bank(const size_t bx, const size_t by) :
		clients(),
		x(bx),
		y(by)
	{}

	bool isEmpty() const
	{
		return !clients.size();
	}

	bool isFull() const
	{
		return false;
	}

	const size_t size() const
	{
		return clients.size();
	}

	void add(const Client& client, bool displ)
	{
		if (!isFull())
		{
			if (displ)
			{
				clear();
			}
			size_t i = 0;
			for (; i < clients.size() && client.money < clients[i].money; i++);
			clients.insert(clients.cbegin() + i, client);
			if (displ)
			{
				display();
			}
		}
	}

	void work()
	{
		if (clients.size())
		{

			activeClient(0);
			double plus = (clients[0].money * (percent / 100));
			cout << " Баланс увеличился на " << plus << "$";
			cout << " . Нажмите Enter . . . ";
			clients[0].money += plus;
			while (_getch() != ENTER);
			clearClient(0);
			setCol(0, 0);
			cout << " Баланс увеличился на " << plus << "$";
			cout << " . Нажмите Enter . . . ";
			clear();
			Client temp = clients[0];
			for (size_t i = 0; i < clients.size() - 1; i++)
			{
				clients[i] = clients[i + 1];
			}
			clients[clients.size() - 1] = temp;
			display();
		}
	}

	void del(const size_t i)
	{
		activeClient(i, 12, 0);
		cout << " Клиент удаляется из списка клиентов банка. Баланс = " << clients[i].money;
		cout << ". Нажмите Enter . . . ";
		while (_getch() != 13);
		activeClient(i, 0, 0);
		cout << " Клиент удаляется из списка клиентов банка. Баланс = " << clients[i].money;
		cout << ". Нажмите Enter . . . ";
		clearClient(clients.size() - 1);
		clients.erase(clients.cbegin() + i);
		display();
	}

	void check()
	{
		for (size_t i = 0; i < clients.size(); i++)
		{
			if (clients[i].money <= 0)
			{
				del(i);
			}
		}
	}

	void random()
	{
		if (clients.size())
		{
			size_t index = rand() % clients.size();
			int plus = (rand() % 1201 - 600);
			if (!plus) plus++;
			activeClient(index);
			setCol(15, 0);
			cout << " Баланс клиента " << (plus > 0 ? "увеличился" : "уменьшился") << " на " <<
				abs(plus);
			cout << " Нажмите Enter . . . ";
			clients[index].money += plus;
			while (_getch() != ENTER);
			displayClient(index);
			setCol(0, 0);
			cout << " Баланс клиента " << (plus > 0 ? "увеличился" : "уменьшился") << " на " <<
				abs(plus);
			cout << " Нажмите Enter . . . ";
			check();
		}
	}

	void displayClient(const size_t index) const
	{
		setPos(x, y + index);
		setCol(14, 0);
		cout << clients[index].name << " [";
		setCol(10, 0);
		cout << clients[index].id;
		setCol(14, 0);
		cout << "] :";
		setCol(10, 0);
		cout << " $";
		setCol(15, 0);
		cout << clients[index].money;
	}

	void clearClient(const size_t index) const
	{
		activeClient(index, 0, 0);
	}

	void activeClient(const size_t index, const short fc = 10, const short bc = 0) const
	{
		setPos(x, y + index);
		setCol(fc, bc);
		cout << clients[index].name << " [" << clients[index].id << "] :";
		cout << " $" << clients[index].money;
	}

	void display() const
	{
		for (size_t i = 0; i < clients.size(); i++)
		{
			displayClient(i);
		}
	}

	void clear() const
	{
		for (size_t i = 0; i < clients.size(); i++)
		{
			clearClient(i);
		}
	}
};

Client makeClient()
{
	static int id = 0;
	static const string names[] = { "Ivan", "Petr", "Vasya", "Steve", "Bred" };
	return Client{ names[rand() % 5], id++, static_cast<double>(1000 + (rand() % 51 - 25)) };
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Bank bank(1, 1);
	for (size_t i = 0; i < 10; i++)
	{
		bank.add(makeClient(), false);
	}

	bank.display();
	float delay = 0.0;
	int press = 0;
	int selectPress = 0;
	setCol(15, 0);
	setPos(80, 1);
	cout << "Enter : выполнить банковскую операцию";
	setPos(80, 2);
	cout << "Space : рандомно начислить или отнять деньги";
	setPos(80, 3);
	cout << "+ : добавить в очередь клиента";
	setPos(80, 4);
	cout << "- : удалить клиента из списка";
	size_t now = 0;
	while (bank.size())
	{
		if (delay > 5000)
		{
			delay = 0.0;
			bank.work();
		}
		press = getAsyncKey();
		if (press == ENTER)
		{
			delay = 0.0;
			bank.work();
		}
		if (press == SPACE)
		{
			delay = 0.0;
			bank.random();
		}
		if (press == '+')
		{
			delay = 0.0;
			bank.add(makeClient(), true);
		}
		if (press == '-' && bank.size())
		{
			delay = 0.0;
			now = 0;
			do
			{
				bank.activeClient(now, 12, 0);
				selectPress = _getch();
				if (selectPress == DOWN && now < bank.size() - 1)
				{
					bank.displayClient(now);
					now++;
				}
				else if (selectPress == UP && now)
				{
					bank.displayClient(now);
					now--;
				}
				else if (selectPress == ENTER)
				{
					bank.del(now);
					selectPress = ESC;
				}
			} while (selectPress != ESC);
		}
		delay += 0.1;
	}
}