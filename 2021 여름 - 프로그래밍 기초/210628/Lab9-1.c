#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int input[20] = { 0 };
	int i = 0;
	printf("input number (exit 0): ");

	do {
		scanf("%d", &input[i]);
	} while (input[i++] != 0);

	i = 0;
	while (input[i] != 0)
	{
		printf("%d ", input[i++]);
	}
	puts("");
}