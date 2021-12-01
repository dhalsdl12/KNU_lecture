#include <stdio.h>

int main()
{
	int x = 16391;

	printf("%6d, %08x\n", x, x);
	printf("%6d, %08x\n", x >> 1, x >> 1);
	printf("%6d, %08x\n", x >> 2, x >> 2);
	printf("%6d, %08x\n", x >> 3, x >> 3);
	printf("%6d, %08x\n", x << 2, x << 2);
	printf("%6d, %08x\n", x << 3, x << 3);

	return 0;
}