#include <iostream>

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//��������� ��������� �����
	srand(time(nullptr));
	int a = rand();
	std::cout << a % 11+10 << std::endl; //a% - ������� ����� + � ������ ������
	std::cout << a % 5 - 2 << std::endl;
	int start = 763, end = 871;
	std::cout << rand() % (end - start + 1) + start << std::endl;

	//��������� ��������� ������
	int size;
	std::cout << "������� ���-�� ���������: ";
	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size;i++) 
	{
		//arr[i] = rand() % (10 + 5 + 1) - 5; //-5 - 10
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//���������� ����� � ������
	int newnumber;
	std::cout << "������� ����������� �����: ";
	std::cin >> newnumber;
	int pos;
	std::cout << "���� ��������� �������: ";
	std::cin >> pos;
	int* arr2 = new int[size+1];
	for (int i = 0; i < size; i++)
	{
		/*(i < pos) ? arr2[i] = arr[i]: arr2[i + 1] = arr[i];
		if (i < pos) 
		{
			arr2[i] = arr[i];
		}
		else 
		{
			arr2[i + 1] = arr[i];
		}*/
		arr2[i + (i >= pos)] = arr[i];
	}
	delete[]arr;
	arr2[pos] = newnumber;
	size++;
	arr = arr2;
	arr2 = nullptr;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	int size_main, size_insert;
	std::cout << "����� ������ �������� �������: ";
	std::cin >> size_main;
	int* arr_main = new int[size_main];
	for (int i = 0; i < size_main; i++)
	{
		arr_main[i] = rand() % 10;
	}
	std::cout << "����� ������ ������������ �������: ";
	std::cin >> size_insert;
	int* arr_insert = new int[size_insert];
	for (int i = 0; i < size_insert; i++)
	{
		arr_insert[i] = rand() % 10;
	}
	std::cout << std::endl;
	std::cout << "����������� ������:\n";
	for (int i = 0; i < size_insert; i++)
	{
		std::cout << arr_insert[i] << " ";
	}
	std::cout << std::endl;
	int pos3;
	std::cout << "������� ������� ��� ������: ";
	std::cin >> pos3;
	int* new_arr = new int[size_main + size_insert];
	for (int i = 0; i < size_main; i++)
	{
		if (i < pos3)
		{
			new_arr[i] = arr_main[i];
		}
		else
		{
			new_arr[i + size_insert] = arr_main[i];
		}
	}
	for (int i = 0; i < size_insert; i++)
	{
		new_arr[i + pos3] = arr_insert[i];
	}
	delete[]arr_main;
	size_main += size_insert;
	arr_main = new_arr;
	new_arr = nullptr;
	for (int i = 0; i < size_main; i++)
	{
		std::cout << arr_main[i] << " ";
	}
	std::cout << std::endl;

	//�������� ����� �� �������
	int pos2;
	std::cout << "������ ������� �������: ";
	std::cin >> pos2;
	int* arr3 = new int[size - 1];
	for (int i = 0; i < size-1; i++) 
	{
		if (i != pos2)
		{
			arr3[i] = arr[i];
		}
		else
		{
			arr3[i] = arr[i + 1];
		}
	}
	delete[]arr;
	size--;
	arr = arr3;
	arr3 = nullptr;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
#endif//MAIN