#include <stdio.h>

typedef struct {
	char aa;
	int bb;
	char cc;
}pack1;
typedef struct {
	char aa;
	char cc;
	int bb;
}pack2;
typedef struct {
	char aa;
	double cc;
}pack3;

int main()
{
	pack1 pa1;
	pack2 pa2;
	pack3 pa3;

	printf("%d\n", sizeof(pa1));
	printf("%d\n", sizeof(pa2));
	printf("%d\n", sizeof(pa3));
}