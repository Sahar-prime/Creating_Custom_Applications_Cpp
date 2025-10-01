#include <iostream>

//#define MAIN

struct Date //Пользовательский тип данных
{
	int day;//поля
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

void init(Date& d)
{
	std::cout << "Введите день: ";
	std::cin >> d.day;
	std::cout << "Введите месяц: ";
	std::cin >> d.month;
	std::cout << "Введите год: ";
	std::cin >> d.year;
}

Date init()
{
	Date d;
	std::cout << "Введите день: ";
	std::cin >> d.day;
	std::cout << "Введите месяц: ";
	std::cin >> d.month;
	std::cout << "Введите год: ";
	std::cin >> d.year;
	return d;
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
	std::cout << "Введите тепмературу нагрева: ";
	std::cin >> c.temp;
}

void show(const Date& d) 
{
	std::cout << d.day << "." << d.month << "." << d.year << std::endl;
}

void show(const W_machine& c)
{
	std::cout << "Длина: " << c.l <<std::endl;
	std::cout << "Высота: " << c.h << std::endl;
	std::cout << "Ширина: " << c.w << std::endl;
	std::cout << "Мощность: " << c.m << std::endl;
	std::cout << "Скорость отжима: " << c.sp << std::endl;
	std::cout << "Тепмература нагрева: " << c.temp << std::endl;
	std::cout << "Цвет: " << c.col << std::endl;
	std::cout << "Фирма: " << c.f << std::endl;
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
}
#endif //MAIN