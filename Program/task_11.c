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
    int step;          // 호봉 (1~20, 0이면 종료)
    int has_spouse;    // 배우자 유무 (0: 없음, 1: 있음)
    int dependents;    // 부양가족 수

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

        /* 1. 본봉 계산 */
        int base_pay = 800000 + (step - 1) * 42000;  // 본봉

        /* 2. 기초 공제액 계산 */
        int basic_deduction = 1000000
            + 200000 * has_spouse
            + 100000 * dependents;

        /* 3. 과세 표준액 계산 */
        int taxable_income = 0;
        int tax = 0;
        int payment = 0;

        if (base_pay <= basic_deduction) 
        {
            // 기초 공제액보다 적으면 세금 없음
            taxable_income = 0;
            tax = 0;
            payment = base_pay;
        }
        else {
            // 기초 공제액보다 커서 세금이 있는 경우
            taxable_income = base_pay - basic_deduction;

            /* 4. 세율·누진 공제액 결정 */
            int rate;          // %
            int prog_deduct;   // 누진 공제액

            if (taxable_income < 100000) 
            {          // 10만원 미만
                rate = 5;
                prog_deduct = 3000;
            }
            else if (taxable_income < 200000) 
            {     // 10~20만원 미만
                rate = 15;
                prog_deduct = 5000;
            }
            else if (taxable_income < 300000) 
            {     // 20~30만원 미만
                rate = 20;
                prog_deduct = 10000;
            }
            else 
            {                                  // 30만원 이상
                rate = 30;
                prog_deduct = 20000;
            }

            /* 5. 세금 = 과세 표준액 * 세율 - 누진 공제액 */
            tax = taxable_income * rate / 100 - prog_deduct;

            /* 세금의 10원 미만 절사 */
            if (tax > 0)
            {
                tax = (tax / 10) * 10;
            }
            else 
            {
                tax = 0;
            }

            /* 6. 지급액 = 본봉 - 세금 */
            payment = base_pay - tax;
        }

        /* 7. 결과 출력 */
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
