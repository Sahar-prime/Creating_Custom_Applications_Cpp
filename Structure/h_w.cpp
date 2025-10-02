#include <iostream>

//#define H_W

struct boiler
{
    char f[20];
    char col[20];
    float V;
    float power;
    float temp;
};

void init(boiler& parameters)
{
    std::cout << "Введите фирму: ";
    std::cin >> parameters.f;
    std::cout << "Введите цвет: ";
    std::cin >> parameters.col;
    std::cout << "Введите мощность: ";
    std::cin >> parameters.power;
    std::cout << "Введите объем: ";
    std::cin >> parameters.V;
    std::cout << "Введите температуру нагрева: ";
    std::cin >> parameters.temp;
    std::cout << std::endl;
}

void show(const boiler& parameters)
{
    std::cout << "Фирма: " << parameters.f << std::endl;
    std::cout << "Цвет: " << parameters.col << std::endl;
    std::cout << "Мощность: " << parameters.power << std::endl;
    std::cout << "Объем: " << parameters.V << std::endl;
    std::cout << "Температура нагрева: " << parameters.temp << "°C" << std::endl;
}

#ifdef H_W
void main() 
{
    setlocale(LC_ALL, "");

    int size;
    std::cout << "Введите количество бойлеров: ";
    std::cin >> size;
    boiler* arr = new boiler[size];
    for (int i = 0; i < size; i++)
    {
        init(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        show(arr[i]);
        std::cout << std::endl;
    }
    delete[] arr;
}
#endif //H_W