#include <iostream>

// ������� ��� �������� ������ �� ���������� �������
void deleteRow(int**& arr, int& rows, int cols, int rowToDelete)
{
    if (rowToDelete < 0 || rowToDelete >= rows)
    {
        std::cout << "������������ ����� ������!" << std::endl;
        return;
    }

    // ������� ��������� ������
    delete[] arr[rowToDelete];

    // �������� ��������� �� ������
    for (int i = rowToDelete; i < rows - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    // ��������� ���������� �����
    --rows;

    // ���������������� ������ ��� ������� ����������
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
    std::cout << "������� ���������� �����: ";
    std::cin >> rows;
    std::cout << "������� ���������� ��������: ";
    std::cin >> cols;

    // ������� ��������� ������������ ������
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) 
        {
            // ��������� "����������������" �������
            arr[i][j] = (i * cols + j) * 7 % 100; // ������� ������� ��� ��������� �����
        }
    }

    // ������� ������ �� �����
    std::cout << "�������� ������:" << std::endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // ������� ������ �� ������
    int rowToDelete;
    std::cout << "������� ����� ������ ��� �������� (0-" << rows - 1 << "): ";
    std::cin >> rowToDelete;

    deleteRow(arr, rows, cols, rowToDelete);

    // ������� ���������� ������
    std::cout << "������ ����� �������� ������:" << std::endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // ����������� ������
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
