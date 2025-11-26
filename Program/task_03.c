/*
    파일명: task_03
    내용: 계차수열은 인접하는 항의 차로 이루어진 수열을 말한다. 점화식을 이용하여 표현한 다음의 계차수열에 
         대해 n항까지 출력하는 함수와 프로그램을 작성한다.
    작성자: 임승리
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 선언
void print_sequence(int n);

void task03()
{
    int n;

    // 입력
    printf("출력할 항의 개수입력 후 Enter>");
    scanf("%d", &n);

    // 2. 함수 호출
    print_sequence(n);
}

void print_sequence(int n)
{
    int term = 1; // 첫째항은 1로 시작
    int i;

    printf("점화식\n");

    // n번 반복하며 수열 출력
    for (i = 0; i < n; i++)
    {
        printf("%d ", term);

        // 현재 값에 (i + 1)을 더함
        term = term + (i + 1);
    }
    printf("\n");
}

int main()
{
    task03();
    return 0;
}