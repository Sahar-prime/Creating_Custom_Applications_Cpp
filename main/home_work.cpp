#include <iostream>
using namespace std;

// ������� 1: �������� ������� � �������� �������
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

// ������� 2: �������� ���� ��������� ��������� �������
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

// ������� 3: ������� ������� � ��������� �������
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

// ������� 4: ������ ���� ����� �� ��������������� �����
void replaceDotsWithExclamations(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
}

// ������� 5: ������� ���������� ��������� ������� � ������
int countCharOccurrences(const char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

// ������� 6: ������� ����, ���� � ��������� ��������
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
    char str[1000]; // ����� ��� ������

    // ������� 1
    cout << "������� ������ ��� ������� 1: ";
    cin.getline(str, 1000);
    int position;
    cout << "������� ������� ��� ��������: ";
    cin >> position;
    cin.ignore();
    removeCharAtPosition(str, position);
    cout << "���������: " << str << endl;

    // ������� 2
    cout << "������� ������ ��� ������� 2: ";
    cin.getline(str, 1000);
    char ch;
    cout << "������� ������ ��� ��������: ";
    cin >> ch;
    cin.ignore();
    removeAllOccurrences(str, ch);
    cout << "���������: " << str << endl;

    // ������� 3
    cout << "������� ������ ��� ������� 3: ";
    cin.getline(str, 1000);
    cout << "������� ������ ��� �������: ";
    cin >> ch;
    cout << "������� ������� ��� �������: ";
    cin >> position;
    cin.ignore();
    insertCharAtPosition(str, ch, position);
    cout << "���������: " << str << endl;

    // ������� 4
    cout << "������� ������ ��� ������� 4: ";
    cin.getline(str, 1000);
    replaceDotsWithExclamations(str);
    cout << "���������: " << str << endl;

    // ������� 5
    cout << "������� ������ ��� ������� 5: ";
    cin.getline(str, 1000);
    cout << "������� ������� ������: ";
    cin >> ch;
    cin.ignore();
    cout << "���������� ���������: " << countCharOccurrences(str, ch) << endl;

    // ������� 6
    cout << "������� ������ ��� ������� 6: ";
    cin.getline(str, 1000);
    int letters, digits, others;
    countLettersDigitsOthers(str, letters, digits, others);
    cout << "����: " << letters << ", ����: " << digits << ", ��������� ��������: " << others << endl;

    return 0;
}
