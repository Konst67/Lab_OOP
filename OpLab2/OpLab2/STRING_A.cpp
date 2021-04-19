#include "STRING_A.h"
#include <cstdlib>
#include <cstdio>

STRING::STRING()
{
	size = 0;
	str = nullptr;
}

STRING::STRING(const char* inputStr)
{
	int i;
	size = 0;
	for (i = 0; inputStr[i] != '\0'; i++)
	{
		size++;
	}
	size++;
	str = (char*)calloc(size, sizeof(char));
	if (str)
	{
		for (i = 0; i < inputStr[i] != '\0'; i++)
		{
			str[i] = inputStr[i];
		}
		str[i] = '\0';
	}
	else
		size = 0;
}

STRING::STRING(const STRING& other) //Конструктор копирования
	:size(other.size)
{
	str = new char[size];
	for (int i = 0; i < size; i++)
		str[i] = other.str[i];
}

STRING::~STRING() // Деструктор
{
	str = nullptr;
	free(str);
}

char& STRING::SetGet(int index) //Получение индекса
{
	if (index < 0)
		return str[0];
	if (index > size)
		return str[size - 1];
	return str[index];
}
 
void STRING::Set(const char* inputStr) // Получение строки 
{
	int i;
	free(str);
	str = nullptr;
	for (i = 0; inputStr[i] != '\0'; i++)
	{
		size++;
	}
	size++;
	str = (char*)calloc(size, sizeof(char));
	if (!str)
	{
		size = 0;
		return;
	}
	for (i = 0; i < inputStr[i] != '\0'; i++)
	{
		str[i] = inputStr[i];
	}
	str[i] = '\0';
}


