#include <iostream>
//#define DATE

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

// Простой генератор случайных чисел (линейный конгруэнтный метод)
unsigned int simpleRand() 
{
    static unsigned int seed = 1;
    seed = (1103515245 * seed + 12345) & 0x7FFFFFFF;
    return seed;
}

bool isLeapYear(int year) 
{
    if (year % 4 != 0) return false;
    if (year % 100 != 0) return true;
    return (year % 400 == 0);
}

int daysInMonth(int month, int year) 
{
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

bool isValidDate(const Date& date) 
{
    if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1)
        return false;
    return date.day <= daysInMonth(date.month, date.year);
}

Date generateRandomDate(int minYear, int maxYear)
{
    Date date;
    date.year = minYear + simpleRand() % (maxYear - minYear + 1);
    date.month = 1 + simpleRand() % 12;
    date.day = 1 + simpleRand() % daysInMonth(date.month, date.year);
    return date;
}

void printDate(const Date& date) 
{
    cout << (date.day < 10 ? "0" : "") << date.day << "."
        << (date.month < 10 ? "0" : "") << date.month << "."
        << date.year << endl;
}

// Пузырьковая сортировка
void bubbleSort(Date dates[], int n) 
{
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (dates[j].year > dates[j + 1].year ||
                (dates[j].year == dates[j + 1].year && dates[j].month > dates[j + 1].month) ||
                (dates[j].year == dates[j + 1].year && dates[j].month == dates[j + 1].month && dates[j].day > dates[j + 1].day)) {
                swap(dates[j], dates[j + 1]);
            }
        }
    }
}

#ifdef DATE
int main() {
    setlocale(LC_ALL, "");
    int N, minYear, maxYear;
    cout << "Введите количество случайных дат (N): ";
    cin >> N;
    cout << "Введите минимальный год: ";
    cin >> minYear;
    cout << "Введите максимальный год: ";
    cin >> maxYear;

    Date dates[1000]; // Предполагаем, что N <= 1000
    int count = 0;

    while (count < N) {
        Date date = generateRandomDate(minYear, maxYear);
        if (isValidDate(date)) {
            dates[count++] = date;
        }
    }

    cout << "\nСгенерированные даты:\n";
    for (int i = 0; i < N; ++i) {
        printDate(dates[i]);
    }

    bubbleSort(dates, N);

    cout << "\nОтсортированные даты:\n";
    for (int i = 0; i < N; ++i) {
        printDate(dates[i]);
    }

    return 0;
}
#endif //DATE
