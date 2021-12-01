//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("1에서 9사이의 정수 1개를 입력하세요 : \n");
	scanf("%d", &num);
	printf("\n");

	printf("출력:\n");
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