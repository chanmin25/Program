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
    int cc;             
    int age;                
    int tax_per_cc;     
    double rate;        
    double total_tax;   

    printf("승용차 세금 계산 program\n\n");

    printf("승용차의 배기량(cc)을 입력하고 Enter>");
    scanf("%d", &cc);

    printf("차 구입후 경과년수를 입력하고 Enter>");
    scanf("%d", &age);

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
        tax_per_cc = 286;
    }

    if (age < 3)
    {
        rate = 1.0;
    }
    else if (age >= 12)
    {
        rate = 0.5;
    }
    else
    {

        rate = (100 - (age - 2) * 5) / 100.0;
    }


    total_tax = cc * tax_per_cc * rate;

    printf("\n배기량   : %d cc\n", cc);
    printf("경과년수 : %d 년\n", age);
    printf("세금총액 : %.0lf 원\n", total_tax);
}

int main()
{
    task12();
    return 0;
}