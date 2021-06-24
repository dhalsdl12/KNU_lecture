//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int num;
	printf("정수 천만 이하의 하나의 수를 입력 >> ");

	scanf("%d", &num);

	printf("입력한 수 %d는 ", num);
	if (num >= 10000)
	{
		printf("%d만 ", num / 10000);
		num %= 10000;
	}
	if (num >= 1000)
	{
		printf("%d천 ", num / 1000);
		num %= 1000;
	}
	if (num >= 100)
	{
		printf("%d백 ", num / 100);
		num %= 100;
	}
	if (num >= 10)
	{
		printf("%d십 ", num/10);
		num %= 10;
	}
	if (num >= 1)
	{
		printf("%d", num);
	}
	printf("입니다.\n");

	return 0;
}