#include <iostream>

//#define H_W

#ifdef H_W
int main()
{
    setlocale(LC_ALL, "");
    int size_main;
    std::cout << "Введи размер основного массива: ";
    std::cin >> size_main;

    int* arr_main = new int[size_main];
    for (int i = 0; i < size_main; i++)
    {
        arr_main[i] = rand() % 10;
    }

    std::cout << "Исходный массив:\n";
    for (int i = 0; i < size_main; i++)
    {
        std::cout << arr_main[i] << " ";
    }
    std::cout << std::endl;

    int pos, length;
    std::cout << "Введите позицию начала удаления: ";
    std::cin >> pos;
    std::cout << "Введите количество удаляемых элементов: ";
    std::cin >> length;

    // Проверка корректности ввода
    if (pos < 0 || length < 0 || pos + length > size_main)
    {
        std::cout << "Некорректные данные для удаления.\n";
        return 1;
    }

    int new_size = size_main - length;
    int* new_arr = new int[new_size];

    // Копируем элементы до позиции удаления
    for (int i = 0; i < pos; i++)
    {
        new_arr[i] = arr_main[i];
    }

    // Копируем элементы после блока удаления
    for (int i = pos + length; i < size_main; i++)
    {
        new_arr[i - length] = arr_main[i];
    }

    delete[] arr_main;
    arr_main = new_arr;
    size_main = new_size;

    std::cout << "Массив после удаления:\n";
    for (int i = 0; i < size_main; i++)
    {
        std::cout << arr_main[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr_main;
}
#endif //H_W