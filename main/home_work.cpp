#include <iostream>
using namespace std;

// Задание 1: Удаление символа с заданным номером
void removeCharAtPosition(char* str, int position) {
    if (position < 0) return;
    int i = 0;
    while (str[i] != '\0') {
        if (i == position) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            break;
        }
        i++;
    }
}

// Задание 2: Удаление всех вхождений заданного символа
void removeAllOccurrences(char* str, char ch) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ch) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
        }
        else {
            i++;
        }
    }
}

// Задание 3: Вставка символа в указанную позицию
void insertCharAtPosition(char* str, char ch, int position) {
    if (position < 0) return;
    int length = 0;
    while (str[length] != '\0') length++;

    if (position > length) position = length;

    for (int i = length; i >= position; i--) {
        str[i + 1] = str[i];
    }
    str[position] = ch;
}

// Задание 4: Замена всех точек на восклицательные знаки
void replaceDotsWithExclamations(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

// Задание 5: Подсчет количества вхождений символа в строку
int countCharOccurrences(const char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

// Задание 6: Подсчет букв, цифр и остальных символов
void countLettersDigitsOthers(const char* str, int& letters, int& digits, int& others) {
    letters = 0;
    digits = 0;
    others = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            letters++;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            digits++;
        }
        else {
            others++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    char str[1000]; // Буфер для строки

    // Задание 1
    cout << "Введите строку для задания 1: ";
    cin.getline(str, 1000);
    int position;
    cout << "Введите позицию для удаления: ";
    cin >> position;
    cin.ignore();
    removeCharAtPosition(str, position);
    cout << "Результат: " << str << endl;

    // Задание 2
    cout << "Введите строку для задания 2: ";
    cin.getline(str, 1000);
    char ch;
    cout << "Введите символ для удаления: ";
    cin >> ch;
    cin.ignore();
    removeAllOccurrences(str, ch);
    cout << "Результат: " << str << endl;

    // Задание 3
    cout << "Введите строку для задания 3: ";
    cin.getline(str, 1000);
    cout << "Введите символ для вставки: ";
    cin >> ch;
    cout << "Введите позицию для вставки: ";
    cin >> position;
    cin.ignore();
    insertCharAtPosition(str, ch, position);
    cout << "Результат: " << str << endl;

    // Задание 4
    cout << "Введите строку для задания 4: ";
    cin.getline(str, 1000);
    replaceDotsWithExclamations(str);
    cout << "Результат: " << str << endl;

    // Задание 5
    cout << "Введите строку для задания 5: ";
    cin.getline(str, 1000);
    cout << "Введите искомый символ: ";
    cin >> ch;
    cin.ignore();
    cout << "Количество вхождений: " << countCharOccurrences(str, ch) << endl;

    // Задание 6
    cout << "Введите строку для задания 6: ";
    cin.getline(str, 1000);
    int letters, digits, others;
    countLettersDigitsOthers(str, letters, digits, others);
    cout << "Букв: " << letters << ", цифр: " << digits << ", остальных символов: " << others << endl;

    return 0;
}
