/*
    파일명: task_04
    내용: 임의의 두 정수를 입력받아 유클리드 호제법을 이용하여, 최대공약수와 최소공배수를 출력하는 프로그램을 작성한다.
    작성자: 김정민
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task04()
{
    int x, y;       // 입력받을 두 정수
    int m, n;       // 유클리드 호제법 계산을 위한 변수
    int remainder;  // 나머지를 저장할 변수
    int gcd;        // 최대공약수 
    int lcm;        // 최소공배수 

    printf("최소공배수와 최대공약수\n\n");
    printf("두개의 숫자를 입력합니다.\n");

    // 입력
    printf("첫번째 숫자를 입력하고 Enter>");
    scanf("%d", &x);

    printf("두번째 숫자를 입력하고 Enter>");
    scanf("%d", &y);

    // 조건대로 x를 m에, y를 n에 저장 (유클리드 호제법)
    m = x;
    n = y;

    while (1)
    {
        remainder = m % n;  // 나머지 계산

        if (remainder == 0) // 나머지가 0이면 
        {
            gcd = n;        // n이 최대공약수
            break;          // 반복 종료
        }
        else
        {
            // 나머지가 0이 아니면 n을 m에, 나머지를 n에 대입하여 반복
            m = n;
            n = remainder;
        }
    }

    // 최소공배수 계산: (두 수의 곱) / 최대공약수
    lcm = (x * y) / gcd;

    // 출력
    printf("\n최대공약수 %d\n", gcd);
    printf("최소공배수 %d\n", lcm);
}

int main()
{
    task04();
    return 0;
}