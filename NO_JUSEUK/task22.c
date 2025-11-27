/*
    파일명: task_22
    내용: 입력된 한글 문자열에 대해 다음을 처리하는 함수와 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

char* reverse_kor(char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * (len + 1)); 

    int i, j = 0;

    for (i = len - 2; i >= 0; i -= 2)
    {
        result[j++] = str[i];     
        result[j++] = str[i + 1]; 
    }
    result[j] = '\0'; 

    return result;
}

char* remove_blank(char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * (len + 1)); 

    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ') 
        {
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; 

    return result;
}

void task22()
{
    char* st1 = "프로그램";
    char* st2 = "파일 변환";

    char* rev_str;
    char* no_blank_str;

    printf("st1=%s  st2=%s\n", st1, st2);

    rev_str = reverse_kor(st1);
    printf("역변환:%s\n", rev_str);
    printf("원본:%s\n", st1);

    no_blank_str = remove_blank(st2);
    printf("공백제거:%s\n", no_blank_str);
    printf("원본:%s\n", st2);

    free(rev_str);
    free(no_blank_str);
}

int main()
{
    task22();
    return 0;
}