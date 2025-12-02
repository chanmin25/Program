

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void task27()
{
    int year;
    int gan_index;
    int ji_index;


    char* gan[] = { "경", "신", "임", "계", "갑", "을", "병", "정", "무", "기" };


    char* ji[] = { "해",  "자", "축",   "인",    "묘",  "진", "사", "오", "미",   "신",   "유", "술" };
    char* animal[] = { "돼지", "쥐", "소", "호랑이", "토끼", "용", "뱀", "말", "양", "원숭이", "닭", "개" };

    printf("서기년도를 간지로 변환\n\n");

    printf("서기년도를 입력하세요>");
    scanf("%d", &year);


    gan_index = year % 10;

    ji_index = (year - 3) % 12;

    printf("\n%d년의 간지는 %s%s년이고\n", year, gan[gan_index], ji[ji_index]);
    printf("%s띠의 해입니다.\n", animal[ji_index]);
}

int main()
{
    task27();
    return 0;
}