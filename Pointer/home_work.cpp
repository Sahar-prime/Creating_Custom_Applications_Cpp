#include <iostream>

//#define TASK_2
//#define TASK_3

#ifdef TASK_2
void reverseArray(int* arr, int size)
{
    int* start = arr;          // Указатель на начало массива
    int* end = arr + size - 1; // Указатель на конец массива

    while (start < end)
    {
        // Меняем местами элементы, на которые указывают start и end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Продвигаем указатели к центру массива
        ++start;
        --end;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr, size);

    std::cout << "Перевернутый массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
#endif //TASK_2

#ifdef TASK_3
void reverseCopy(int* source, int* dest, int size) 
{
    int* srcPtr = source;// Указатель на начало исходного массива
    int* destPtr = dest + size - 1;// Указатель на конец целевого массива

    for (int i = 0; i < size; ++i)
    {
        *destPtr = *srcPtr; // Копируем элемент из source в dest в обратном порядке
        ++srcPtr;           // Продвигаем указатель source вперед
        --destPtr;          // Продвигаем указатель dest назад
    }
}

int main() 
{
    setlocale(LC_ALL, "");
    int source[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(source) / sizeof(source[0]);

    int* dest = new int[size]; // Динамическое выделение памяти

    reverseCopy(source, dest, size);

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << source[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Копия в обратном порядке: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << dest[i] << " ";
    }
    std::cout << std::endl;

    delete[] dest; // Освобождение памяти
}
#endif //TASK_3