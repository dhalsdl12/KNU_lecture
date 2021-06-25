#include <stdio.h>

int main()
{
	int data = 100;
	int* ptrint;

	ptrint = &data;

	printf("  data %p %8d\n", &data, data);
	printf("ptrint %p %8p\n", &ptrint, ptrint);

	return 0;
}