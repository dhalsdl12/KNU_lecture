//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	char c;
	char yn;

	while (1)
	{
		printf("정수를 입력하세요 : ");
		scanf("%d", &a);

		getchar();
		printf("연산자를 입력하세요 : ");
		scanf("%c", &c);

		printf("정수를 입력하세요 : ");
		scanf("%d", &b);

		switch (c) {
		case '+':
			printf(">>> %d + %d = %d\n", a, b, a + b);
			break;
		case '-':
			printf(">>> %d - %d = %d\n", a, b, a - b);
			break;
		case '*':
			printf(">>> %d * %d = %d\n", a, b, a * b);
			break;
		case '/':
			if (b == 0)
				printf(">>> Error\n");
			else
				printf(">>> %d / %d = %.2lf\n", a, b, a / (double)b);
			break;
		default:
			printf("그런 연산자는 없습니다.\n");
		}
		
		printf("1번 더 수행 하시겠습니까? (Y/N) : ");
		getchar();
		scanf("%c", &yn);
		printf("\n");
		
		if (yn == 'N' || yn == 'n')
			break;
		else if (yn == 'Y' || yn == 'y')
			continue;
	}
	printf("\n프로그램을 종료하니다.\n");
	
	return 0;
}