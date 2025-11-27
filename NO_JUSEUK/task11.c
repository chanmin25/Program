/*
    파일명: task_11
    내용: 어느 회사의 사원 봉급을 계산하는 프로그램을 작성한다. 호봉에 따른 본봉을 기준으로 기초 공제액, 과세 표준액,
         세금 그리고 지급액을 출력한다.
    작성자: 임승리
    날짜: 2025.11.21
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task11()
{
    int step;          
    int has_spouse;    
    int dependents;    

    while (1)
    {
        printf("\n호봉을 입력하세요(0 입력 시 종료) : ");
        scanf("%d", &step);

        if (step == 0)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        if (step < 1 || step > 20)
        {
            printf("호봉은 1~20 사이의 값만 가능합니다.\n");
            continue;
        }

        printf("배우자 유무를 입력하세요 (없음:0, 있음:1) : ");
        scanf("%d", &has_spouse);

        printf("부양가족 수를 입력하세요 : ");
        scanf("%d", &dependents);

        int base_pay = 800000 + (step - 1) * 42000;  

        int basic_deduction = 1000000
            + 200000 * has_spouse
            + 100000 * dependents;

        int taxable_income = 0;
        int tax = 0;
        int payment = 0;

        if (base_pay <= basic_deduction)
        {
            taxable_income = 0;
            tax = 0;
            payment = base_pay;
        }
        else {
            taxable_income = base_pay - basic_deduction;

            int rate;          
            int prog_deduct;   

            if (taxable_income < 100000)
            {          
                rate = 5;
                prog_deduct = 3000;
            }
            else if (taxable_income < 200000)
            {     
                rate = 15;
                prog_deduct = 5000;
            }
            else if (taxable_income < 300000)
            {     
                rate = 20;
                prog_deduct = 10000;
            }
            else
            {                                  
                rate = 30;
                prog_deduct = 20000;
            }

            tax = taxable_income * rate / 100 - prog_deduct;

            if (tax > 0)
            {
                tax = (tax / 10) * 10;
            }
            else
            {
                tax = 0;
            }

            payment = base_pay - tax;
        }

        printf("\n===== 봉급 계산 결과 =====\n");
        printf("호봉                : %d호\n", step);
        printf("본봉                : %d원\n", base_pay);
        printf("기초 공제액         : %d원\n", basic_deduction);
        printf("과세 표준액         : %d원\n", taxable_income);
        printf("세금                : %d원\n", tax);
        printf("지급액(실수령액)    : %d원\n", payment);
        printf("==========================\n");
    }
}

int main()
{
    task11();
    return 0;
}
