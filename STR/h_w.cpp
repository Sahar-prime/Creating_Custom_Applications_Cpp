#include <iostream>

//#define H_W

// Функция сравнения строк
int mystrcmp(const char* str1, const char* str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    if (*str1 == *str2) 
    {
        return 0; // Строки равны
    }
    else if (*str1 > *str2)
    {
        return 1; // Первая строка больше
    }
    else 
    {
        return -1; // Первая строка меньше
    }
}

// Функция реверсирования строки
char* mystrrev(char* str)
{
    if (!str) return nullptr;

    char* start = str;
    char* end = str;

    // Находим конец строки
    while (*end) 
    {
        end++;
    }
    end--; // Указываем на последний символ перед '\0'

    // Меняем местами символы
    while (start < end) 
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

// Функция преобразования строки в верхний регистр
char* Uppercase(char* str) 
{
    if (!str) return nullptr;

    char* ptr = str;
    while (*ptr) 
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr -= 32; // Преобразуем в верхний регистр
        }
        ptr++;
    }
    return str;
}

// Функция преобразования строки в нижний регистр
char* Lowercase(char* str) 
{
    if (!str) return nullptr;

    char* ptr = str;
    while (*ptr) 
    {

        if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr += 32; // Преобразуем в нижний регистр
        }
        ptr++;
    }
    return str;
}

#ifdef H_W
int main()
{
    const char* s1 = "hello";
    const char* s2 = "world";
    char s3[] = "hello";
    char str1[] = "Hello, World!";
    char str2[] = "HELLO, WORLD!";
    int cmp = mystrcmp(s1, s2); // Вернёт отрицательное число
    mystrrev(s3); // Теперь s3 содержит "olleh"
    Uppercase(str1); // Теперь str1 содержит "HELLO, WORLD!"
    Lowercase(str2); // Теперь str2 содержит "hello, world!"
    std::cout << cmp << std::endl;
    std::cout << s3 << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}
#endif //H_W
