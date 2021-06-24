#include <stdio.h>

int main()
{
	int x = 5, y = 10;
	
	printf("%d\n", x += y);
	printf("%d\n", x -= y);
	printf("%d\n", x *= y);
	printf("%d\n", x /= y);
	printf("%d\n", x %= y);

	printf("%d\n", x *= x + y);

	return 0;
}