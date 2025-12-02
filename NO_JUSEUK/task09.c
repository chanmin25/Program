

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void task09()
{
    char* city[] = { "서울", "수원", "천안", "대전", "대구", "부산" };


    int toll_table[6][6] = {
        {0, 1700, 4200, 7500, 15200, 19300}, 
        {0, 0,    3400, 6700, 13600, 17800}, 
        {0, 0,    0,    4200, 11000, 15000}, 
        {0, 0,    0,    0,    7800,  12100}, 
        {0, 0,    0,    0,    0,     4500 }, 
        {0, 0,    0,    0,    0,     0    }  
    };

    int start_code, end_code;
    int temp; 

    printf("고속도로 통행료 계산 program\n\n");

    printf("각 도시별 번호\n");
    printf("서울(0) 수원(1) 천안(2)\n");
    printf("대전(3) 대구(4) 부산(5)\n\n");

    printf("출발지 도시번호 입력하고 Enter>");
    scanf("%d", &start_code);

    printf("도착지 도시번호 입력하고 Enter>");
    scanf("%d", &end_code);

    if (start_code < 0 || start_code > 5 || end_code < 0 || end_code > 5)
    {
        printf("잘못된 도시 번호입니다.\n");
        return 0;
    }

    int s = start_code;
    int e = end_code;

    if (s > e)
    {
        temp = s;
        s = e;
        e = temp;
    }
    else if (s == e)
    {
        printf("출발지와 도착지가 같습니다.\n");
        return 0;
    }


    printf("%s에서 %s까지 요금 : %d 원\n", city[start_code], city[end_code], toll_table[s][e]);
}

int main()
{
    task09();
    return 0;
}