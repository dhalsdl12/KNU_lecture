//2018115425 ±Ç¿À¹Î

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	for (int i = 32; i <= 126; i++)
	{
		printf("%c  ", i);
		if ((i - 7) % 8 == 0)
			printf("\n");
	}
}