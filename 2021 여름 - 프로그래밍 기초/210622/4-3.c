#include <stdio.h>

int main()
{
	int n = 16, ret_value = 0;

	ret_value = printf("hello\n");
	printf("%d\n", ret_value);

	ret_value = printf("Ãâ·Â°ª : %d %i %o %#o %#x %#X\n",
		n, n, n, n, n, n);
	printf("%d %i\n", 16, 16);
	printf("%o %#o\n", 16, 16);
	printf("%x %#x %#X\n", 10, 10, 10);

	return 0;
}