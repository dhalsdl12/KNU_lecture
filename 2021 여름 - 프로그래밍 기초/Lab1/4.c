//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	double num;
	printf("실수를 입력하시오 >> ");
	scanf("%lf", &num);

	printf("지수형식으로는 %e입니다.", num);

	return 0;
}