//2018115425 �ǿ���

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
		printf("������ �Է��ϼ��� : ");
		scanf("%d", &a);

		getchar();
		printf("�����ڸ� �Է��ϼ��� : ");
		scanf("%c", &c);

		printf("������ �Է��ϼ��� : ");
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
			printf("�׷� �����ڴ� �����ϴ�.\n");
		}
		
		printf("1�� �� ���� �Ͻðڽ��ϱ�? (Y/N) : ");
		getchar();
		scanf("%c", &yn);
		printf("\n");
		
		if (yn == 'N' || yn == 'n')
			break;
		else if (yn == 'Y' || yn == 'y')
			continue;
	}
	printf("\n���α׷��� �����ϴϴ�.\n");
	
	return 0;
}