#include <iostream>
//#define TIME

using namespace std;

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

//����� �������
void printTime(const Time& t)
{
    cout << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds << endl;
}

//������������ �������
Time normalizeTime(Time t) 
{
    // ������������ ������
    if (t.seconds < 0)
    {
        t.seconds += 60;
        t.minutes--;
    }
    t.minutes += t.seconds / 60;
    t.seconds %= 60;

    // ������������ �����
    if (t.minutes < 0)
    {
        t.minutes += 60;
        t.hours--;
    }
    t.hours += t.minutes / 60;
    t.minutes %= 60;

    // ������������ �����
    t.hours %= 24;
    if (t.hours < 0)
    {
        t.hours += 24;
    }

    return t;
}

//���������� �������
Time addTime(const Time& t, int h, int m, int s)
{
    Time result = { t.hours + h, t.minutes + m, t.seconds + s };
    return normalizeTime(result);
}

//��������� �������
Time subtractTime(const Time& t, int h, int m, int s)
{
    return addTime(t, -h, -m, -s);
}

#ifdef TIME
int main()
{
    setlocale(LC_ALL, "");
    Time currentTime;
    cout << "������� ������� ����� (���� ������ �������): ";
    cin >> currentTime.hours >> currentTime.minutes >> currentTime.seconds;

    int choice;
    do 
    {
        cout << "\n������� �����: ";
        printTime(currentTime);

        cout << "\n����:\n";
        cout << "1. ��������� �����\n";
        cout << "2. ������� �����\n";
        cout << "3. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            int h, m, s;
            cout << "������� ����, ������, �������: ";
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