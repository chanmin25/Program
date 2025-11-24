/*
    파일명: project_16
    내용: 패스트푸드 전문점에서 메뉴를 선택하고, 금액과 잔돈을 계산하기까지의 과정이 현장에서 이루어지는 것과 같은 방법으로 점원의 입장에서 금전등록기(또는 POS: Point of Sale)를
          조작하는 과정을 처리하는 프로그램을 작성한다.
    작성자: 이승훈
    날짜: 2025.11.23
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 메뉴 정보를 담을 구조체
typedef struct
{
    int id;
    char name[30];
    int price;
} Menu;

// 주문 정보를 담을 구조체
typedef struct
{
    int menuIdx; // 메뉴 배열의 인덱스
    int count;   // 주문 수량
} Order;

// 메뉴 데이터 초기화
Menu menus[] =
{
    {10, "치즈버거세트", 3300}, {11, "더블버거세트", 4500}, {12, "치킨세트", 10000},
    {20, "치즈버거", 1600}, {21, "더블버거", 2900}, {22, "햄버거", 1200},
    {30, "아이스크림", 1200}, {31, "포테이토", 1800}, {32, "빙수", 2000},
    {40, "콜라", 1000}, {41, "커피", 1100}, {42, "밀크쉐이크", 1500}
};
int menuCount = 12;

// 주문 내역을 저장할 배열 (최대 100개 주문 가능)
Order orders[100];
int orderCount = 0; // 현재 주문 건수

// 메뉴판 출력 함수
void print_menu(int total)
{
    printf("\n");
    printf("세트메뉴                  버거메뉴\n");
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[0].id, menus[0].name, menus[0].price, menus[3].id, menus[3].name, menus[3].price);
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[1].id, menus[1].name, menus[1].price, menus[4].id, menus[4].name, menus[4].price);
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[2].id, menus[2].name, menus[2].price, menus[5].id, menus[5].name, menus[5].price);
    printf("\n");
    printf("디저트메뉴                음료메뉴\n");
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[6].id, menus[6].name, menus[6].price, menus[9].id, menus[9].name, menus[9].price);
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[7].id, menus[7].name, menus[7].price, menus[10].id, menus[10].name, menus[10].price);
    printf("%d%-14s %5d   %d%-12s %5d\n", menus[8].id, menus[8].name, menus[8].price, menus[11].id, menus[11].name, menus[11].price);

    printf("\n지불할 총액 :    %d\n\n", total);
    printf("1. 추가  2. 취소 3. 입력종료\n");
}

// 메뉴 ID로 메뉴 배열의 인덱스를 찾는 함수
int find_menu_index(int id)
{
    for (int i = 0; i < menuCount; i++)
    {
        if (menus[i].id == id) return i;
    }
    return -1;
}

void PJ16()
{
    int choice, menuID, count, i;
    int total = 0;
    int payment, change;

    while (1)
    {
        print_menu(total);
        printf("번호 선택 후 Enter : ");
        scanf("%d", &choice);

        if (choice == 1)
        { // [추가]
            printf("메뉴번호 입력후 Enter :");
            scanf("%d", &menuID);
            int idx = find_menu_index(menuID);

            if (idx != -1)
            {
                printf("수량 입력후 Enter >");
                scanf("%d", &count);

                // 주문 내역에 추가
                orders[orderCount].menuIdx = idx;
                orders[orderCount].count = count;
                orderCount++;

                // 총액 갱신
                total += menus[idx].price * count;
            }
            else {
                printf("잘못된 메뉴 번호입니다.\n");
            }

        }
        // 취소
        else if (choice == 2)
        {
            printf("선택한 메뉴\n");
            // 현재 주문 내역 출력
            for (i = 0; i < orderCount; i++)
            {
                // 취소된 주문(수량 0)은 출력 제외
                if (orders[i].count > 0)
                {
                    int mIdx = orders[i].menuIdx;
                    printf("%d%-14s *%d-  %d\n",
                        menus[mIdx].id, menus[mIdx].name, orders[i].count, menus[mIdx].price * orders[i].count);
                }
            }

            printf("취소할 메뉴버튼 입력 후 Enter(0: cancel) >");
            scanf("%d", &menuID);

            if (menuID != 0)
            {
                int found = 0;
                // 주문 내역 뒤에서부터 검색하여 해당 메뉴 취소 (가장 최근 주문 취소)
                for (i = orderCount - 1; i >= 0; i--)
                {
                    if (orders[i].count > 0 && menus[orders[i].menuIdx].id == menuID)
                    {
                        total -= menus[orders[i].menuIdx].price * orders[i].count;
                        orders[i].count = 0; // 수량을 0으로 만들어 취소 처리
                        found = 1;
                        break; // 하나만 취소하고 중단
                    }
                }
                if (!found) printf("해당 메뉴의 주문 내역이 없습니다.\n");
            }

        }
        // 입력종료
        else if (choice == 3)
        {
            printf("\n고객이 지불할 총액은    %d원 입니다.\n", total);
            printf("고객으로부터 받은 금액을 입력 후 Enter>");
            scanf("%d", &payment);

            if (payment >= total)
            {
                change = payment - total;
                printf("\n명세표\n");
                for (i = 0; i < orderCount; i++)
                {
                    if (orders[i].count > 0)
                    {
                        int mIdx = orders[i].menuIdx;
                        printf("%d%-14s *%d-  %d\n",
                            menus[mIdx].id, menus[mIdx].name, orders[i].count, menus[mIdx].price * orders[i].count);
                    }
                }
                printf("금액 :    %d\n", total);
                printf("잔돈 :    %d\n", change);
                break;
            }

            else
            {
                printf("금액이 부족합니다.\n");
            }
        }
    }
}

int main()
{
    PJ16();
    return 0;
}