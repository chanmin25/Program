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
    double value;       
    int unit_num;       
    double cm_value;    

    char* unit_names[] = {
        "센티미터", "미터", "킬로미터",
        "인치", "피트", "야드",
        "마일", "자(척)", "간", "리"
    };

    printf("도량형 환산 프로그램\n\n");

    printf("환산값을 입력 : ");
    scanf("%lf", &value);

    printf("\n단위번호\n\n");
    printf("0:센티미터  1:미터      2:킬로미터\n");
    printf("3:인치      4:피트      5:야드\n");
    printf("6:마일      7:자(척)    8:간\n");
    printf("9:리\n\n");

    printf("단위번호 선택 : ");
    scanf("%d", &unit_num);

    switch (unit_num)
    {
    case 0: 
        cm_value = value;
        break;
    case 1: 
        cm_value = value * 100.0;
        break;
    case 2: 
        cm_value = value * 100000.0;
        break;
    case 3: 
        cm_value = value * 2.54;
        break;
    case 4: 
        cm_value = value * 30.48;
        break;
    case 5: 
        cm_value = value * 91.44;
        break;
    case 6: 
        cm_value = value * 160934.4;
        break;
    case 7: 
        cm_value = value * 30.303;
        break;
    case 8: 
        cm_value = value * 181.818;
        break;
    case 9: 
        cm_value = value * 39272.7;
        break;
    default:
        printf("잘못된 단위 번호입니다.\n");
        return 1;
    }

    printf("\n");
    printf("%10s %12.3f\n", unit_names[0], cm_value);             
    printf("%10s %12.3f\n", unit_names[1], cm_value / 100.0);     
    printf("%10s %12.3f\n", unit_names[2], cm_value / 100000.0);  
    printf("%10s %12.3f\n", unit_names[3], cm_value / 2.54);      
    printf("%10s %12.3f\n", unit_names[4], cm_value / 30.48);     
    printf("%10s %12.3f\n", unit_names[5], cm_value / 91.44);     
    printf("%10s %12.3f\n", unit_names[6], cm_value / 160934.4);  
    printf("%10s %12.3f\n", unit_names[7], cm_value / 30.303);    
    printf("%10s %12.3f\n", unit_names[8], cm_value / 181.818);   
    printf("%10s %12.3f\n", unit_names[9], cm_value / 39272.7);   
}

int main()
{
    task15();
    return 0;
}