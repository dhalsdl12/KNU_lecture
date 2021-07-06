#include <stdio.h>

void cbv(int a, int b)
{
	a += b;
}
void cbr(int* a, int b)
{
	*a += b;
}
int main()
{
	int a = 10;
	
	cbv(a, 20);
	printf("cbv %d\n", a);

	cbr(&a, 20);
	printf("cbr %d\n", a);

	return 0;
}