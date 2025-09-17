#include <iostream>

//#define MAIN

//#define PART_1
//#define PART_2
//#define PART_3
//#define PART_4
//#define PART_5
//#define TASK

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

#ifdef PART_1
	const int size = 10;
	int students[size]; //= {5, 4, 4, 3, 4};
	for (int i = 0; i < size; i++) 
	{
		std::cin >> students[i];
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << students[i] << " ";
	}
	std::cout << std::endl;
#endif //PART_1

#ifdef PART_2
	int a = 5, b = 10;
	int* x, * y;
	std::cout << a << " " << &a << std::endl;
	x = &a;
	std::cout << *x << " " << x << std::endl;
	std::cout << b << " " << &b << std::endl;
	//*x - разменовывание
	y = &b;
	std::cout << *y << " " << y << std::endl;
	x = y;
	std::cout << a << " " << &a << std::endl;
	std::cout << *x << " " << x << std::endl;
	std::cout << b << " " << &b << std::endl;
	std::cout << *y << " " << y << std::endl;
	*x = 100;
	std::cout << a << " " << &a << std::endl;
	std::cout << *x << " " << x << std::endl;
	std::cout << b << " " << &b << std::endl;
	std::cout << *y << " " << y << std::endl;
	b = 50;
	std::cout << a << " " << &a << std::endl;
	std::cout << *x << " " << x << std::endl;
	std::cout << b << " " << &b << std::endl;
	std::cout << *y << " " << y << std::endl;
	x = nullptr;
#endif //PART_2

#ifdef PART_3	
	int* ptr = new int(5);
	std::cout << *ptr << std::endl;
	int b = 10;
	delete ptr;
	ptr = &b;
	std::cout << *ptr << std::endl;
#endif //PART_3

#ifdef PART_4
	int arr[5]{ 4,3,5,6,3 };
	int* ptr = &arr[0];

	for (int i = 0; i < 5; i++) 
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << *(ptr + i) << " ";
	}
	std::cout << std::endl;
	ptr = &arr[0];
	for (int i = 0; i < 5; i++)
	{
		std::cout << *(arr+i) << " ";
		ptr++;
	}
	std::cout << std::endl;
	ptr = &arr[0];
	for (int i = 0; i < 5; i++)
	{
		std::cout << ptr[i] << " ";
	}
	std::cout << std::endl;
#endif //PART_4
	
#ifdef PART_5
	int size;
	std::cin >> size;
	int* arr_d = new int[5];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr_d[i];
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << arr_d[i] << " ";
	}
	std::cout << std::endl;
	delete[]arr_d;
#endif //PART_5
	
#ifdef TASK
	int size1, size2;
	std::cout << "Введите размер первого массива: ";
	std::cin >> size1;
	std::cout << "Введите размер второго массива: ";
	std::cin >> size2;

	int* arr1 = new int[size1];
	int* arr2 = new int[size2];

	unsigned long seed = 42;
	for (int i = 0; i < size1; ++i) {
		seed = (1103515245 * seed + 12345) % 2147483648;
		arr1[i] = (seed % 100) + 1;
	}

	for (int i = 0; i < size2; ++i) {
		seed = (1103515245 * seed + 12345) % 2147483648;
		arr2[i] = (seed % 100) + 1;
	}

	std::cout << "Первый массив: ";
	for (int i = 0; i < size1; ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Второй массив: ";
	for (int i = 0; i < size2; ++i) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	int* arr3 = new int[size1 + size2];
	for (int i = 0; i < size1; ++i) {
		arr3[i] = arr1[i];
	}
	for (int i = 0; i < size2; ++i) {
		arr3[size1 + i] = arr2[i];
	}

	std::cout << "Объединённый массив: ";
	for (int i = 0; i < size1 + size2; ++i) {
		std::cout << arr3[i] << " ";
	}
	std::cout << std::endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
#endif //TASK
}
#endif //MAIN