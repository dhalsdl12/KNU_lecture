#include <stdio.h>

int main()
{
	int num = 13;

	printf("%d", num >> 7 & 1);
	printf("%d", num >> 6 & 1);
	printf("%d", num >> 5 & 1);
	printf("%d", num >> 4 & 1); putchar(' ');
	printf("%d", num >> 3 & 1);
	printf("%d", num >> 2 & 1);
	printf("%d", num >> 1 & 1);
	printf("%d", num >> 0 & 1); puts("");

	return 0;
}