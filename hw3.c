#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int main(void) {
    int menu;

    while (1) {
        printf("\n==== 메인 메뉴 ====\n");
        printf("1) 단위 변환기\n");
        printf("2) 간단 계산기\n");
        printf("3) 점수 평균 계산\n");
        printf("4) 문자열 처리\n");
        printf("5) 랜덤 비밀번호 생성기\n");
	printf("6) 종료\n");
        printf("선택: ");

        if (scanf("%d", &menu) != 1) break;

        switch (menu) {
            case 1:            break;
            case 2:      break;
            case 3:       break;
            case 4:   
                string_change();
                break;
	    case 5: break;
            case 6: 
                printf("종료합니다.\n");
                return 0;
            default:
                printf("1~6 중 선택하세요.\n");
        }
    }

    return 0;
}
