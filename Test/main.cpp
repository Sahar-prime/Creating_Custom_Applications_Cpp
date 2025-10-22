#include <iostream>

//#define MAIN

using namespace std;

//Структура для бритвы (2 характеристики)
struct Britva
{
    char proizvoditel[50];
    char model[50];
};

//Структура для геля для бритья (2 характеристики)
struct GelDlyaBritya
{
    char marka[50];
    char tip[50];
};

//Структура для подарочного набора
struct PodarochnyiNabor
{
    char nazvanie[100];
    Britva britva;
    GelDlyaBritya gel;
};

//Функция ввода
void entering_information(PodarochnyiNabor& nabor)
{
    cout << "Введите название подарочного набора: ";
    cin.getline(nabor.nazvanie, 100);
    //Ввод данных для бритвы
    cout << "--- Данные для бритвы ---" << endl;
    cout << "Производитель: ";
    cin.getline(nabor.britva.proizvoditel, 50);
    cout << "Модель: ";
    cin.getline(nabor.britva.model, 50);
    //Ввод данных для геля
    cout << "--- Данные для геля для бритья ---" << endl;
    cout << "Марка: ";
    cin.getline(nabor.gel.marka, 50);
    cout << "Тип (например, для чувствительной кожи): ";
    cin.getline(nabor.gel.tip, 50);
}

//Функция вывода
void printed_information(const PodarochnyiNabor& nabor)
{
    cout << endl << "--- Содержимое подарочного набора ---" << endl;
    cout << "Название набора: " << nabor.nazvanie << endl;
    cout << "Бритва:" << endl;
    cout << "  Производитель: " << nabor.britva.proizvoditel << endl;
    cout << "  Модель: " << nabor.britva.model << endl;
    cout << "Гель для бритья:" << endl;
    cout << "  Марка: " << nabor.gel.marka << endl;
    cout << "  Тип: " << nabor.gel.tip << endl;
}

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");

    PodarochnyiNabor product;
    entering_information(product);
    printed_information(product);
}
#endif //MAIN