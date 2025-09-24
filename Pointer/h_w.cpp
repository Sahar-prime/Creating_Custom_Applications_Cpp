#include <iostream>

//#define H_W

#ifdef H_W
int main()
{
    setlocale(LC_ALL, "");
    int size_main;
    std::cout << "����� ������ ��������� �������: ";
    std::cin >> size_main;

    int* arr_main = new int[size_main];
    for (int i = 0; i < size_main; i++)
    {
        arr_main[i] = rand() % 10;
    }

    std::cout << "�������� ������:\n";
    for (int i = 0; i < size_main; i++)
    {
        std::cout << arr_main[i] << " ";
    }
    std::cout << std::endl;

    int pos, length;
    std::cout << "������� ������� ������ ��������: ";
    std::cin >> pos;
    std::cout << "������� ���������� ��������� ���������: ";
    std::cin >> length;

    // �������� ������������ �����
    if (pos < 0 || length < 0 || pos + length > size_main)
    {
        std::cout << "������������ ������ ��� ��������.\n";
        return 1;
    }

    int new_size = size_main - length;
    int* new_arr = new int[new_size];

    // �������� �������� �� ������� ��������
    for (int i = 0; i < pos; i++)
    {
        new_arr[i] = arr_main[i];
    }

    // �������� �������� ����� ����� ��������
    for (int i = pos + length; i < size_main; i++)
    {
        new_arr[i - length] = arr_main[i];
    }

    delete[] arr_main;
    arr_main = new_arr;
    size_main = new_size;

    std::cout << "������ ����� ��������:\n";
    for (int i = 0; i < size_main; i++)
    {
        std::cout << arr_main[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr_main;
}
#endif //H_W