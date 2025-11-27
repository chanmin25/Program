/*
    파일명: task_34
    내용: 1부터 100 사이의 번호 중에서 n개의 제비를 뽑아 오름차순으로 출력하는 프로그램을 작성한다.
    작성자: 이승훈
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

void generate_numbers(int* arr, int n);
void sort_numbers(int* arr, int n);

void task34()
{
    int n;
    int* lotto = NULL; 
    int i;

    srand((unsigned int)time(NULL));

    printf("1부터 100사이의 제비뽑기 번호출력\n");
    printf("뽑을 제비의 개수를 입력하고 Enter> ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("100개 이하로 입력해주세요.\n");
        return 0;
    }

    
    lotto = (int*)malloc(sizeof(int) * n);
    if (lotto == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    generate_numbers(lotto, n);

    for (i = 0; i < n; i++)
    {
        printf(" %d :  %d\n", i + 1, lotto[i]);
    }

    sort_numbers(lotto, n);

    printf("\n오름차순 정렬결과\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d :  %d\n", i + 1, lotto[i]);
    }

    free(lotto);
}

void generate_numbers(int* arr, int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n; i++)
    {
        temp = rand() % 100 + 1; 

        for (j = 0; j < i; j++)
        {
            if (arr[j] == temp)
            {
                i--;
                break;
            }
        }

        if (j == i)
        {
            arr[i] = temp;
        }
    }
}


void sort_numbers(int* arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    task34();
    return 0;
}