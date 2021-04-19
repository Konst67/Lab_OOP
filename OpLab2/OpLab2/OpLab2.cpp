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
	int size = 1; // �������� ���������� �������� ��� ������������� letter
	int i, j = 1;
	char* tfStr;  // �������� ������ ��� ������������� letter
	// ������� ���������� ������������� �������� 'a'
	for (i = 1; inputStr.SetGet(i) != '\0'; i++)
	{
		size++;
		// ���� �� ��������� ������ letter
		if (inputStr.SetGet(i) == letter)
		{
			// ������� ������ �� ����� letter
			if (inputStr.SetGet(i) == inputStr.SetGet(i - 1))
			{
				// ���� ��� �����, �� ��� ������������� ������
				size--;
			}
		}
	}
	// ��������� ������ ����� ������
	size++;
	// ������� ������
	tfStr = (char*)calloc(size, sizeof(char));
	if (!tfStr)
		return nullptr;
	// ����������� ������ ������
	*tfStr = inputStr.SetGet(0);
	// ��������� �� �� ��������, ������ �� ��������� ������������� �������
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
	// ��������� ����� ������
	tfStr[size - 1] = '\0';
	STRING StrOut(tfStr);	
	return StrOut;
}
