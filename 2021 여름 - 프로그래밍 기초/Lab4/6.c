//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("행의 수를 선택하세요: ");
	scanf("%d", &num);
	printf("\n");
	for (int i = 0; i < num; i++)
	{
		for (int j = num - i - 1; j > 0; j--)
		{
			printf(" ");
		}
		for (int k = i; k >= 0; k--)
		{
			printf("%d", k);
		}
		for (int k = 1; k <= i; k++)
		{
			printf("%d", k);
		}
		printf("\n");
	}

	return 0;
}