#include <iostream>

void matrix_multiply(int** A, int** B, int** C, int M, int N, int K) 
{
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < K; ++j) 
        {
            C[i][j] = 0; // Обнуляем элемент перед суммированием
            for (int k = 0; k < N; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() 
{
    // Размеры матриц
    const int M = 2; // строки матрицы A
    const int N = 3; // столбцы матрицы A / строки матрицы B
    const int K = 2; // столбцы матрицы B

    // Выделение памяти для матриц
    int** A = new int* [M];
    for (int i = 0; i < M; ++i) 
    {
        A[i] = new int[N];
    }

    int** B = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        B[i] = new int[K];
    }

    int** C = new int* [M];
    for (int i = 0; i < M; ++i)
    {
        C[i] = new int[K];
    }

    // Заполнение матрицы A
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    // Заполнение матрицы B
    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    // Умножение матриц
    matrix_multiply(A, B, C, M, N, K);

    // Вывод результата
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < K; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < M; ++i) 
    {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < N; ++i) 
    {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < M; ++i) 
    {
        delete[] C[i];
    }
    delete[] C;
}