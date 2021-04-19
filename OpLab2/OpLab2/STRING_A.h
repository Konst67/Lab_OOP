#pragma once
class STRING
{
public:
	STRING();  // Конструктор
	STRING(const char* inputStr); // Конструктор с параметром
	~STRING(); // Деструктор
	void Set(const char* inputStr); // Присвоение строки целиком
	char& SetGet(int index); // Функция получение/присваивание значения индекса
	STRING(const STRING& other);// Конструктор копирования
private:
	char* str;  // Строка
	int size; // Размер строки
};
