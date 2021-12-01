#include <stdio.h>

void pointer_test()
{
	int x = 1, y = 2;
	int* ip;

	ip = &x;
	printf("%d %d %d\n", *ip, x, y);

	y = *ip;
	*ip = *ip + 10;
	printf("%d %d %d\n", *ip, x, y);

	x = x + 20;
	printf("%d %d %d\n", *ip, x, y);
}

int main()
{
	pointer_test();

	return 0;
}