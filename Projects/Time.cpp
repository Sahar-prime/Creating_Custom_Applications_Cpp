#include <iostream>
//#define TIME

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

//Вывод времени
void printTime(const Time& t)
{
    cout << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds << endl;
}

//Нормализация времени
Time normalizeTime(Time t) 
{
    // Нормализация секунд
    if (t.seconds < 0)
    {
        t.seconds += 60;
        t.minutes--;
    }
    t.minutes += t.seconds / 60;
    t.seconds %= 60;

    // Нормализация минут
    if (t.minutes < 0)
    {
        t.minutes += 60;
        t.hours--;
    }
    t.hours += t.minutes / 60;
    t.minutes %= 60;

    // Нормализация часов
    t.hours %= 24;
    if (t.hours < 0)
    {
        t.hours += 24;
    }

    return t;
}

//Добавление времени
Time addTime(const Time& t, int h, int m, int s)
{
    Time result = { t.hours + h, t.minutes + m, t.seconds + s };
    return normalizeTime(result);
}

//Вычитание времени
Time subtractTime(const Time& t, int h, int m, int s)
{
    return addTime(t, -h, -m, -s);
}

#ifdef TIME
int main()
{
    setlocale(LC_ALL, "");
    Time currentTime;
    cout << "Введите текущее время (часы минуты секунды): ";
    cin >> currentTime.hours >> currentTime.minutes >> currentTime.seconds;

    int choice;
    do 
    {
        cout << "\nТекущее время: ";
        printTime(currentTime);

        cout << "\nМеню:\n";
        cout << "1. Прибавить время\n";
        cout << "2. Вычесть время\n";
        cout << "3. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            int h, m, s;
            cout << "Введите часы, минуты, секунды: ";
            cin >> h >> m >> s;

            if (choice == 1) 
            {
                currentTime = addTime(currentTime, h, m, s);
            }
            else
            {
                currentTime = subtractTime(currentTime, h, m, s);
            }
        }
    } while (choice != 3);

    return 0;
}
#endif //TIME