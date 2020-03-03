#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
using namespace std;
//—оздайте класс Passport(паспорт), который будет содержать паспортную информацию о гражданине ”краниы.
//— помощью механизма наследовани€, реализуйте класс ForeignPassport(загран.паспорт) производный от Passport.
//Ќапомним, что загран.паспорт содержит помимо паспортных данных, также данные о визах, номер загран.паспорта.
//
//данные в паспорте :
//‘»ќ
//пол
//дата рождени€
//прописка
//гражданское состо€ние
//
//данные загран.паспорта:
//массив виз - место поездки, цель визита, дата начала, дата окончани€, просроченность визы(bool)
//
//«аполнение всех полей
//return дл€ каждого пол€
//установка пол€ просроченность визы если дата окончани€ - текуща€€ дата больше чем 25 дней
//метод дл€ вывода информации в каждом классе - в классе загран паспорта можно вызвать метод из базового класса, если така€ необходимость
//возникнет
class Passport {
	char* fio_, *pol_, *birsday_, *propiska_, *civil_status_;
public:
	Passport() {
		fio_ = nullptr;
		pol_ = nullptr;
		birsday_ = nullptr;
		propiska_ = nullptr;
		civil_status_ = nullptr;
		setfio("unknown");
		setpol("unknown");
		setbirsday("unknown");
		setpropiska("unknown");
		setcivil_status("unknown");
	}
	void setfio(const char* fio) {
		if (fio_ == nullptr)
		{
			fio_ = new char[strlen(fio) + 1];
		}
		else {
			delete[]fio_;
			fio_ = new char[strlen(fio) + 1];
		}
		strcpy(fio_, fio);
	}
	char* getfio()const {
		return fio_;
	}
	void setpol(const char* pol) {
		if (pol_ == nullptr)
		{
			pol_ = new char[strlen(pol) + 1];
		}
		else {
			delete[]pol_;
			pol_ = new char[strlen(pol) + 1];
		}
		strcpy(pol_, pol);
	}
	char* getpol()const {
		return pol_;
	}
	void setbirsday(const char* birsday) {
		if (birsday_ == nullptr)
		{
			birsday_ = new char[strlen(birsday) + 1];
		}
		else {
			delete[]birsday_;
			birsday_ = new char[strlen(birsday) + 1];
		}
		strcpy(birsday_, birsday);
	}
	char* getbirsday()const {
		return birsday_;
	}
	void setpropiska(const char* propiska) {
		if (propiska_ == nullptr)
		{
			propiska_ = new char[strlen(propiska) + 1];
		}
		else {
			delete[]propiska_;
			propiska_ = new char[strlen(propiska) + 1];
		}
		strcpy(propiska_, propiska);
	}
	char* getpropiska()const {
		return propiska_;
	}
	void setcivil_status(const char* civil_status) {
		if (civil_status_ == nullptr)
		{
			civil_status_ = new char[strlen(civil_status) + 1];
		}
		else {
			delete[]civil_status_;
			civil_status_ = new char[strlen(civil_status) + 1];
		}
		strcpy(civil_status_, civil_status);
	}
	char* getcivil_status()const {
		return civil_status_;
	}
	Passport(char* fio, char* pol, char* birsday, char* propiska, char* civil_status) {
		setfio(fio);
		setpol(pol);
		setbirsday(birsday);
		setpropiska(propiska);
		setcivil_status(civil_status);
	}
	void showpassport() {
		cout << "fio = " << fio_ << "\n";
		cout << "pol = " << pol_ << "\n";
		cout << "birsday = " << birsday_ << "\n";
		cout << "propiska = " << propiska_ << "\n";
		cout << "civil_status = " << civil_status_ << "\n";
	}
};
class ForeignPassport :public Passport {
	char* place_, *target_, *date_start_, *date_finich_;
public:
	ForeignPassport() {
		place_ = nullptr;
		target_ = nullptr;
		date_start_ = nullptr;
		date_finich_ = nullptr;
		setplace("unknown");
		settarget("unknown");
		setdate_start("unknown");
		setdate_finich("unknown");
	}
	void setplace(const char* place) {
		if (place_ == nullptr) {
			place_ = new char[strlen(place) + 1];
		}
		else {
			delete[]place_;
			place_ = new char[strlen(place) + 1];
		}
		strcpy(place_,place);
	}
	char* getplace()const {
		return place_;
	}
	void settarget(const char* target) {
		if (target_ == nullptr) {
			target_ = new char[strlen(target) + 1];
		}
		else {
			delete[]target_;
			target_ = new char[strlen(target) + 1];
		}
		strcpy(target_, target);
	}
	char* gettarget()const {
		return target_;
	}
	void setdate_start(const char* date_start) {
		if (date_start_ == nullptr) {
			date_start_ = new char[strlen(date_start) + 1];
		}
		else {
			delete[]date_start_;
			date_start_ = new char[strlen(date_start) + 1];
		}
		strcpy(date_start_, date_start);
	}
	char* getdate_start()const {
		return date_start_;
	}
	void setdate_finich(const char* date_finich) {
		if (date_finich_ == nullptr) {
			date_finich_ = new char[strlen(date_finich) + 1];
		}
		else {
			delete[]date_finich_;
			date_finich_ = new char[strlen(date_finich) + 1];
		}
		strcpy(date_finich_, date_finich);
	}
	char* getdate_finich()const {
		return date_finich_;
	}
	ForeignPassport(char* place, char*target, char*date_start, char*date_finich) {
		setplace(place);
		settarget(target);
		setdate_start(date_start);
		setdate_finich(date_finich);
	}
	void showForeignPassport() {
		cout << "place = " << place_ << "\n";
		cout << "target = " << target_ << "\n";
		cout << "date_start = " << date_start_ << "\n";
		cout << "date_finich = " << date_finich_ << "\n";
		Passport::showpassport();
	}
};
void main() {
	Passport a;
	a.setfio("Tolik Torman");
	a.setpol("men");
	a.setbirsday("19.04.1993");
	a.setpropiska("DDDDD");
	a.setcivil_status("ADFGEW");
	a.showpassport();
	cout << "\n\n";
	ForeignPassport b;
	b.showForeignPassport();
	b.Passport::showpassport();
	b.setplace("belg");
	b.settarget("www");
	b.setdate_start("kk");
	b.setdate_finich("adad");
	b.showForeignPassport();
	system("pause");
}