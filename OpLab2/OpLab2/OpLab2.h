#pragma once
using namespace std;
class STRING_A
{
public:
	STRING_A(char str); /* Конструктор */
	char& SetGet(int i); /* Возвращение массива */
	void Print(char str); /* Вывод
	результатов на экран */
	STRING_A(const STRING_A& other); /* Конструктор копирования */
	~STRING_A(); /* Деструктор */
private:
	char** str;
	int i;
};