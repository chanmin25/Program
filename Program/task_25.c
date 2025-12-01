/*
    파일명: task_25
    내용: 입력된 실수형 숫자에 대해 0~9까지 각각의 숫자가 몇 개있는지를 카운트하는 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

void task25()
{
    char input_num[100]; 
    char integer_part[50] = { 0 }; // 정수 부분 저장
    char decimal_part[50] = { 0 }; // 소수 부분 저장
    int counts[10] = { 0 };    // 0~9 숫자 카운트 배열
    int i, len;
    char* dot_ptr; // 소수점 위치를 찾기 위한 포인터

    printf("실수숫자의 카운트\n\n");
    printf("실수입력후 Enter하세요.\n");
    printf("정수,실수부분은 9자리를 초과할 수 없음\n");
    printf("입력>");
    scanf("%s", input_num);

    // 1. 소수점('.') 위치 찾기
    dot_ptr = strchr(input_num, '.');

    if (dot_ptr != NULL)
    {
        // 소수점이 있는 경우
        // 정수 부분 복사: 처음부터 소수점 직전까지
        // (dot_ptr - input_num)은 소수점의 인덱스이자 정수부의 길이
        // 예시(1234.567) :

            //input_num(시작점 '1') : 주소가 1000번지라고 가정.

            //dot_ptr(점 '.') : 주소가 1004번지가 됨.

            //계산 : 1004 - 1000 = 4

            //결과 : "아, 점 앞에 숫자가 4개 있구나!"라고 알게 됨.
        strncpy(integer_part, input_num, dot_ptr - input_num);

        // 소수 부분 복사: 소수점 다음 칸(dot_ptr + 1)부터 끝까지
        // . + 1 이므로 .567을 읽는 것
        strcpy(decimal_part, dot_ptr + 1);
    }
    else
    {
        // 소수점이 없는 경우 (정수만 입력됨)
        strcpy(integer_part, input_num);
        // 소수 부분은 없음 (이미 0으로 초기화됨)
    }

    // 2. 출력
    printf("입력된 실수 : %s\n", input_num);
    printf("정수 부분   : %s\n", integer_part);
    // 소수 부분이 비어있지 않을 때만 출력
    printf("소수이하부분: %s\n\n", decimal_part);

    // 3. 숫자 카운트 (문자열 전체를 돌면서)
    len = strlen(input_num);
    for (i = 0; i < len; i++)
    {
        // 문자가 '0'~'9' 사이인 경우에만 카운트 (소수점 '.'은 제외됨)
        if (input_num[i] >= '0' && input_num[i] <= '9')
        {
            int digit = input_num[i] - '0';     // '1' - '0' => 아스키코드  49 - 48 = 1(정수)
            counts[digit]++;
        }
    }

    // 4. 결과 출력
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