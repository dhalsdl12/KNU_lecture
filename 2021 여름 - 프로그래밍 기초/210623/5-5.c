#include <stdio.h>

int main()
{
	printf("%d\n", 3 > 4);
	printf("%d\n", 3 < 4.0);
	printf("%d\n", 'a' <= 'b');
	printf("%d\n", 'Z' <= 'a');
	printf("%d\n", 4.27 >= 4.35);
	printf("%d\n", 4 != 4.0);
	printf("%d\n", 4.0F == 4.0);

	return 0;
}