#include <stdio.h>

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
		
        if (menu<1 || menu>6) 
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
				average_cal();
				break;
            case 4: 
				printf("\n문자열 처리를 실행합니다.\n");
				break;
	    	case 5: 
				printf("\n랜덤 비밀번호 생성기를 실행합니다.\n");
				break;
            case 6: 
                printf("\n미니 도구 모음팩을 종료합니다.\n");
                return 0;
            default:
                printf("\n1~6 중 선택하세요.\n");
        }
    }

    return 0;
}
