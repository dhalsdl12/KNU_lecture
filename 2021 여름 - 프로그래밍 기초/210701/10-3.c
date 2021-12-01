#include <stdio.h>


int sumary(int* ary, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += *(ary + i);

	return sum;
}
int main()
{
	int point[] = { 95,88,76,54,85,33,65,78,99,82 };
	int* address = point;
	int length = sizeof(point) / sizeof(int);

	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += *(point + i);
	}
	printf("main sum = %d\n", sum);

	printf("sumary() sum = %d\n", sumary(point, length));
	printf("sumary() sum = %d\n", sumary(&point[0], length));
	printf("sumary() sum = %d\n", sumary(address, length));

	return 0;
}