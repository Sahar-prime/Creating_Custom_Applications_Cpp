#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//#define MAIN_3

struct Date
{
    int day;
    int month;
    int year;
};

struct FinancialTransaction
{
    double amount;            
    bool transactionType; 
    char description[100];   
    Date transactionDate;    
};

void init(FinancialTransaction& transaction)
{
    std::cout << "Введите сумму транзакции: ";
    std::cin >> transaction.amount;

    std::cout << "Введите тип транзакции (расход-1/доход-0): ";
    std::cin >> transaction.transactionType;

    std::cout << "Введите описание транзакции: ";
    std::cin.ignore();
    std::cin.getline(transaction.description, 100);

    std::cout << "Введите дату транзакции (день месяц год): ";
    std::cin >> transaction.transactionDate.day >> transaction.transactionDate.month >> transaction.transactionDate.year;
}

void printTransaction(const FinancialTransaction& transaction) 
{
    std::cout << "Сумма: " << transaction.amount << "\n";
    std::cout << "Тип: " << (transaction.transactionType? "расход":"доход") << "\n";
    std::cout << "Описание: " << transaction.description << "\n";
    std::cout << "Дата: " << transaction.transactionDate.day << "." << transaction.transactionDate.month << "." << transaction.transactionDate.year << "\n\n";
}

#ifdef MAIN_3
int main() 
{
    setlocale(LC_ALL, "");
    const int MAX_TRANSACTIONS = 100;
    FinancialTransaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;

    std::cout << "Добавление новой транзакции:\n";
    init(transactions[transactionCount]);
    transactionCount++;

    for (int i = 0; i < transactionCount; ++i) 
    {
        printTransaction(transactions[i]);
    }

}
#endif //MAIN_3