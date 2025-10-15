#include <iostream>

//#define H_W_3

// Структура для представления товара
struct Product 
{
    char productName[100];
    int quantity;
    double pricePerUnit;
};

// Функция для вывода информации о товарах на складе
void displayInventory(const Product* inventory, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        std::cout << "Название: " << inventory[i].productName << std::endl;
        std::cout << "Количество: " << inventory[i].quantity << std::endl;
        std::cout << "Цена за единицу: " << inventory[i].pricePerUnit << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }
}

// Функция для добавления нового товара в массив
Product* addProductToInventory(Product* inventory, int& size, const Product& newProduct) 
{
    Product* newInventory = new Product[size + 1];

    for (int i = 0; i < size; ++i) 
    {
        newInventory[i] = inventory[i];
    }

    newInventory[size] = newProduct;
    size++;

    delete[] inventory;

    return newInventory;
}

// Функция для расчета общей стоимости товаров на складе
double calculateInventoryValue(const Product* inventory, int size) 
{
    double totalValue = 0.0;
    for (int i = 0; i < size; ++i)
    {
        totalValue += inventory[i].quantity * inventory[i].pricePerUnit;
    }
    return totalValue;
}

#ifdef H_W_3
int main() 
{
    setlocale(LC_ALL, "");
    int inventorySize = 0;
    Product* inventory = nullptr;

    // Добавление товаров
    Product product1 = { "Яблоки", 50, 1.5 };
    inventory = addProductToInventory(inventory, inventorySize, product1);

    Product product2 = { "Бананы", 30, 2.0 };
    inventory = addProductToInventory(inventory, inventorySize, product2);

    // Вывод информации о товарах
    displayInventory(inventory, inventorySize);

    // Расчет общей стоимости
    double totalValue = calculateInventoryValue(inventory, inventorySize);
    std::cout << "Общая стоимость товаров на складе: " << totalValue << std::endl;

    // Освобождение памяти
    delete[] inventory;
}
#endif //H_W_3