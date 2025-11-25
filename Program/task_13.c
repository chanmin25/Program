/*
    파일명: task_13
    내용: 한국전력공사의 전기요금은 기본요금과 사용량에 따른 요금을 합하여 계산한다. 기본요금 산정은 [표 1]을, 사용량에 따른 요금 산정은 
         [표 2]를 기준으로 한다. 이러한 기준으로 한 달 전력 사용량에 대해 청구 요금을 계산하여 청구서를 출력하는 프로그램을 작성한다.
    작성자: 이승훈
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task13()
{
    int usage;              // 전력 사용량(kWh)
    int base_fee = 0;       // 기본요금
    double usage_fee = 0;   // 사용량 요금 (소수점 계산 필요)
    int total_elec_fee;     // 전력 요금 합계 (기본 + 사용량) (원 단위 절사 위해 int 사용)
    int vat;                // 부가세 (반올림)
    int fund;               // 전력기금 (10원 미만 절사)
    int total_bill;         // 청구 요금 (10원 미만 절사)

    printf("전기요금 청구서 출력 program\n\n");
    printf("전력사용량(Kw/h)을 입력하고 Enter>");
    scanf("%d", &usage);

    // 1. 기본요금 계산 (표 1 기준)
    if (usage <= 100)
    {
        base_fee = 390;
    }
    else if (usage <= 200)
    {
        base_fee = 870;
    }
    else if (usage <= 300)
    {
        base_fee = 1530;
    }
    else if (usage <= 400)
    {
        base_fee = 3680;
    }
    else if (usage <= 500)
    {
        base_fee = 6970;
    }
    else
    {
        base_fee = 12350;
    }

    // 2. 사용량 요금 계산 (표 2 기준 - 누진세 적용)
    // 계산 편의를 위해 남은 사용량을 줄여가며 계산하거나, 구간별로 더합니다.
    double temp_usage = (double)usage;

    if (temp_usage > 500)
    {
        usage_fee += (temp_usage - 500) * 677.3;
        temp_usage = 500;
    }
    if (temp_usage > 400)
    {
        usage_fee += (temp_usage - 400) * 398.7;
        temp_usage = 400;
    }
    if (temp_usage > 300)
    {
        usage_fee += (temp_usage - 300) * 267.8;
        temp_usage = 300;
    }
    if (temp_usage > 200)
    {
        usage_fee += (temp_usage - 200) * 179.4;
        temp_usage = 200;
    }
    if (temp_usage > 100)
    {
        usage_fee += (temp_usage - 100) * 120.2;
        temp_usage = 100;
    }
    if (temp_usage > 0)
    {
        usage_fee += temp_usage * 57.9;
    }

    // 3. 각종 세금 및 총액 계산
    // 전력요금 합계 (소수점은 없는듯함)
    total_elec_fee = base_fee + (int)usage_fee;

    // 부가세: 10% (1원 미만 반올림)
    // 반올림 공식: (int)(값 + 0.5)
    vat = (int)((total_elec_fee * 0.1) + 0.5);

    // 전력기금: 3.7% (10원 미만 절사)
    // 10원 미만 절사 공식: (값 / 10) * 10
    fund = (int)(total_elec_fee * 0.037);
    fund = (fund / 10) * 10;

    // 요금 합계
    int temp_total = total_elec_fee + vat + fund;

    // 청구 요금 (10원 미만 절사)
    total_bill = (temp_total / 10) * 10;

    // 4. 출력
    printf("\n");
    printf("기본요금 : %8d원\n", base_fee);
    printf("사용요금 : %8d원\n", (int)usage_fee);
    printf("전력요금 : %8d원\n", total_elec_fee);
    printf("전력기금 : %8d원\n", fund);
    printf("부가가치 : %8d원\n", vat);
    printf("청구요금 : %8d원\n", total_bill);
}

int main()
{
    task13();
    return 0;
}