//2018115425 ±Ç¿À¹Î

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void arraymerge(int* a, int an, int* b, int bn, int* c)
{
	int i = 0, j = 0;
	int k = 0;

	while (i < an && j < bn)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			i++;
			k++;
		}
		else
		{
			c[k] = b[j];
			j++;
			k++;
		}
	}
	for (; i < an; i++)
	{
		c[k] = a[i];
		k++;
	}
	for (; j < bn; j++)
	{
		c[k] = b[j];
		k++;
	}
}
void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
			break;
		printf("%3d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 1,2,5,7,9,14,17 };
	int b[] = { 2,3,6,8,14,15 };
 	int c[20] = { 0 };

	int an = sizeof(a) / sizeof(a[0]);
	int bn = sizeof(b) / sizeof(b[0]);

	arraymerge(a, an, b, bn, c);
	
	print_array(a, an);
	print_array(b, bn);
	print_array(c, sizeof(c) / sizeof(c[0]));

	return 0;
}