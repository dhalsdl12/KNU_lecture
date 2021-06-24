#include <stdio.h>

int main()
{
	int x = 127;
	printf("%5d %08x\n", x, x);
	printf("%08x\n", x & 1);
	printf("%08x\n", x | 1);
	printf("%08x\n", x ^ 1);
	printf("%08x\n", ~(-1));
	printf("%08x\n", ~1);
}