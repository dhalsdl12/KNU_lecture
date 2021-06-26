#include <stdio.h>

int main()
{
	int num = 13;

	for (int i = 7; i >= 0; i--)
	{
		printf("%d", num >> i & 1);
		if (i % 4 == 0)
			putchar(' ');
	}
	puts("");

	return 0;
}