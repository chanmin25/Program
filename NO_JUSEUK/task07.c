

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


long long factorial(int n)  
{
    long long result = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}


long long combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void task07()
{
    int rows;
    int n, r;

    printf("파스칼의 삼각형 출력 프로그램\n\n");

    printf("출력할 행의 수 입력후 Enter\n");
    printf("행의수:");
    scanf("%d", &rows);
    printf("\n");


    for (n = 0; n < rows; n++)
    {

        for (r = 0; r < rows - n - 1; r++)
        {
            printf("  ");
        }


        for (r = 0; r <= n; r++)
        {

            printf("%4lld", combination(n, r));
        }

        printf("\n");
    }
}

int main()
{
    task07();
    return 0;
}