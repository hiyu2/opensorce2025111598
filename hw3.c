#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

void to_upper(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

void string_change() {
    char str[100];
    char str1[100];

    printf("소문자 문자열 입력: ");
    scanf("%s", str);

    to_upper(str);

    printf("대문자 변환: %s\n", str);

    printf("대문자 문자열 입력: ");
    scanf("%s", str1);

    to_lower(str1);

    printf("소문자 변환: %s\n", str1);
}


void generate_random_password(char *password, size_t length)
{
    const char charset[] =
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$^&*()_+[]{}|;:,.<>?";

    size_t charset_size = sizeof(charset) - 1;

    for (size_t i = 0; i < length; i++) {
        int key = rand() % charset_size;
        password[i] = charset[key];
    }
    password[length] = '\0';
}

void password_menu(void)
{
    size_t password_length = 12;
    char password[password_length + 1];

    srand((unsigned int)time(NULL));

    generate_random_password(password, password_length);

    printf("\n====== 랜덤 비밀번호 생성기 ======\n");
    printf("생성된 비밀번호: %s\n", password);
    printf("=================================\n");
}


int main(void) 
{
    int menu;

    while (1) 
    {
        printf("\n==== 메인 메뉴 ====\n");
        printf("1) 단위 변환기\n");
        printf("2) 간단 계산기\n");
        printf("3) 점수 평균 계산\n");
        printf("4) 문자열 처리\n");
        printf("5) 랜덤 비밀번호 생성기\n");
        printf("6) 종료\n");
        printf("\n선택: ");

        if (scanf("%d", &menu) != 1) 
        {
            printf("\n1~6의 정수를 입력해주세요.\n");
            while (getchar() != '\n');
            break;
        }

        if (menu < 1 || menu > 6) 
        {
            printf("\n1~6의 정수를 입력해주세요.\n");
            continue;
        }

        switch (menu) 
        {
            case 1:
                printf("\n단위 변환기를 실행합니다.\n");
                break;

            case 2:
                printf("\n간단 계산기를 실행합니다.\n");
                break;

            case 3:
                printf("\n점수 평균 계산기를 실행합니다.\n");
                break;

            case 4:
                printf("\n문자열 처리를 실행합니다.\n");
                break;

            case 5:
                printf("\n랜덤 비밀번호 생성기를 실행합니다.\n");
                password_menu(); 
                break;

            case 6:
                printf("\n미니 도구 모음팩을 종료합니다.\n");
                return 0;
        }
    }

    return 0;
}
