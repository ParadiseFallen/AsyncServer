/*
Пользователь вводит строку с клавиатуры.
1. Проверить является ли строка палиндромом. (Палиндром - это выражение, которое читается одинаково слева направо и справа налево).
Из строки нужно убрать всё, что не является буквой, цифрой или знаком пунтуации. Кроме того, сравнение должно происходить без учёта регистра.

2. Напечатать самое длинное и самое короткое слово в этой строке.
3. После каждого предложения добавьте смайлик ( :) ) в строке:

Я очень гордился тем, что попал в команду для полета на Марс – кто бы отказался прогуляться по чужой планете!Но... меня забыли. Бросили, раненого и растерянного, и корабль улетел.В лучшем случае я смогу протянуть в спасательном модуле 400 суток. Что же делать – разыскать в безбрежных красных песках поврежденную бурей антенну, попытаться починить ее, чтобы связаться с базовым кораблем и напомнить о своем существовании? Или дожидаться прибытия следующей экспедиции, которая прилетит только через ЧЕТЫРЕ ГОДА?Где брать еду? Воду? Воздух?Как не сойти с ума от одиночества?Робинзону было легче... у него хотя бы был Пятница.

Результат выведите на экран

4. Найдите все имена в строке - т.е. все слова, начинающиеся с Карл и Клар.
После -  выведите их на экран.

Карл у Клары забрал кораллы, Клара у Карла забрала кларнет. Карлуша был хорошим мальчиком, его связывали тёплые. дружески отношения с Кларочкой.

5. Пользователь вводит строку. Перевернуть каждое слово, в котором есть хотя бы три гласных букв.
Вывести изменённую строку на экран.
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <functional>

void ToLowerString(std::string &Text)
{
	std::transform(Text.begin(), Text.end(), Text.begin(),
		[](unsigned char c) { return std::tolower(c); });
	std::cout << "Text : " << Text << "\n";
}

void ClearString(std::string &Text) {
	Text.erase(
		std::remove_if(Text.begin(), Text.end(), &isdigit),
		Text.end());
	Text.erase(
		std::remove_if(Text.begin(), Text.end(), &ispunct),
		Text.end());
}

bool IsPalindrome(std::string Test) {
	ClearString(Test);
	ToLowerString(Test);
	std::string t = Test;
	std::reverse(t.begin(), t.end());
	return Test == t;
}

bool Min(std::string& a, std::string& b)
{
	a.shrink_to_fit();
	b.shrink_to_fit();
	return b.size() > a.size();
}
bool Max(std::string& a, std::string& b)
{
	a.shrink_to_fit();
	b.shrink_to_fit();
	return b.size()<a.size();
}

std::string GetFirstWord(std::string& text) 
{
	std::string text2="";

	for (char character : text)
	{
		if ((bool)isalpha(character))
		{
			text2 += character;
		}
		else
		{
			break;
		}
	}
	return text2;
}

std::string FindMinMaxWord(std::string text,bool (*comparator)(std::string&,std::string&))
{
	std::string tmpWord = "";
	std::string word = "";
	
	for (char character : text)
	{
		if ((bool)isalpha(character))
		{
			tmpWord += character;
		}
		else
		{
			if (comparator(tmpWord,word))
			{
				word = tmpWord;
			}
			tmpWord = "";
		}
	}
	return word;
}



void FindMinMaxWord(std::string Text) {
	std::cout << "Min : " << FindMinMaxWord(Text, &Min) << "\n";
	std::cout << "Max : " << FindMinMaxWord(Text, &Max) << "\n";
}
void main()
{
	std::string s;
	//std::cout << "Enter palindrome : ";
	//std::cin >> s;
	//std::cout << (IsPalindrome(s) ? ("Palindrome") : ("Not palindrome")) << "\nEnter sentencies :" << std::endl;
	std::getline(std::cin, s);
	FindMinMaxWord(s);


}
