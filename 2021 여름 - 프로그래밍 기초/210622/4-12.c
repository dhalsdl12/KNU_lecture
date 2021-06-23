#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a, b, c;

	printf("10 8 16\n");
	scanf("%d %o %x", &a, &b, &c);
	printf("%d %#o %#x\n\n", a, b, c);

	printf("10 8 16\n");
	scanf("%i %i %i", &a, &b, &c);
	printf("%d %d %d\n\n", a, b, c);
}