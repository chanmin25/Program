/*
    파일명: task_02
    내용 : 각 항에 대한 일정한 비율을 곱하여 얻어지는 수열을 등비수열 또는 기하수열이라 하고 항
    에 곱해지는 일정한 비율을 공비라 한다. 공비가 2인 다음의 등비수열의 대해 점화식과 일
    반항을 이용하여 n항까지 출력하는 함수와 프로그램을 작성한다.
    작성자: 임승리
    날짜: 2025.11.22
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

void print_by_recurrence(int n);
void print_by_general(int n);

void task02()
{
    int n;
    printf("출력할 항의 개수 입력 후 Enter>>");
    scanf("%d", &n);

    printf("점화식\n");
    print_by_recurrence(n);

    printf("일반항\n");
    print_by_general(n);
}


void print_by_recurrence(int n)
{
    int a = 1;          
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a);
        a *= 2;         
    }
    printf("\n");
}

void print_by_general(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int a = (int)pow(2, i - 1);  
        printf("%d ", a);
    }
    printf("\n");
}

int main()
{
    task02();
    return 0;
}