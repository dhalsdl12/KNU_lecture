//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("1���� 9������ ���� 1���� �Է��ϼ��� : \n");
	scanf("%d", &num);
	printf("\n");

	printf("���:\n");
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d", j);
		}
		for (int j = i + 1; j <= num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}