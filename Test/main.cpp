#include <iostream>

//#define MAIN

using namespace std;

//��������� ��� ������ (2 ��������������)
struct Britva
{
    char proizvoditel[50];
    char model[50];
};

//��������� ��� ���� ��� ������ (2 ��������������)
struct GelDlyaBritya
{
    char marka[50];
    char tip[50];
};

//��������� ��� ����������� ������
struct PodarochnyiNabor
{
    char nazvanie[100];
    Britva britva;
    GelDlyaBritya gel;
};

void init(PodarochnyiNabor& nabor)
{
    //���� ������ ��� ������
    cout << "������� �������� ����������� ������: ";
    cin.getline(nabor.nazvanie, 100);
    cout << "--- ������ ��� ������ ---" << endl;
    cout << "�������������: ";
    cin.getline(nabor.britva.proizvoditel, 50);
    cout << "������: ";
    cin.getline(nabor.britva.model, 50);

    //���� ������ ��� ����
    cout << "--- ������ ��� ���� ��� ������ ---" << endl;
    cout << "�����: ";
    cin.getline(nabor.gel.marka, 50);
    cout << "��� (��������, ��� �������������� ����): ";
    cin.getline(nabor.gel.tip, 50);
}

void printed_information(const PodarochnyiNabor& nabor)
{
    cout << endl << "--- ���������� ����������� ������ ---" << endl;
    cout << "�������� ������: " << nabor.nazvanie << endl;
    cout << "������:" << endl;
    cout << "  �������������: " << nabor.britva.proizvoditel << endl;
    cout << "  ������: " << nabor.britva.model << endl;
    cout << "���� ��� ������:" << endl;
    cout << "  �����: " << nabor.gel.marka << endl;
    cout << "  ���: " << nabor.gel.tip << endl;
}

#ifdef MAIN
int main()
{
    setlocale(LC_ALL, "");

    PodarochnyiNabor product;
    init(product);
    printed_information(product);
}
#endif //MAIN

/*
������� ��������� ������ (2 �������������� �� �����)
� ���� ��� ������ (2 �������������� �� �����).
������� ���������� ����� � ���. ����� ��������.
*/