#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int i, sum, max;

	scanf("%d", &max);

	for (i = 1, sum = 0; i <= max; i++)
	{
		sum += i;
	}
	printf("for sum = %d\n", sum);

	i = 1, sum = 0;
	while (i <= max)
	{
		sum += i;
		i++;
	}
	printf("while sum = %d\n", sum);

	return 0;
}