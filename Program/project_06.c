/*
    파일명: project_06
    내용: 로또의 추첨 방법은 1에서부터 45까지 숫자가 표시된 45개의 공을 통에 넣고 돌리면서 6개의 공을 순차적으로 선택하여 공에 표시된 숫자로 당첨번호를 결정한다. 프로그램에 의해
          1부터 45번의 숫자 중에서 중복되지 않는 6개의 숫자를 순차적으로 추출해 내도록 작성한다.
    작성자: 정찬민
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>   // time

void PJ06()
{
    int num[45];        // 1~45 숫자가 들어갈 원본 배열
    int lotto[6];       // 당첨된 번호를 저장할 배열
    int count = 45;     // 현재 남은 공의 개수
    int i, j, index, temp;

    // 1. 난수 생성기 초기화
    srand((unsigned int)time(NULL));

    // 2. 원본 배열 초기화 (1부터 45까지 저장)
    for (i = 0; i < 45; i++)
    {
        num[i] = i + 1;
    }

    // 3. 시작 대기 화면
    printf("[로또 당첨 번호]\n");
    printf("\n");

    // 4. 로또 번호 추첨 (6번 반복)
    for (i = 0; i < 6; i++)
    {
        // 남은 개수(count) 범위 내에서 랜덤한 인덱스 생성
        index = rand() % count;

        // 선택된 인덱스의 값을 당첨 배열에 저장
        lotto[i] = num[index];

        printf("%d번째 당첨번호 : %d\n", i + 1, lotto[i]);

        // 배열 밀어내기 (선택된 값 제거)
        // 뽑힌 인덱스 뒤에 있는 숫자들을 한 칸씩 앞으로 이동
        for (j = index; j < count - 1; j++)
        {
            num[j] = num[j + 1];
        }

        // 공 하나를 뽑았으므로 전체 개수 감소
        count--;
    }

    // 5. 당첨 번호 정렬 (오름차순)
    for (i = 0; i < 6 - 1; i++)
    {
        for (j = 0; j < 6 - 1 - i; j++)
        {
            if (lotto[j] > lotto[j + 1])
            {
                temp = lotto[j];
                lotto[j] = lotto[j + 1];
                lotto[j + 1] = temp;
            }
        }
    }

    // 6. 최종 결과 출력
    printf("\n[당첨 번호 정렬]\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", lotto[i]);
    }
    printf("\n");
}

int main()
{
    PJ06();
    return 0;
}