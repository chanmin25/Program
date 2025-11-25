/*
    파일명: task_12
    내용: 승용차에 대한 승용 세율 [표 1]과 세금 할인율 [표 2], 그리고 세금 계산 방법에 의해 승용차의 배기량(cc)과 구입 후 경과 년을 입력하면 
         자동차세금을 출력하는 프로그램을 작성한다.
    작성자: 정찬민
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task12()
{
    int cc;             // 배기량
    int age;            // 경과년수
    int tax_per_cc;     // cc당 세율
    double rate;        // 납부 비율 (할인율 적용 후)
    double total_tax;   // 최종 세금

    printf("승용차 세금 계산 program\n\n");

    // 1. 입력
    printf("승용차의 배기량(cc)을 입력하고 Enter>");
    scanf("%d", &cc);

    printf("차 구입후 경과년수를 입력하고 Enter>");
    scanf("%d", &age);

    // 2. 배기량에 따른 세율 결정
    if (cc <= 800)
    {
        tax_per_cc = 104;
    }
    else if (cc <= 1000)
    {
        tax_per_cc = 130;
    }
    else if (cc <= 1600)
    {
        tax_per_cc = 182;
    }
    else if (cc <= 2000)
    {
        tax_per_cc = 260;
    }
    else if (cc <= 2500)
    {
        tax_per_cc = 286;
    }
    else
    {
        // 2500cc 초과
        tax_per_cc = 286;
    }

    // 3. 경과년도에 따른 할인율(납부 비율) 결정    
    if (age < 3)
    {
        // 3년 미만: 100% 할인율
        rate = 1.0;
    }
    else if (age >= 12)
    {
        // 12년 이상: 50% 할인율
        rate = 0.5;
    }
    else
    {
        // 3년 ~ 11년: 매년 5%씩 감소
        // 공식: 100 - (경과년수 - 2) * 5
        rate = (100 - (age - 2) * 5) / 100.0;
    }

    // 4. 최종 세금 계산
    // 공식: 배기량 * 세율 * 할인율
    total_tax = cc * tax_per_cc * rate;

    // 5. 출력
    printf("\n배기량   : %d cc\n", cc);
    printf("경과년수 : %d 년\n", age);
    printf("세금총액 : %.0lf 원\n", total_tax);
}

int main()
{
    task12();
    return 0;
}