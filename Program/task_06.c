/*
    파일명: task_06
    내용: 다음 두 개의 3×3 행렬에 대해 행렬의 합, 차 그리고 곱을 구하는 프로그램을 각각 함수로 작성한다.
    작성자: 임승리
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 3x3 행렬 출력을 위한 함수
void print_matrix(int m[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     // 행
    {
        for (j = 0; j < 3; j++) // 열
        {
            // 보기 좋게 5칸 간격으로 출력
            printf("%5d", m[i][j]);
        }
        printf("\n");
    }
}

// 행렬의 합 (A + B)
void add_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     // 행 (row) 반복
    {
        for (j = 0; j < 3; j++) // 열 (col) 반복
        {
            // 같은 위치의 원소끼리 더함
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// 행렬의 차 (A - B)
void sub_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)     // 행 (row) 반복
    {
        for (j = 0; j < 3; j++) // 열 (col) 반복
        {
            // 같은 위치의 원소끼리 뺌
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

// 행렬의 곱 (A * B)
void mul_matrix(int a[3][3], int b[3][3], int result[3][3])
{
    int i, j, k;
    int sum;

    // 행렬 곱셈 공식: C(i,j) = Sum(A(i,k) * B(k,j))
    for (i = 0; i < 3; i++)     // 행 (row)
    {
        for (j = 0; j < 3; j++) // 열 (col)
        {
            sum = 0; // 누적할 변수 초기화
            for (k = 0; k < 3; k++)
            {
                // A는 옆으로(k가 열), B는 밑으로(k가 행) 이동하며 곱함
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum; // 계산된 합계를 결과 칸에 저장
        }
    }
}

void task06()
{
    // 문제에 제시된 값으로 행렬 초기화
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

    int result[3][3]; // 계산 결과를 저장할 배열

    // 1. Matrix A 출력
    printf("matrix A:\n");
    print_matrix(matrixA);

    // 2. Matrix B 출력
    printf("\nmatrix B:\n");
    print_matrix(matrixB);

    // 3. 합 계산 및 출력
    add_matrix(matrixA, matrixB, result);
    printf("\nmatrix A + matrix B:\n");
    print_matrix(result);

    // 4. 차 계산 및 출력
    sub_matrix(matrixA, matrixB, result);
    printf("\nmatrix A - matrix B:\n");
    print_matrix(result);

    // 5. 곱 계산 및 출력
    mul_matrix(matrixA, matrixB, result);
    printf("\nmatrix A * matrix B:\n");
    print_matrix(result);
}

int main()
{
    task06();
    return 0;
}