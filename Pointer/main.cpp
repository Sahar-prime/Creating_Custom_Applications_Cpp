#include <iostream>

//#define MAIN
//#define PART1
//#define PART2

#ifdef MAIN
int main()
{
	setlocale(LC_ALL, "");
#ifdef PART1
	//генерация случайных чисел
	srand(time(nullptr));
	int a = rand();
	std::cout << a % 11 + 10 << std::endl; //a% - сколько чисел + с какого начать
	std::cout << a % 5 - 2 << std::endl;
	int start = 763, end = 871;
	std::cout << rand() % (end - start + 1) + start << std::endl;

	//генерация случайных массив
	int size;
	std::cout << "Введите кол-во элементов: ";
	std::cin >> size;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
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
	int pos;
	std::cout << "Куда добавляем элемент: ";
	std::cin >> pos;
	int* arr2 = new int[size + 1];
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
	std::cout << "Введи размер основого массива: ";
	std::cin >> size_main;
	int* arr_main = new int[size_main];
	for (int i = 0; i < size_main; i++)
	{
		arr_main[i] = rand() % 10;
	}
	std::cout << "Введи размер вставляемого массива: ";
	std::cin >> size_insert;
	int* arr_insert = new int[size_insert];
	for (int i = 0; i < size_insert; i++)
	{
		arr_insert[i] = rand() % 10;
	}
	std::cout << std::endl;
	std::cout << "Вставляемый массив:\n";
	for (int i = 0; i < size_insert; i++)
	{
		std::cout << arr_insert[i] << " ";
	}
	std::cout << std::endl;
	int pos3;
	std::cout << "Введите позицию для ставки: ";
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

	//удаление числа из массива
	int pos2;
	std::cout << "Откуда удаляем элемент: ";
	std::cin >> pos2;
	int* arr3 = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
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
#endif //PART1
#ifdef PART2
	//двухмерные массивы
	int rows, cols;
	std::cout << "Введите размеры массива: ";
	std::cin >> rows >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	//генерация двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	//вывод двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//удаление двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;

	//трехмерные массивы
	int a, b, c;
	std::cout << "Введите размеры массива: ";
	std::cin >> a >> b >> c;
	int*** arr2 = new int** [a];
	for (int i = 0; i < a; i++)
	{
		arr2[i] = new int*[b];
		for (int j=0; j <b; j++) 
		{
			arr2[i][j] = new int[c];
		}
	}
	//генерация двухмерного массива
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				arr2[i][j][k] = rand() % 10;
			}
		}
	}
	//вывод двухмерного массива
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (int k = 0; k < c; k++)
			{
				std::cout << arr2[i][j][k] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	//удаление двухмерного массива
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			delete[]arr2[i][j];
		}
		delete[]arr2[i];
	}
	delete[]arr2;

	//четырехмерные массивы
	int e, f, g, h;
	std::cout << "Введите размеры массива: ";
	std::cin >> e >> f >> g >> h;
	// Выделение памяти для четырёхмерного массива
	int**** arr4 = new int*** [e];
	for (int i = 0; i < e; i++)
	{
		arr4[i] = new int** [f];
		for (int j = 0; j < f; j++) 
		{
			arr4[i][j] = new int* [g];
			for (int k = 0; k < g; k++) 
			{
				arr4[i][j][k] = new int[h];
			}
		}
	}
	// Генерация значений для четырёхмерного массива
	for (int i = 0; i < e; i++)
	{
		for (int j = 0; j < f; j++)
		{
			for (int k = 0; k < g; k++)
			{
				for (int l = 0; l < h; l++)
				{
					arr4[i][j][k][l] = rand() % 10;
				}
			}
		}
	}
	// Вывод четырёхмерного массива
	for (int i = 0; i < e; i++) 
	{
		for (int j = 0; j < f; j++)
		{
			for (int k = 0; k < g; k++) 
			{
				for (int l = 0; l < h; l++)
				{
					std::cout << arr4[i][j][k][l] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	// Освобождение памяти
	for (int i = 0; i < e; i++)
	{
		for (int j = 0; j < f; j++) 
		{
			for (int k = 0; k < g; k++) 
			{
				delete[] arr4[i][j][k];
			}
			delete[] arr4[i][j];
		}
		delete[] arr4[i];
	}
	delete[] arr4;

#endif //PART2
}
#endif//MAIN