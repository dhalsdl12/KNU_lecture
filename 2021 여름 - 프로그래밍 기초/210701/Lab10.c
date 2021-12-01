#include <stdio.h>

void myprintA(int a, int b)
{
	printf("%d %d\n", a, b);
}
void myprintB()
{
	printf("C language\n");
}
void myprintC()
{
	printf("bye\n");
}

int main()
{
	myprintA(1, 2);
	myprintB();
	myprintC();

	return 0;
}