

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task08()
{
    double height, weight; 
    double std_weight;     
    double bmi;            
    double obesity;        

    printf("비만도 측정 program\n\n");

    printf("신장(cm)을 입력하고 Enter> ");
    scanf("%lf", &height);
    printf("체중(kg)을 입력하고 Enter> ");
    scanf("%lf", &weight);

    std_weight = (height - 100.0) * 0.9;

    bmi = weight / ((height / 100.0) * (height / 100.0));

    obesity = (weight - std_weight) / std_weight * 100.0;

    printf("\n판정 결과\n\n");
    printf("표준체중(kg) : %.1lf\n", std_weight);
    printf("신체질량지수 : %.1lf\n", bmi);

    printf("지수에 대한 비만 판정: ");
    if (bmi < 20.0)
    {
        printf("저체중\n");
    }
    else if (bmi <= 24.0)
    {
        printf("정상 체중\n");
    }
    else if (bmi <= 30.0)
    {
        printf("과체중\n");
    }
    else
    {
        printf("병적 비만\n");
    }

    printf("비만도(%%) : %.1lf\n", obesity);

    printf("비만도에 대한 판정 : ");
    if (obesity < 10.0)
    {
        printf("정상 체중\n");
    }
    else if (obesity <= 19.0)
    {
        printf("과체중\n");
    }
    else
    {
        printf("비만\n");
    }
}

int main()
{
    task08();
    return 0;
}