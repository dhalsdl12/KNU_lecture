//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int mask = 0xffff;

	printf("정수 하나를 입력하시오 : ");
	scanf("%d", &num);

	num = num & mask;
	printf("입력값 %d의 하위 16비트는 8진수로 %#o, \
16진수로 %#x\n", num, num, num);

	return 0;
}