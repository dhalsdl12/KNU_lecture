#include <stdio.h>
#include <stdlib.h>

typedef struct element* link;
typedef struct element {
	int data;
	link link;
};
int main()
{
	link a;
	int* b;

	a = calloc(5, sizeof(*a));
	if (a == NULL)
	{
		printf("a NULL\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i].data);
		printf("%p ", &a[i]);
		printf("%p \n", a[i].link);
	}


}