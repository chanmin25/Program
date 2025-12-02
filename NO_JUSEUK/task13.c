

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task13()
{
    int usage;              
    int base_fee = 0;       
    double usage_fee = 0;   
    int total_elec_fee;     
    int vat;                
    int fund;               
    int total_bill;         

    printf("전기요금 청구서 출력 program\n\n");
    printf("전력사용량(Kw/h)을 입력하고 Enter>");
    scanf("%d", &usage);

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


    total_elec_fee = base_fee + (int)usage_fee;


    vat = (int)((total_elec_fee * 0.1) + 0.5);


    fund = (int)(total_elec_fee * 0.037);
    fund = (fund / 10) * 10;

    int temp_total = total_elec_fee + vat + fund;

    total_bill = (temp_total / 10) * 10;

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