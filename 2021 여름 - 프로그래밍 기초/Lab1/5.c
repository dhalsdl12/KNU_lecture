//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("10진수 정수 입력 >> ");
	scanf("%d", &num);
	printf("10진수: %d, 8진수: %#o, 16진: %#x\n\n", num, num, num);

	printf("8진수 정수 입력 (예: 77)>> ");
	scanf("%o", &num);
	printf("10진수: %d, 8진수: %#o, 16진: %#x\n\n", num, num, num);

	printf("16진수 정수 입력 (예: 1a0)>> ");
	scanf("%x", &num);
	printf("10진수: %d, 8진수: %#o, 16진: %#x\n\n", num, num, num);

	printf("8진수 정수 입력 (예: 077)>> ");
	scanf("%o", &num);
	printf("10진수: %d, 8진수: %o, 16진: %x\n\n", num, num, num);

	printf("16진수 정수 입력 (예: 0x1a0)>> ");
	scanf("%x", &num);
	printf("10진수: %d, 8진수: %o, 16진: %x\n\n", num, num, num);

	return 0;
}