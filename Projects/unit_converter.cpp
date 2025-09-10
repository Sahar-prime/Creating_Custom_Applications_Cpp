#include <iostream>
//#define UNIT_CONVERTER

using namespace std;

// Конвертация температуры
void convertTemperature()
{
    int choice;
    double value;
    cout << "Выберите направление конвертации:\n";
    cout << "1. °C → °F\n";
    cout << "2. °F → °C\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << "Введите значение: ";
    cin >> value;

    if (choice == 1) 
    {
        double result = value * 9.0 / 5.0 + 32;
        cout << value << " °C = " << result << " °F\n";
    }
    else if (choice == 2) 
    {
        double result = (value - 32) * 5.0 / 9.0;
        cout << value << " °F = " << result << " °C\n";
    }
    else
    {
        cout << "Некорректный выбор.\n";
    }
}

// Конвертация длины
void convertLength()
{
    int choice;
    double value;
    cout << "Выберите направление конвертации:\n";
    cout << "1. Метры → Километры\n";
    cout << "2. Километры → Метры\n";
    cout << "3. Метры → Мили\n";
    cout << "4. Мили → Метры\n";
    cout << "5. Километры → Мили\n";
    cout << "6. Мили → Километры\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << "Введите значение: ";
    cin >> value;

    switch (choice)
    {
    case 1:
        cout << value << " м = " << value / 1000 << " км\n";
        break;
    case 2:
        cout << value << " км = " << value * 1000 << " м\n";
        break;
    case 3:
        cout << value << " м = " << value / 1609.34 << " миль\n";
        break;
    case 4:
        cout << value << " миль = " << value * 1609.34 << " м\n";
        break;
    case 5:
        cout << value << " км = " << value / 1.60934 << " миль\n";
        break;
    case 6:
        cout << value << " миль = " << value * 1.60934 << " км\n";
        break;
    default:
        cout << "Некорректный выбор.\n";
    }
}

// Конвертация массы
void convertMass() 
{
    int choice;
    double value;
    cout << "Выберите направление конвертации:\n";
    cout << "1. Килограммы → Фунты\n";
    cout << "2. Фунты → Килограммы\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    cout << "Введите значение: ";
    cin >> value;

    if (choice == 1)
    {
        double result = value * 2.20462;
        cout << value << " кг = " << result << " фунтов\n";
    }
    else if (choice == 2) 
    {
        double result = value / 2.20462;
        cout << value << " фунтов = " << result << " кг\n";
    }
    else 
    {
        cout << "Некорректный выбор.\n";
    }
}

#ifdef UNIT_CONVERTER
int main() 
{
    setlocale(LC_ALL, "");
    int choice;
    do
    {
        cout << "\nМеню конвертера:\n";
        cout << "1. Температура (°C ↔ °F)\n";
        cout << "2. Длина (м ↔ км ↔ мили)\n";
        cout << "3. Масса (кг ↔ фунты)\n";
        cout << "4. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            convertTemperature();
            break;
        case 2:
            convertLength();
            break;
        case 3:
            convertMass();
            break;
        case 4:
            cout << "Выход...\n";
            break;
        default:
            cout << "Некорректный выбор.\n";
        }
    } while (choice != 4);

    return 0;
}
#endif //UNIT_CONVERTER