#include <iostream>

//#define MAIN

struct Date
{
    int day;
    int month;
    int year;
};

struct W_machine
{
    char f[20];
    char col[20];
    float w;
    float l;
    float h;
    float m;
    float sp;
    float temp;
};

struct cl_iron
{
    char f[20];
    char col[20];
    float min_temp;
    float max_temp;
    bool steam_supply;
    float m;
};

struct Car
{
    char col[20];
    float V;
    float l;
    float h;
    float m;
    float d;
    bool automat;
};

struct Boss
{
    char comp[22];
    Car m;
};

struct Employee
{
    char fio[65];
    Date start;
};

// Функции инициализации
void init(Car& a)
{
    std::cout << "Цвет машины: ";
    std::cin >> a.col;
    std::cout << "Объём двигателя: ";
    std::cin >> a.V;
    std::cout << "Длина: ";
    std::cin >> a.l;
    std::cout << "Высота: ";
    std::cin >> a.h;
    std::cout << "Мощность: ";
    std::cin >> a.m;
    std::cout << "Диаметр колёс: ";
    std::cin >> a.d;
    std::cout << "Коробка передач (1-автоматическая, 0-механическая): ";
    std::cin >> a.automat;
}

void init(Boss& a)
{
    std::cout << "Компания: ";
    std::cin.ignore();
    std::cin.getline(a.comp, 22);
    std::cout << "Машина: " << std::endl;
    init(a.m);
}

void init(Employee& e)
{
    std::cout << "ФИО: ";
    std::cin.ignore();
    std::cin.getline(e.fio, 65);
    std::cout << "Дата начала: " << std::endl;
    init(e.start);
}

void init(Date& d)
{
    std::cout << "Введите день: ";
    std::cin >> d.day;
    std::cout << "Введите месяц: ";
    std::cin >> d.month;
    std::cout << "Введите год: ";
    std::cin >> d.year;
    std::cout << std::endl;
}

void init(cl_iron& c)
{
    std::cout << "Введите фирму: ";
    std::cin >> c.f;
    std::cout << "Введите цвет: ";
    std::cin >> c.col;
    std::cout << "Введите подачу пара (1-да, 0-нет): ";
    std::cin >> c.steam_supply;
    std::cout << "Введите мощность: ";
    std::cin >> c.m;
    std::cout << "Введите минимальную температуру: ";
    std::cin >> c.min_temp;
    std::cout << "Введите максимальную температуру: ";
    std::cin >> c.max_temp;
    std::cout << std::endl;
}

void init(W_machine& c)
{
    std::cout << "Введите фирму: ";
    std::cin >> c.f;
    std::cout << "Введите цвет: ";
    std::cin >> c.col;
    std::cout << "Введите длину: ";
    std::cin >> c.l;
    std::cout << "Введите высоту: ";
    std::cin >> c.h;
    std::cout << "Введите ширину: ";
    std::cin >> c.w;
    std::cout << "Введите мощность: ";
    std::cin >> c.m;
    std::cout << "Введите скорость отжима: ";
    std::cin >> c.sp;
    std::cout << "Введите температуру нагрева: ";
    std::cin >> c.temp;
    std::cout << std::endl;
}

// Функции вывода
void show(const Car& a)
{
    std::cout << "Цвет: " << a.col << std::endl;
    std::cout << "Объём: " << a.V << std::endl;
    std::cout << "Длина: " << a.l << std::endl;
    std::cout << "Высота: " << a.h << std::endl;
    std::cout << "Мощность: " << a.m << std::endl;
    std::cout << "Диаметр колёс: " << a.d << std::endl;
    std::cout << "Коробка передач: " << (a.automat ? "Автоматическая" : "Механическая") << std::endl;
}

void show(const Boss& a)
{
    std::cout << "Компания: " << a.comp << std::endl;
    std::cout << "Машина: " << std::endl;
    show(a.m);
}

void show(const Employee& e)
{
    std::cout << "ФИО: " << e.fio << std::endl;
    std::cout << "Дата начала: ";
    show(e.start);
}

void show(const Date& d)
{
    std::cout << d.day << "." << d.month << "." << d.year << std::endl;
}

void show(const W_machine& c)
{
    std::cout << "Фирма: " << c.f << std::endl;
    std::cout << "Цвет: " << c.col << std::endl;
    std::cout << "Длина: " << c.l << std::endl;
    std::cout << "Высота: " << c.h << std::endl;
    std::cout << "Ширина: " << c.w << std::endl;
    std::cout << "Мощность: " << c.m << std::endl;
    std::cout << "Скорость отжима: " << c.sp << std::endl;
    std::cout << "Температура нагрева: " << c.temp << std::endl;
}

void show(const cl_iron& c)
{
    std::cout << "Фирма: " << c.f << std::endl;
    std::cout << "Цвет: " << c.col << std::endl;
    std::cout << "Мощность: " << c.m << std::endl;
    std::cout << "Минимальная температура: " << c.min_temp << std::endl;
    std::cout << "Максимальная температура: " << c.max_temp << std::endl;
    std::cout << "Подача пара: " << (c.steam_supply ? "да" : "нет") << std::endl;
}

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");

    Date d;
    init(d);
    show(d);

    W_machine c;
    init(c);
    show(c);

    int size;
    std::cout << "Введите количество утюгов: ";
    std::cin >> size;
    cl_iron* arr = new cl_iron[size];
    for (int i = 0; i < size; i++)
    {
        init(arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        show(arr[i]);
    }
    delete[] arr;

    Employee e;
    init(e);
    show(e);

    Car h;
    init(h);
    show(h);

    Boss t;
    init(t);
    show(t);
}
#endif //MAIN