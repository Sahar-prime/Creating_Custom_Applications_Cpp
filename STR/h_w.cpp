#include <iostream>

//#define H_W

// ������� ��������� �����
int mystrcmp(const char* str1, const char* str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    if (*str1 == *str2) 
    {
        return 0; // ������ �����
    }
    else if (*str1 > *str2)
    {
        return 1; // ������ ������ ������
    }
    else 
    {
        return -1; // ������ ������ ������
    }
}

// ������� �������������� ������
char* mystrrev(char* str)
{
    if (!str) return nullptr;

    char* start = str;
    char* end = str;

    // ������� ����� ������
    while (*end) 
    {
        end++;
    }
    end--; // ��������� �� ��������� ������ ����� '\0'

    // ������ ������� �������
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

// ������� �������������� ������ � ������� �������
char* Uppercase(char* str) 
{
    if (!str) return nullptr;

    char* ptr = str;
    while (*ptr) 
    {
        if (*ptr >= 'a' && *ptr <= 'z')
        {
            *ptr -= 32; // ����������� � ������� �������
        }
        ptr++;
    }
    return str;
}

// ������� �������������� ������ � ������ �������
char* Lowercase(char* str) 
{
    if (!str) return nullptr;

    char* ptr = str;
    while (*ptr) 
    {

        if (*ptr >= 'A' && *ptr <= 'Z')
        {
            *ptr += 32; // ����������� � ������ �������
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
    int cmp = mystrcmp(s1, s2); // ����� ������������� �����
    mystrrev(s3); // ������ s3 �������� "olleh"
    Uppercase(str1); // ������ str1 �������� "HELLO, WORLD!"
    Lowercase(str2); // ������ str2 �������� "hello, world!"
    std::cout << cmp << std::endl;
    std::cout << s3 << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}
#endif //H_W
