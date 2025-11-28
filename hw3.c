#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


void simple_calculator(void)
{
    double a, b, result;
    char op;
    int status;

    printf("\n====== 간단 계산기 ======\n");
    printf("예)  3 + 5  처럼 공백을 넣어서 입력하세요.\n");
    printf("수식 입력 (숫자 연산자 숫자): ");

    status = scanf("%lf %c %lf", &a, &op, &b);
    if (status != 3) {
        printf("입력이 올바르지 않습니다. 예: 3 + 5\n");
        while (getchar() != '\n');
        return;
    }

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
        case 'x':
        case 'X':
            result = a * b;
            break;
        case '/':
            if (b == 0) {
                printf("0으로 나눌 수 없습니다.\n");
                return;
            }
            result = a / b;
            break;
        default:
            printf("지원하지 않는 연산자입니다. (+, -, *, / 만 사용)\n");
            return;
    }

    printf("결과: %.2f %c %.2f = %.2f\n", a, op, b, result);
}


void average_cal(void)
{
    int add = 0;
    int total = 0;
    int count = 0;
    double result = 0.0; 

    printf("\n====== 점수 평균 계산기 ======\n");
    printf("점수들을 1개씩 입력해주세요.\n");
    printf("입력 완료시 -1을 입력해주세요.\n");
    printf("\n");

    while (1) 
    {
        printf("점수 입력 (종료: -1): ");
        
        if (scanf("%d", &add) != 1) 
        {
            printf("\n유효하지 않은 입력입니다. 정수를 입력해 주세요.\n");
            while (getchar() != '\n');
            break;
        }

        if (add == -1) 
        {
            break; 
        }

        total += add;
        count += 1;
    }

    if (count > 0) 
    {
        result = (double)total / count; 
        
        printf("\n============================\n");
        printf("총 입력된 점수 개수: %d\n", count);
        printf("점수들의 총합: %d\n", total);
        printf("점수들의 평균: %.2f\n", result); 
        printf("============================\n");
    } 
    else 
    {
        printf("\n입력된 점수가 없어 평균을 계산할 수 없습니다.\n");
        printf("메인 메뉴로 돌아갑니다.\n");
    }
}

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

void converter_menu()
{
	double cm, m;
	int result;
	printf("센티미터(cm)를 입력하세요.");
	result = scanf("%lf", &cm);
	if (result != 1){
		printf("입력이 올바르지 않습니다.\n");
		return;
	}
	m = cm / 100.0;
	printf("%.2f cm는 %.2f m 입니다.\n", cm, m);
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
                converter_menu();
				break;

            case 2:
                printf("\n간단 계산기를 실행합니다.\n");
				simple_calculator();
                break;

            case 3:
                printf("\n점수 평균 계산기를 실행합니다.\n");
                average_cal();
                break;

            case 4:
                printf("\n문자열 처리를 실행합니다.\n");
                string_change();
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
