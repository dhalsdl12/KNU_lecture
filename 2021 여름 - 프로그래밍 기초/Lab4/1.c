//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("정수 1개를 입력하세요 : \n");
	scanf("%d", &num);
	printf("\n");

	printf("5의 배수를 제외한 모든 홀수 :\n");
	for (int i = 1; i <= num; i++)
	{
		if (i % 5 != 0)
		{
			if (i % 2 == 1)
				printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}