//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define sq2(x) x*x
#define sq4(x) sq2(x)*sq2(x)

int main()
{
	float num;

	printf("x의 값을 실수로 입력하시오 : ");
	scanf("%f", &num);

	printf("x의 제곱은 %.1f입니다.\n", sq2(num));
	printf("x의 네제곱은 %.1f입니다.\n", sq4(num));

	return 0;
}