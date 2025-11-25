/*
    파일명: task_15
    내용: 거리에 대한 값과 단위가 입력되면 다음의 도량형 환산표를 기준으로 하여 나머지 단위의 환산 값들을 단위와 함께 출력하는 프로그램을 작성한다.   
    작성자: 이승훈
    날짜: 2025.11.25
    버전: v1.0
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void task15()
{
    double value;       // 입력받은 값
    int unit_num;       // 입력받은 단위 번호
    double cm_value;    // cm 단위로 변환된 기준 값

    // 단위 이름 배열
    char* unit_names[] = {
        "센티미터", "미터", "킬로미터",
        "인치", "피트", "야드",
        "마일", "자(척)", "간", "리"
    };

    printf("도량형 환산 프로그램\n\n");

    // 1. 입력
    printf("환산값을 입력 : ");
    scanf("%lf", &value);

    printf("\n단위번호\n\n");
    printf("0:센티미터  1:미터      2:킬로미터\n");
    printf("3:인치      4:피트      5:야드\n");
    printf("6:마일      7:자(척)    8:간\n");
    printf("9:리\n\n");

    printf("단위번호 선택 : ");
    scanf("%d", &unit_num);

    // 2. 처리: 모든 단위를 기준 단위(cm)로 변환
    switch (unit_num)
    {
    case 0: // cm -> cm
        cm_value = value;
        break;
    case 1: // m -> cm
        cm_value = value * 100.0;
        break;
    case 2: // km -> cm
        cm_value = value * 100000.0;
        break;
    case 3: // inch -> cm
        cm_value = value * 2.54;
        break;
    case 4: // ft -> cm
        cm_value = value * 30.48;
        break;
    case 5: // yd -> cm
        cm_value = value * 91.44;
        break;
    case 6: // mile -> cm
        cm_value = value * 160934.4;
        break;
    case 7: // 자(척) -> cm
        cm_value = value * 30.303;
        break;
    case 8: // 간 -> cm
        cm_value = value * 181.818;
        break;
    case 9: // 리 -> cm
        cm_value = value * 39272.7;
        break;
    default:
        printf("잘못된 단위 번호입니다.\n");
        return 1;
    }

    // 3. 출력: 기준 값(cm)을 각 단위로 다시 변환하여 출력
    printf("\n");
    // %10s: 문자열 10칸 확보, %12.3f: 실수 12칸 확보하고 소수점 3자리까지
    printf("%10s %12.3f\n", unit_names[0], cm_value);             // cm
    printf("%10s %12.3f\n", unit_names[1], cm_value / 100.0);     // m
    printf("%10s %12.3f\n", unit_names[2], cm_value / 100000.0);  // km
    printf("%10s %12.3f\n", unit_names[3], cm_value / 2.54);      // inch
    printf("%10s %12.3f\n", unit_names[4], cm_value / 30.48);     // ft
    printf("%10s %12.3f\n", unit_names[5], cm_value / 91.44);     // yd
    printf("%10s %12.3f\n", unit_names[6], cm_value / 160934.4);  // mile
    printf("%10s %12.3f\n", unit_names[7], cm_value / 30.303);    // 자
    printf("%10s %12.3f\n", unit_names[8], cm_value / 181.818);   // 간
    printf("%10s %12.3f\n", unit_names[9], cm_value / 39272.7);   // 리
}

int main()
{
    task15();
    return 0;
}