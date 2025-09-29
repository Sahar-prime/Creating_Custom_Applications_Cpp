#include <iostream>

// Функция для удаления строки из двумерного массива
void deleteRow(int**& arr, int& rows, int cols, int rowToDelete)
{
    if (rowToDelete < 0 || rowToDelete >= rows)
    {
        std::cout << "Некорректный номер строки!" << std::endl;
        return;
    }

    // Удаляем выбранную строку
    delete[] arr[rowToDelete];

    // Сдвигаем указатели на строки
    for (int i = rowToDelete; i < rows - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    // Уменьшаем количество строк
    --rows;

    // Перераспределяем память для массива указателей
    int** newArr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    arr = newArr;
}

int main() 
{
    setlocale(LC_ALL, "");

    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    // Создаем двумерный динамический массив
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            // Заполняем "псевдослучайными" числами
            arr[i][j] = (i * cols + j) * 7 % 100; // Простая формула для генерации чисел
        }
    }

    // Выводим массив на экран
    std::cout << "Исходный массив:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Удаляем строку по номеру
    int rowToDelete;
    std::cout << "Введите номер строки для удаления (0-" << rows - 1 << "): ";
    std::cin >> rowToDelete;

    deleteRow(arr, rows, cols, rowToDelete);

    // Выводим измененный массив
    std::cout << "Массив после удаления строки:" << std::endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождаем память
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
