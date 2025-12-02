
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