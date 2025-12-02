

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