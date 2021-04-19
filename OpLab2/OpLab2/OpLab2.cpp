#include <cstdio>
#include <cstdlib>
#include "STRING_A.h"

STRING DeleteDoubleLetter(STRING inputStr, char letter); 

int main()
{
	STRING str;
	str.Set("bbaa ca daraa eaaaa faaaaar");
	printf("Input Str: %s\n", str);
	str = DeleteDoubleLetter(DeleteDoubleLetter(str, 'a'), 'b');
	printf("Transform Str: %s\n", str);
	return 0;
}

STRING DeleteDoubleLetter(STRING inputStr, char letter)
{
	int size = 1; // Итоговое количество символов без повторяющихся letter
	int i, j = 1;
	char* tfStr;  // Итоговая строка без повторяющихся letter
	// Считаем количество повторяющихся символов 'a'
	for (i = 1; inputStr.SetGet(i) != '\0'; i++)
	{
		size++;
		// Если мы встретили символ letter
		if (inputStr.SetGet(i) == letter)
		{
			// Смотрим символ до этого letter
			if (inputStr.SetGet(i) == inputStr.SetGet(i - 1))
			{
				// Если они равны, то это повторяющийся символ
				size--;
			}
		}
	}
	// Добавляем символ конца строки
	size++;
	// Создаем строку
	tfStr = (char*)calloc(size, sizeof(char));
	if (!tfStr)
		return nullptr;
	// Присваиваем первый символ
	*tfStr = inputStr.SetGet(0);
	// Повторяем те же действия, только не записывая повторяющиеся символы
	for (i = 1; inputStr.SetGet(i) != '\0'; i++)
	{
		if (inputStr.SetGet(i) == letter)
		{
			if (inputStr.SetGet(i) == inputStr.SetGet(i - 1))
			{
				continue;
			}
			else
			{
				tfStr[j] = inputStr.SetGet(i);
				j++;
			}
		}
		else
		{
			tfStr[j] = inputStr.SetGet(i);
			j++;
		}
	}
	// Добавляем конец строки
	tfStr[size - 1] = '\0';
	STRING StrOut(tfStr);	
	return StrOut;
}
