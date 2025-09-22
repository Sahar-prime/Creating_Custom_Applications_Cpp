#include <iostream>

//#define MAIN

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	//генерация случайных чисел
	srand(time(nullptr));
	int a = rand();
	std::cout << a % 11+10 << std::endl; //a% - сколько чисел + с какого начать
	std::cout << a % 5 - 2 << std::endl;
	int start = 763, end = 871;
	std::cout << rand() % (end - start + 1) + start << std::endl;

	//генерация случайных массив
	int size;
	std::cout << "Введите кол-во элементов: ";
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

	//добавление числа в массив
	int newnumber;
	std::cout << "Введите добавляемое число: ";
	std::cin >> newnumber;
	int* arr2 = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
	delete[]arr;
	arr2[size] = newnumber;
	size++;
	arr = arr2;
	arr2 = nullptr;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	//удаление числа из массива
	int* arr3 = new int[size - 1];
	for (int i = 0; i < size-1; i++) 
	{
		arr3[i] = arr[i];
	}
	delete[]arr;
	arr = arr3;
	arr3 = nullptr;
	size--;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
#endif//MAIN