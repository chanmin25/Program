

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

void task24()
{
    char input_num[100]; 
    int counts[10] = { 0 }; 
    int i, len;
    int digit;

    printf("정수숫자의 카운트\n\n");

    printf("입력최대값은 무제한입니다.\n");
    printf("정수입력후 Enter하세요.\n");
    printf("입력>");
    scanf("%s", input_num);

    len = strlen(input_num);

    for (i = 0; i < len; i++)
    {
        if (input_num[i] >= '0' && input_num[i] <= '9')
        {

            digit = input_num[i] - '0';

            counts[digit]++;
        }
    }

    printf("\n숫자 count\n");
    for (i = 0; i <= 9; i++)
    {
        printf(" %d     %d\n", i, counts[i]);
    }
}

int main()
{
    task24();
    return 0;
}