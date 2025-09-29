#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

// ����������� ����� ������
int mystrlen(const char* str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

// ����������� ������ str2 � str1
char* mystrcpy(char* str1, const char* str2)
{
	int i = 0;
	while (str2[i] != '\0')
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return str1;
}

// ������������ �����: ������������ str2 � str1
char* mystrcat(char* str1, const char* str2)
{
	int len1 = mystrlen(str1);
	int len2 = mystrlen(str2);
	for (int i = 0; i <= len2; i++)
	{
		str1[len1 + i] = str2[i];
	}
	return str1;
}

// ����� ������� s � ������ str
char* mystrchr(char* str, char s)
{
	while (*str != '\0')
	{
		if (*str == s)
		{
			return str;
		}
		str++;
	}
	return nullptr; // 0, ���� ������ �� ������
}

// ����� ��������� str2 � ������ str1
char* mystrstr(char* str1, char* str2)
{
	int len2 = mystrlen(str2);
	if (len2 == 0)
	{
		return str1;
	}

	while (*str1 != '\0')
	{
		char* begin = str1;
		char* pattern = str2;
		while (*begin != '\0' && *pattern != '\0' && *begin == *pattern)
		{
			begin++;
			pattern++;
		}
		if (*pattern == '\0')
		{
			return str1;
		}
		str1++;
	}
	return nullptr; // 0, ���� ��������� �� �������
}

#ifdef MAIN
void main()
{
	setlocale(LC_ALL, "");

	//int arr[] = { 1,2,3 };
	char str[10]; //= "Hello";
	std::cin >> str;
	std::cout << str << std::endl;
	//����� ������
	std::cout << strlen(str) << std::endl;
	//strcat() - ������������ (�������� �����)
	char str1[10] = "qwerty";
	char str2[20] = "test";
	strcat(str2, str1);
	//strcat_s(str2, strlen(str1)+strlen(str2) + 1, str1);
	std::cout << str2 << std::endl;
	//strcpy() - ����������� ������
	char copy[20];
	strcpy(copy, str2);
	std::cout << copy << std::endl;
	if (strstr(copy, "qwe")) //��������� ��������� �� ������ ���������
	{
		std::cout << "���������\n";
	}
	else
	{
		std::cout << "�� ���������\n";
	}
	//strchr(copy, "a");
	_strupr(copy);
	std::cout << copy << std::endl;
	_strlwr(copy);
	std::cout << copy << std::endl;
	copy[3] = toupper(copy[3]);
	std::cout << copy << std::endl;
	copy[3] = tolower(copy[3]);
	std::cout << copy << std::endl;
	char* ptr = new char[strlen(str1) + strlen(str2) + 1];
	strcpy(ptr, str1);
	strcat(ptr, str2);
	std::cout << ptr << std::endl;
	delete[]ptr;

	//��������� � 3 ������� � ��������: ���
	//������� ��� � ����� ������ (��������)
	char surname[50];
	char name[50];
	char patronymic[50];
	// ������ ������ � ��������
	std::cout << "������� �������: ";
	std::cin >> surname;
	std::cout << "������� ���: ";
	std::cin >> name;
	std::cout << "������� ��������: ";
	std::cin >> patronymic;
	// ��������� ����� ����� ��� ������������ ������
	int fullLength = strlen(surname) + strlen(name) + strlen(patronymic) + 3; // +2 ��� �������� � +1 ��� '\0'
	// �������� ������ ��� ����� ������
	char* fullName = new char[fullLength];
	// �������� ��� � ���� ������
	strcpy(fullName, surname);
	strcat(fullName, " ");
	strcat(fullName, name);
	strcat(fullName, " ");
	strcat(fullName, patronymic);
	// ������� ���������
	std::cout << "������ ���: " << fullName << std::endl;
	// ����������� ���������� ������
	delete[] fullName;
	std::cout << strcmp(str1, str2) << std::endl;
	char s1[10] = "cat123";
	char s2[10] = "cat";
	if (strcmp(s1, s2) < 0)
	{
		std::cout << "������ ������ ������\n";
	}
	else if (strcmp(s1, s2) > 0)
	{
		std::cout << "������ ������ ������\n";
	}
	else
	{
		std::cout << "������ �����\n";
	}

}
#endif //MAIN