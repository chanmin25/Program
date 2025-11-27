/*
    파일명: task_20
    내용: 영어 단어에 대해 끝말을 이어가는 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>     

void task20()
{
    char word[100];         
    char present_word[100]; 
    int count = 0;          

    while (1)
    {
        printf("단어를 입력하고 Enter (0입력 시 종료)>");
        scanf("%s", &word);

        if (word[0] == '0') 
        {
            break;
        }

        if (count == 0)             
        {
            strcpy(present_word, word); 
            count++;
        }

        else               
        {
            int len = strlen(present_word);

            if (present_word[len - 1] == word[0])
            {
                strcpy(present_word, word);     
                count++;
            }
            else    
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