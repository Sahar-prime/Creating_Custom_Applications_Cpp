#include <iostream>

void matrix_multiply(int** A, int** B, int** C, int M, int N, int K) 
{
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < K; ++j) 
        {
            C[i][j] = 0; // �������� ������� ����� �������������
            for (int k = 0; k < N; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() 
{
    // ������� ������
    const int M = 2; // ������ ������� A
    const int N = 3; // ������� ������� A / ������ ������� B
    const int K = 2; // ������� ������� B

    // ��������� ������ ��� ������
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

    // ���������� ������� A
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    // ���������� ������� B
    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    // ��������� ������
    matrix_multiply(A, B, C, M, N, K);

    // ����� ����������
    for (int i = 0; i < M; ++i) 
    {
        for (int j = 0; j < K; ++j)
        {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // ������������ ������
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