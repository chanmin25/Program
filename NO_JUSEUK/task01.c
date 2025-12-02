
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ignition(int n);    
void general(int n);

void task01()
{
    int n;

    printf("출력할 항의 개수입력 후 Enter> ");
    scanf("%d", &n);

    ignition(n);    
    general(n);     
}


void ignition(int n)
{
    int current_value = 1;  
    int i;

    printf("점화식\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", current_value);
        current_value = current_value + 2;  
    }
    printf("\n");
}


void general(int n)
{
    int i;
    int value;

    printf("일반항\n");
    for (i = 1; i <= n; i++)
    { 
        value = 2 * i - 1;     
        printf("%d ", value);
    }
    printf("\n");
}

int main()
{
    task01();
    return 0;
}