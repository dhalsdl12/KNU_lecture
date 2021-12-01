#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int dec = 30, oct = 012, hex = 0x5E;

	printf("정수입력\n");
	printf("10 - 8 - 16\n");

	scanf("%d - %o - %x", &dec, &oct, &hex);
	printf("%d - %o - %x\n", dec, oct, hex);
	printf("%d - %d - %d\n", dec, oct, hex);

	return 0;
}