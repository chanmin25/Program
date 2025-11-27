/*
    파일명: task_06
    내용: 다음 두 개의 3×3 행렬에 대해 행렬의 합, 차 그리고 곱을 구하는 프로그램을 각각 함수로 작성한다.
    작성자: 임승리
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_matrix(int m[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     
    {
        for (j = 0; j < 3; j++) 
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     
    {
        for (j = 0; j < 3; j++) 
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void mul_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j, k;
    int sum;

    for (i = 0; i < 3; i++)     
    {
        for (j = 0; j < 3; j++) 
        {
            sum = 0; 
            for (k = 0; k < 3; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum; 
        }
    }
}

void task06()
{
    int matrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[3][3] = {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };

    int result[3][3]; 

    printf("matrix A:\n");
    print_matrix(matrixA);

    printf("\nmatrix B:\n");
    print_matrix(matrixB);

    add_matrix(matrixA, matrixB, result);
    printf("\nmatrix A + matrix B:\n");
    print_matrix(result);

    sub_matrix(matrixA, matrixB, result);
    printf("\nmatrix A - matrix B:\n");
    print_matrix(result);

    mul_matrix(matrixA, matrixB, result);
    printf("\nmatrix A * matrix B:\n");
    print_matrix(result);
}

int main()
{
    task06();
    return 0;
}