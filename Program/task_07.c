/*
    파일명: task_07
    내용: 파스칼의 삼각형을 다음 [그림 1]과 같이 출력하는 프로그램을 함수로 작성한다. 출력할 행의 수는 입력을 받아 처리한다. 
    작성자: 김정민
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 팩토리얼(!)을 계산하는 함수
// n! = n * (n-1) * ... * 1
long long factorial(int n)  // long long을 쓰는 이유는 오버플로우를 방지하기 위함.
{
    long long result = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// 이항계수 nCr을 계산하는 함수
// nCr = n! / (r! * (n-r)!)
long long combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void task07()
{
    int rows;
    int n, r;

    printf("파스칼의 삼각형 출력 프로그램\n\n");

    // 1. 입력
    printf("출력할 행의 수 입력후 Enter\n");
    printf("행의수:");
    scanf("%d", &rows);
    printf("\n");

    // 2. 처리 및 출력
    // n: 행 번호 (0부터 rows-1까지)
    for (n = 0; n < rows; n++)
    {
        // [공백 출력] 삼각형 모양을 만들기 위해 앞쪽에 공백을 넣음
        // 아래로 갈수록 공백이 줄어들어야 함 (rows - n - 1 만큼)
        // 숫자가 2~3자리일 수 있으므로 공백을 넉넉히(2칸씩) 줌
        for (r = 0; r < rows - n - 1; r++)
        {
            printf("  ");
        }

        // [숫자 출력] 해당 행(n)의 0번째부터 n번째 항까지 출력
        // r: 열 번호 (0부터 n까지)
        for (r = 0; r <= n; r++)
        {
            // 이항계수 공식으로 값 계산 후 출력
            // %4lld: 숫자를 4칸 폭으로 출력하여 간격을 맞춤, long long 이기에 ll이라고 씀
            printf("%4lld", combination(n, r));
        }

        // 한 행 출력이 끝나면 줄바꿈
        printf("\n");
    }
}

int main()
{
    task07();
    return 0;
}