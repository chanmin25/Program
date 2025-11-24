/*
    파일명: project_17
    내용: 0부터 9999 사이의 난수를 만들어 텍스트 방식의 파일 "rand.txt"에 한 줄에 5개씩 10줄로 50개를 출력하고 나서, 텍스트 파일 "rand.txt"를 읽어 들여 정렬하여 출력하는 프로그램이다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>   // time

#define SIZE 50     // 데이터 개수

void PJ17()
{
    FILE* fp;
    int data[SIZE];
    int i, j, temp;

    // 난수 생성기 초기화 (랜덤 기능을 위한)
    srand((unsigned int)time(NULL));

    fp = fopen("rand.txt", "w"); // 쓰기 모드로 열기
    if (fp == NULL)
    {
        printf("파일 생성 오류!\n");
        return 1;
    }

    printf("rand.txt 파일을 생성하고 난수를 저장합니다.\n");

    for (i = 0; i < SIZE; i++)
    {
        // 난수 생성
        int num = rand() % 10000;

        // 파일에 저장
        fprintf(fp, "%d ", num);

        // 5개마다 줄바꿈
        if ((i + 1) % 5 == 0)
        {
            fprintf(fp, "\n");
        }
    }
    fclose(fp); // 파일 닫기

    fp = fopen("rand.txt", "r"); // 읽기 모드로 열기
    if (fp == NULL)
    {
        printf("파일 열기 오류!\n");
        return 1;
    }

    // 파일에서 데이터 읽어오기
    for (i = 0; i < SIZE; i++)
    {
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);

    // 오름차순
    for (i = 0; i < SIZE - 1; i++)
    {
        for (j = 0; j < SIZE - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("\n[ 정렬된 결과 출력 ]\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%5d ", data[i]);    // 보기 좋게 간격 맞춤

        if ((i + 1) % 5 == 0)       // 5개 출력할 때마다 줄바꿈
        {
            printf("\n");
        }
    }
}

int main()
{
    PJ17();
    return 0;
}