//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x, y;
	printf("2차원 좌표 x와 y값을 입력하시오 (예: 3 5) ");
	scanf("%d %d", &x, &y);

	if (x > 0 && y > 0)
		printf("1사분면\n");
	else if (x < 0 && y > 0)
		printf("2사분면\n");
	else if (x < 0 && y < 0)
		printf("3사분면\n");
	else if (x > 0 && y < 0)
		printf("4사분면\n");

	return 0;
}