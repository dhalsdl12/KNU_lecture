#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int input = 0;

	do {
		printf("number : ");
		scanf("%d", &input);
	} while (input != 0);

	puts("end\n");

	return 0;
}