/*
    파일명: task_24
    내용: 입력된 정수형 숫자에 대해 0~9까지 각각의 숫자가 몇 개있는지를 카운트하는 프로그램을 작성한다.
    작성자: 임승리
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen 함수 사용

void task24()
{
    char input_num[100]; // 숫자를 문자열로 저장할 배열
    int counts[10] = { 0 }; // 0~9까지 각 숫자의 개수를 저장할 배열 (0으로 초기화 필수)
    int i, len;
    int digit;

    printf("정수숫자의 카운트\n\n");

    // 정수형 변수의 최댓값은 한계가 있으므로, 문자열로 안내
    // (문제의 예시는 unsigned int의 한계를 보여주지만, 문자열로 하면 훨씬 긴 숫자도 가능)
    printf("입력최대값은 무제한입니다.\n");
    printf("정수입력후 Enter하세요.\n");
    printf("입력>");
    scanf("%s", input_num);

    // 입력된 문자열의 길이 구하기
    len = strlen(input_num);

    // 문자열을 한 글자씩 확인하며 카운트
    for (i = 0; i < len; i++)
    {
        // 문자가 '0'~'9' 사이인 경우에만 처리 (안전장치)
        if (input_num[i] >= '0' && input_num[i] <= '9')
        {
            // [핵심 로직]
            // 문자 '0'의 아스키코드는 48.
            // 문자 '1'은 49...
            // 따라서 문자에서 '0'(48)을 빼면 실제 정수 값(0~9)이 나옴.
            digit = input_num[i] - '0';

            // 해당 숫자의 카운트 증가
            counts[digit]++;
        }
    }

    // 결과 출력
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