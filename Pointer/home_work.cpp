#include <iostream>

//#define TASK_2
//#define TASK_3

#ifdef TASK_2
void reverseArray(int* arr, int size)
{
    int* start = arr;          // ��������� �� ������ �������
    int* end = arr + size - 1; // ��������� �� ����� �������

    while (start < end)
    {
        // ������ ������� ��������, �� ������� ��������� start � end
        int temp = *start;
        *start = *end;
        *end = temp;

        // ���������� ��������� � ������ �������
        ++start;
        --end;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "�������� ������: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr, size);

    std::cout << "������������ ������: ";
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
    int* srcPtr = source;// ��������� �� ������ ��������� �������
    int* destPtr = dest + size - 1;// ��������� �� ����� �������� �������

    for (int i = 0; i < size; ++i)
    {
        *destPtr = *srcPtr; // �������� ������� �� source � dest � �������� �������
        ++srcPtr;           // ���������� ��������� source ������
        --destPtr;          // ���������� ��������� dest �����
    }
}

int main() 
{
    setlocale(LC_ALL, "");
    int source[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(source) / sizeof(source[0]);

    int* dest = new int[size]; // ������������ ��������� ������

    reverseCopy(source, dest, size);

    std::cout << "�������� ������: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << source[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "����� � �������� �������: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << dest[i] << " ";
    }
    std::cout << std::endl;

    delete[] dest; // ������������ ������
}
#endif //TASK_3