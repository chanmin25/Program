

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

void task25()
{
    char input_num[100];
    char integer_part[50] = { 0 }; 
    char decimal_part[50] = { 0 }; 
    int counts[10] = { 0 };    
    int i, len;
    char* dot_ptr; 

    printf("실수숫자의 카운트\n\n");
    printf("실수입력후 Enter하세요.\n");
    printf("정수,실수부분은 9자리를 초과할 수 없음\n");
    printf("입력>");
    scanf("%s", input_num);

    dot_ptr = strchr(input_num, '.');

    if (dot_ptr != NULL)
    {

        strncpy(integer_part, input_num, dot_ptr - input_num);


        strcpy(decimal_part, dot_ptr + 1);
    }
    else
    {
        strcpy(integer_part, input_num);
    }

    printf("입력된 실수 : %s\n", input_num);
    printf("정수 부분   : %s\n", integer_part);
    printf("소수이하부분: %s\n\n", decimal_part);

    len = strlen(input_num);
    for (i = 0; i < len; i++)
    {
        if (input_num[i] >= '0' && input_num[i] <= '9')
        {
            int digit = input_num[i] - '0';     
            counts[digit]++;
        }
    }

    printf("num     cnt\n");
    for (i = 0; i <= 9; i++)
    {
        printf("%d       %d\n", i, counts[i]);
    }
}

int main()
{
    task25();
    return 0;
}