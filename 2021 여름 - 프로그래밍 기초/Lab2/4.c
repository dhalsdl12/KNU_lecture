//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a, b, c;

	printf("세 수를 입력 >> ");
	scanf("%d %d %d", &a, &b, &c);

	printf("max : %d", a > b ? (a > c ? a : c) : (b > c ? b : c));

	return 0;
}