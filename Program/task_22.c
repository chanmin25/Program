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
#include <stdlib.h> // malloc, free 사용을 위한 헤더

// 한글 문자열을 역순으로 변환하는 함수
char* reverse_kor(char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * (len + 1)); // 원본 길이 + 1(NULL 문자)만큼 동적 메모리 할당

    int i, j = 0;

    // 문자열의 끝에서부터 2바이트씩 앞으로 이동하며 복사
    for (i = len - 2; i >= 0; i -= 2)
    {
        // 한 글자(2바이트)를 통째로 복사
        result[j++] = str[i];     // '램'을 앞으로 보내서 복사
        result[j++] = str[i + 1]; // '램'의 뒷부분 복사, 다음 '그'의 뒷부분 복사 ... 이런식으로 진행
    }
    result[j] = '\0'; // 문자열 끝에 NULL 문자 추가

    return result;
}

// 문자열에서 공백을 제거하는 함수
char* remove_blank(char* str)
{
    int len = strlen(str);
    char* result = (char*)malloc(sizeof(char) * (len + 1)); // 최대 원본 길이만큼 메모리 할당

    int i, j = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] != ' ') // 공백이 아닌 경우에만 복사
        {
            result[j++] = str[i];
        }
        // 공백이면? 아무것도 안 하고 그냥 넘어감
    }
    result[j] = '\0'; // 문자열 끝에 NULL 문자 추가

    return result;
}

void task22()
{
    char* st1 = "프로그램";
    char* st2 = "파일 변환";

    // 결과 저장을 위한 포인터 변수
    char* rev_str;
    char* no_blank_str;

    printf("st1=%s  st2=%s\n", st1, st2);

    // 1. 역변환 수행
    rev_str = reverse_kor(st1);
    printf("역변환:%s\n", rev_str);
    printf("원본:%s\n", st1);

    // 2. 공백 제거 수행
    no_blank_str = remove_blank(st2);
    printf("공백제거:%s\n", no_blank_str);
    printf("원본:%s\n", st2);

    // 사용한 메모리 해제
    free(rev_str);
    free(no_blank_str);
}

int main()
{
    task22();
    return 0;
}