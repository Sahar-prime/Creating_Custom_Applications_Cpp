#include <iostream>

//#define MAIN
//#define PART1
//#define PART2

// Функция для транспонирования матрицы
int** transposeMatrix(int** matrix, int rows, int cols) 
{
	// Создаём новую матрицу с размерами cols x rows
	int** transposed = new int* [cols];
	for (int i = 0; i < cols; i++)
	{
		transposed[i] = new int[rows];
	}
	// Заполняем новую матрицу транспонированными элементами
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			transposed[j][i] = matrix[i][j];
		}
	}
	return transposed;
}

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
	// Двухмерные массивы
	int rows, cols;
	std::cout << "Введите размеры массива: ";
	std::cin >> rows >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	// Генерация двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	// Вывод двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Удаление двухмерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;

	// Трехмерные массивы
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
	// Генерация двухмерного массива
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
	// Вывод двухмерного массива
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
	// Удаление двухмерного массива
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			delete[]arr2[i][j];
		}
		delete[]arr2[i];
	}
	delete[]arr2;

	// Четырехмерные массивы
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
	
	// Попарное сложение строк трехмерного массива
	int rows3, cols3;
	std::cout << "Введите размеры массива: ";
	std::cin >> rows3 >> cols3;
	// Создание и заполнение исходного массива
	int** arr5 = new int* [rows3];
	for (int i = 0; i < rows3; i++) 
	{
		arr5[i] = new int[cols3];
	}
	// Заполнение массива случайными числами (без rand())
	for (int i = 0; i < rows3; i++)
	{
		for (int j = 0; j < cols3; j++)
		{
			arr5[i][j] = (i * cols3 + j) % 10; // Простое заполнение для примера
		}
	}
	// Вывод исходного массива
	std::cout << "Исходный массив:" << std::endl;
	for (int i = 0; i < rows3; i++) 
	{
		for (int j = 0; j < cols3; j++) 
		{
			std::cout << arr5[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// Определение размера нового массива
	int newCols = (cols3 + 1) / 2; // Округление вверх
	int** newArr = new int* [rows3];
	for (int i = 0; i < rows3; i++) 
	{
		newArr[i] = new int[newCols];
	}
	// Суммирование элементов попарно
	for (int i = 0; i < rows3; i++)
	{
		for (int j = 0; j < newCols; j++) 
		{
			int sum = arr5[i][2 * j];
			if (2 * j + 1 < cols)
			{
				sum += arr5[i][2 * j + 1];
			}
			newArr[i][j] = sum;
		}
	}
	// Вывод нового массива
	std::cout << "\nНовый массив (попарные суммы):" << std::endl;
	for (int i = 0; i < rows3; i++)
	{
		for (int j = 0; j < newCols; j++)
		{
			std::cout << newArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// Удаление массивов
	for (int i = 0; i < rows3; i++) 
	{
		delete[] arr5[i];
		delete[] newArr[i];
	}
	delete[] arr5;
	delete[] newArr;

	// Транспонирование матрицы двухмерного массива
	int rows6, cols6;
	std::cout << "Введите размеры массива: ";
	std::cin >> rows6 >> cols6;
	// Создание и заполнение исходной матрицы
	int** arr6 = new int* [rows6];
	for (int i = 0; i < rows6; i++)
	{
		arr6[i] = new int[cols6];
	}
	for (int i = 0; i < rows6; i++) 
	{
		for (int j = 0; j < cols6; j++) 
		{
			arr6[i][j] = rand() % 10;
		}
	}
	// Вывод исходной матрицы
	std::cout << "Исходная матрица:" << std::endl;
	for (int i = 0; i < rows6; i++) 
	{
		for (int j = 0; j < cols6; j++) 
		{
			std::cout << arr6[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// Использование функции
	int** transposedArr = transposeMatrix(arr6, rows6, cols6);
	// Вывод транспонированной матрицы
	std::cout << "\nТранспонированная матрица:" << std::endl;
	for (int i = 0; i < cols6; i++)
	{
		for (int j = 0; j < rows6; j++) 
		{
			std::cout << transposedArr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// Освобождение памяти
	for (int i = 0; i < rows6; i++) 
	{
		delete[] arr6[i];
	}
	delete[] arr6;
	for (int i = 0; i < cols6; i++)
	{
		delete[] transposedArr[i];
	}
	delete[] transposedArr;
#endif //PART2
}
#endif//MAIN