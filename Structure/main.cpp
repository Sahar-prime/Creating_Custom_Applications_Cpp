#include <iostream>

//#define MAIN

struct Student
{
	char fio[50];
	int marks[3];
};

struct Class 
{
	char name[4]; //11б\0
	/*Student stud[3];*/
	Student* stud;
	int counter;
};

struct Product 
{
	char productName[50];
	double productPrice; 
};

struct Order 
{
	int orderNumber;     
	Product* products;
	int productCount;  
};

// Функции инициализации
void init(Product& p)
{
	std::cout << "Название товара: ";
	std::cin.get();
	std::cin.getline(p.productName, 50);
	std::cout << "Цена товара: ";
	std::cin >> p.productPrice;
}

void init(Order& o)
{
	std::cout << "Номер заказа: ";
	std::cin >> o.orderNumber;
	std::cin.get();

	std::cout << "Количество товаров: ";
	std::cin >> o.productCount;
	std::cin.get();

	o.products = new Product[o.productCount];

	for (int i = 0; i < o.productCount; ++i)
	{
		std::cout << "\nТовар #" << i + 1 << ":" << std::endl;
		init(o.products[i]);
	}
}

void init(Student& a) 
{
	std::cout << "Введите ФИО: ";
	//std::cin >> a.fio;
	std::cin.getline(a.fio, 50);
	std::cout << "Введите оценки: ";
	for (int i = 0; i < 3; i++) 
	{
		std::cin >> a.marks[i];
	}
}

void init(Class& c)
{
	std::cout << "Введите класс: ";
	std::cin >> c.name;
	std::cout << "Введите кол-во студентов: ";
	std::cin >> c.counter;
	c.stud = new Student[c.counter];
	for (int i = 0; i < c.counter; i++) 
	{
		getchar();
		std::cout << "Введите ФИО: ";
		//std::cin >> a.fio;
		std::cin.getline(c.stud[i].fio, 50);
		std::cout << "Введите оценки: ";
		for (int i = 0; i < 3; i++)
		{
			std::cin >> c.stud[i].marks[i];
		}
	}
}

// Функции вывода
void show(const Product& p)
{
	std::cout << "Товар: " << p.productName << ", Цена: " << p.productPrice << std::endl;
}

void show(const Order& o)
{
	std::cout << "\nНомер заказа: " << o.orderNumber << std::endl;
	std::cout << "Список товаров:" << std::endl;
	for (int i = 0; i < o.productCount; ++i)
	{
		show(o.products[i]);
	}
}

void show(const Class c)
{
	std::cout << "Класс: " << c.name << std::endl;
	std::cout << "Оценки: ";
	for (int i = 0; i < c.counter; i++)
	{
		std::cout << c.stud[i].marks[i];
	}
	std::cout << std::endl;
}

void show(const Student a)
{
	std::cout << "Фио: " << a.fio << std::endl;
	std::cout << "Оценки: ";
	for (int i = 0; i < 3; i ++) 
	{
		std::cout << a.marks[i] << " ";
	}
	std::cout << std::endl;
}

#ifdef MAIN
int main() 
{
	setlocale(LC_ALL, "");

	Class c;
	init(c);
	show(c);

	Order order;
	init(order);
	show(order);


}
#endif //MAIN