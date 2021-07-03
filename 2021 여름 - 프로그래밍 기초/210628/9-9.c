#include <stdio.h>

int main()
{
	char c[4] = { 'a', '\0', '\0' , '\0' };
	int* pi = (int*)&c[0];
	char* pc = &c[0];

	printf("pi\n");
	printf("%d %c\n", c[0], c[0]);
	printf("%d %c\n", *pi, *pi);
	printf("pc\n");
	printf("%d %c\n", *pc, *pc);
}