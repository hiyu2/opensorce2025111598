#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double cm, m;
    int result;

    printf("센티미터(cm)를 입력하세요: ");
    result = scanf("%lf", &cm);
    if (result != 1) {
        printf("입력이 올바르지 않습니다.\n");
        return 1;
    }

    m = cm / 100.0;

    printf("%.2f cm는 %.2f m 입니다.\n", cm, m);

    return 0;
}
