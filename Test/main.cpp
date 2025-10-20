#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN

// Структура для бритвы
struct Britva
{
    char proizvoditel[50];
    char model[50];
};

// Структура для геля для бритья
struct GelDlyaBritya
{
    char marka[50];
    char tip[50];
};

// Структура для подарочного набора
struct PodarochnyiNabor
{
    char nazvanie[100];
    Britva britva;
    GelDlyaBritya gel;
};

// Функция инициализации одного подарочного набора
void init(PodarochnyiNabor& nabor)
{
    std::cout << "Введите название подарочного набора: ";
    std::cin.ignore();
    std::cin.getline(nabor.nazvanie, 100);

    std::cout << "--- Данные для бритвы ---" << std::endl;
    std::cout << "Производитель: ";
    std::cin.getline(nabor.britva.proizvoditel, 50);
    std::cout << "Модель: ";
    std::cin.getline(nabor.britva.model, 50);

    std::cout << "--- Данные для геля для бритья ---" << std::endl;
    std::cout << "Марка: ";
    std::cin.getline(nabor.gel.marka, 50);
    std::cout << "Тип (например, для чувствительной кожи): ";
    std::cin.getline(nabor.gel.tip, 50);
}

// Функция вывода информации о подарочном наборе
void printNabor(const PodarochnyiNabor& nabor)
{
    std::cout << "Название набора: " << nabor.nazvanie << "\n";
    std::cout << "Бритва:\n";
    std::cout << "  Производитель: " << nabor.britva.proizvoditel << "\n";
    std::cout << "  Модель: " << nabor.britva.model << "\n";
    std::cout << "Гель для бритья:\n";
    std::cout << "  Марка: " << nabor.gel.marka << "\n";
    std::cout << "  Тип: " << nabor.gel.tip << "\n\n";
}

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");
    const int MAX_NABORS = 100;
    PodarochnyiNabor nabors[MAX_NABORS];
    int naborCount = 0;

    std::cout << "Добавление нового подарочного набора:\n";
    init(nabors[naborCount]);
    naborCount++;

    for (int i = 0; i < naborCount; ++i)
    {
        printNabor(nabors[i]);
    }
}
#endif //MAIN
