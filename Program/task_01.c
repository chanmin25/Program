/*
    파일명: task_01
    내용: 등차수열은 첫째항부터 차례로 일정한 수를 더하여 얻어지는 수열을 말한다. 공차가 2인 다음의 등차수열에 대해 점화식과 일반항을 이용하여
         n항까지 출력하는 함수와 프로그램을 작성한다.
    작성자: 김정민
    날짜: 2025.11.24
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ignition(int n);    // 전반선언
void general(int n);

void task01()
{
    int n;

    printf("출력할 항의 개수입력 후 Enter> ");
    scanf("%d", &n);

    ignition(n);    // 점화식 함수 실행
    general(n);     // 일반항 함수 실행
}

// 점화식
void ignition(int n)
{
    int current_value = 1;  // 첫째항(a1) = 1로 저장
    int i;

    printf("점화식\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", current_value);
        current_value = current_value + 2;  // 현재 값에 공차 2를 더함
    }
    printf("\n");
}

// 일반식
void general(int n)
{
    int i;
    int value;

    printf("일반항\n");
    for (i = 1; i <= n; i++)
    { // 1항부터 n항까지 반복
        value = 2 * i - 1;     // 공식 대입: (an = 2n -1)에 i를 대입하여 계산
        printf("%d ", value);
    }
    printf("\n");
}

int main()
{
    task01();
    return 0;
}