/*
    파일명: task_20
    내용: 영어 단어에 대해 긑말을 이어가는 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>     // strlen, strcpy 함수 사용을 위한 헤더

void task20()
{
    char word[100];         // 현재 입력받는 단어를 저장할 배열
    char present_word[100];     // 이전에 입력한 단어를 저장할 배열
    int count = 0;          // 입력된 단어의 개수를 세는 변수 (첫 단어 구별용)

    while (1)
    {
        printf("단어를 입력하고 Enter (0입력 시 종료)>");
        scanf("%s", &word);

        if (word[0] == '0') // 1. 종료 조건 확인 
        {
            break;
        }

        if (count == 0)     // 2. 첫 번째 단어일 경우 무조건 저장
        {
            strcpy(present_word, word); // 현재 단어를 이전 단어 공간에 복사
            count++;
        }

        else                // 3. 두 번째 단어부터는 끝말잇기 규칙 검사
        {
            // 이전 단어의 길이 계산
            int len = strlen(present_word);

            // 이전 단어의 마지막 문자와 현재 단어의 첫 문자 비교
            // 배열 인덱스는 0부터 시작하므로 마지막 문자는 [길이 - 1]
            if (present_word[len - 1] == word[0])
            {
                strcpy(present_word, word);     // 맞으면 통과
                count++;
            }
            else    // 틀리면 다시 입력 요청
            {
                printf("다시 입력하세요\n");
            }
        }
    }
}

int main()
{
    task20();
    return 0;
}