

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_sequence(int n);

void task03()
{
    int n;

    
    printf("출력할 항의 개수입력 후 Enter>");
    scanf("%d", &n);

    
    print_sequence(n);
}

void print_sequence(int n)
{
    int term = 1; 
    int i;

    printf("점화식\n");

    
    for (i = 0; i < n; i++)
    {
        printf("%d ", term);

        
        term = term + (i + 1);
    }
    printf("\n");
}

int main()
{
    task03();
    return 0;
}