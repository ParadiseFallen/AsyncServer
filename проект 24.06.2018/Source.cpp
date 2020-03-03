//Методы :
//заполнение всей группы
//вывод на экран всей группы
//показать по номеру
//метод для поиска самого успешного\двоечного(? !) человека по среднему баллу
//поиск самого успешного мальчика / самой успешной девочки
//вывод всех учеников женского пола / мужского пола
//перегрузить[] для получения определённого студента из группы
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
string names[5] = {"Anenko","Tkachuk","Starovoit","Krestenko","Sidorova"};
string pol[5] = { "m","m","m","w","w" };
class Student //Описать класс "Студент"
{
	//Описать поля :
	string pol;	//пол
	string surname;//Фамилия
	string name;//имя
public:
	struct Marks //список оценок по трём предметам(структурой)
	{
		int Maths;
		int Phusics;
		int Language;
	};
	//Описать методы :
	//заполнение каждого поля
	Marks a;
	Student()
	{
		pol = "unknown";
		surname = "unknown";
		name = "unknown";
		a.Maths = 0 + rand()% 9;
		a.Phusics = 0 + rand() % 10;
		a.Language = 0 + rand() % 12;
	}	
	//get, set для каждого поля
	void setPol(string pol_){
		pol = pol_;
	}
	string getPol() {
		return pol;
	}
	void setSurname(string surname_){
		surname = surname_;
	}
	string getSurname() {
		return surname;
	}
	void setName(string name_) {
		name = name_;
	}
	string getName() {
		return name;
	}
	void setMath(int Maths_) {
		a.Maths = Maths_;
	}
	int getMath() {
		return a.Maths;
	}
	void setPhusics(int Phusics_) {
		a.Maths = Phusics_;
	}
	int getPhusics() {
		return a.Phusics;
	}
	void setLanguage(int Language_) {
		a.Language = Language_;
	}
	int getLanguage() {
		return a.Language;
	}	
	//распечатать информацию по студенту
	void showInformation() {
		cout << "Pol : "<< pol << endl;
		cout << "Surname : "<< surname << endl;
		cout << "Name : "<< name << endl;
		cout << "Maths's mark : " << a.Maths << endl;
		cout << "Phusics's mark : " << a.Phusics << endl;
		cout << "Language's mark : " << a.Language << endl;
	}
	
	};
//Описать класс "Группа", состоящий из динамического массива студентов

class group {
	Student *mygroup;
	int length;
public :
	void setLength(int length_) {
		if (mygroup!=NULL)
		{
			delete[]mygroup;
		}
		length = length_;
		mygroup = new Student[length];
	}
	group() {
		mygroup = NULL;
		setLength(2);
	}
	void setGroup() {
		int p;
		for (size_t i = 0; i < length; i++)
		{
			p = rand() % 5;
			mygroup[i].setName(names[p]);
			mygroup[i].setPol(pol[p]);
		}
	}
	void showGroup() {
		for (size_t i = 0; i < length; i++)
		{
			mygroup[i].showInformation();
		}
	}

};


void main() {
	group a;
	a.setLength(5);
	a.setGroup();
	a.showGroup();
		
	
	
	system("pause");
}