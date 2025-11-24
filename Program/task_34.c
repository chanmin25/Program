/*
    파일명: task_34
    내용: 1부터 100 사이의 번호 중에서 n개의 제비를 뽑아 오름차순으로 출력하는 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free, rand, srand
#include <time.h>   // time

void generate_numbers(int* arr, int n);
void sort_numbers(int* arr, int n);

void task34()
{
    int n;
    int* lotto = NULL; // 동적 배열을 위한 포인터
    int i;

    // 1. 난수 생성기 초기화 (매번 다른 번호 생성을 위해 필수)
    srand((unsigned int)time(NULL));

    // 2. 제비 개수 입력
    printf("1부터 100사이의 제비뽑기 번호출력\n");
    printf("뽑을 제비의 개수를 입력하고 Enter> ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("100개 이하로 입력해주세요.\n");
        return 0;
    }

    // 3. 동적 메모리 할당 
    lotto = (int*)malloc(sizeof(int) * n);
    if (lotto == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 4. 난수 생성 함수 호출
    generate_numbers(lotto, n);

    // 5. 생성된 난수 출력
    for (i = 0; i < n; i++)
    {
        printf(" %d :  %d\n", i + 1, lotto[i]);
    }

    // 6. 정렬 함수 호출
    sort_numbers(lotto, n);

    // 7. 정렬된 결과 출력
    printf("\n오름차순 정렬결과\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d :  %d\n", i + 1, lotto[i]);
    }

    // 8. 메모리 해제
    free(lotto);
}

// 1~100 사이의 중복되지 않는 난수를 생성하여 배열에 저장
void generate_numbers(int* arr, int n)
{
    int i, j;
    int temp;

    for (i = 0; i < n; i++)
    {
        temp = rand() % 100 + 1; // 1 ~ 100 사이 난수 생성

        // 중복 검사: 이전에 생성된 번호들(0 ~ i-1)과 비교
        for (j = 0; j < i; j++)
        {
            if (arr[j] == temp)
            {
                // 중복 발생 시, i를 하나 줄여서 다시 뽑게 함
                i--;
                break;
            }
        }

        // 중복이 아니라면 배열에 저장 (중복이면 i-- 되었으므로 덮어씀)
        if (j == i)
        {
            arr[i] = temp;
        }
    }
}


// 배열을 오름차순으로 정렬 (버블 정렬 사용)
void sort_numbers(int* arr, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            // 앞의 수가 뒤의 수보다 크면 자리 바꿈
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