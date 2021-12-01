#include <stdio.h>

int main()
{
	int a, b, c;
	a = b = c = 5;

	printf("%d\n", a = a + 2);
	printf("%d\n", a);
	printf("%d\n", a = b + c);
	printf("%d\n", a);
}