#include <iostream>

//#define MAIN_2

struct Task
{
    char title[50];
    char description[150];
    bool status;
};

void init(Task& t)
{
    std::cout << "����� ��������: ";
    std::cin.getline(t.title, 50);
    std::cout << "����� ��������: ";
    std::cin.getline(t.description, 150);
    std::cout << "����� ������ (1 - ���������, 0 - �� ���������): ";
    std::cin >> t.status;
}

void init(Task* t, int size)
{
    for (int i = 0; i < size; i++)
    {
        getchar();
        init(t[i]);
    }
}

void show(const Task& t)
{
    std::cout << "��������: " << t.title << std::endl;
    std::cout << "��������: " << t.description << std::endl;
    std::cout << "������: " << (t.status ? "���������" : "�� ���������") << std::endl;
}

void show(Task* t, int size)
{
    for (int i = 0; i < size; i++)
    {
        show(t[i]);
    }
}

void addTask(Task*& t, int& size, const Task& add)
{
    Task* newarr = new Task[size + 1];
    for (int i = 0; i < size; i++)
    {
        newarr[i] = t[i];
    }
    newarr[size] = add;
    delete[]t;
    t = newarr;
    newarr = nullptr;
    size++;
}

void delTask(Task*& t, int& size)
{
    Task* newarr = new Task[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        newarr[i] = t[i];
    }
    delete[]t;
    t = newarr;
    newarr = nullptr;
    size--;
}

void delTask(Task*& t, int& size, int index)
{
    Task* newarr = new Task[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        newarr[i] = t[i + (i >= index)];
    }
    delete[]t;
    t = newarr;
    newarr = nullptr;
    size--;
}

void removeCompletedTask(Task*& t, int& size)
{
    int i = 0;
    while (i < size)
    {
        if (t[i].status == true)
        {
            delTask(t, size, i);
            i--;
            std::cout << size << std::endl;
        }
        i++;
    }
}

void statusChange(Task*& t, int index)
{
    /*if (t[index].status == true)
    {
        t[index].status = false;
    }
    else
    {
        t[index].status = true;
    }*/
    t[index].status = t[index].status ? false : true;
}

#ifdef MAIN_2
int main()
{
    setlocale(0, "");
    int size;
    std::cout << "����� ������: ";
    std::cin >> size;
    Task* t = new Task[size];
    init(t, size);
    show(t, size);
    Task a = { "test", "hello world", true };
    addTask(t, size, a);
    /*show(t, size);
    int user;
    std::cout << "� ����� ������ ���������� ������: ";
    std::cin >> user;
    statusChange(t, user);
    show(t, size);
    delTask(t, size, 1);*/
    removeCompletedTask(t, size);
    show(t, size);
    delete[]t;
}
#endif //MAIN_2