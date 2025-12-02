

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task04()
{
    int x, y;       
    int m, n;       
    int remainder;  
    int gcd;        
    int lcm;        

    printf("최소공배수와 최대공약수\n\n");
    printf("두개의 숫자를 입력합니다.\n");

    printf("첫번째 숫자를 입력하고 Enter>");
    scanf("%d", &x);

    printf("두번째 숫자를 입력하고 Enter>");
    scanf("%d", &y);

    m = x;
    n = y;

    while (1)
    {
        remainder = m % n;  

        if (remainder == 0) 
        {
            gcd = n;        
            break;          
        }
        else
        {
            m = n;
            n = remainder;
        }
    }

    lcm = (x * y) / gcd;

    printf("\n최대공약수 %d\n", gcd);
    printf("최소공배수 %d\n", lcm);
}

int main()
{
    task04();
    return 0;
}