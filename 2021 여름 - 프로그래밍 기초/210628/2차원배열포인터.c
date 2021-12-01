#include <stdio.h>

int main()
{
	int ary[][4] = { 5,7,6,2,7,8,1,3 };
	int(*ptr)[4] = ary;

	printf("%2d, %2d\n", **ary, **ptr++);
	printf("%2d, %2d\n", **(ary+1), **(ptr++));
	
	ptr = ary;
	printf("%d\n", **ptr);
	printf("%2d, %2d\n", *(ary[1] + 1), *(ptr[1] + 1));
	printf("%2d, %2d\n", *(*(ary + 1) + 3), *(*(ptr + 1) + 3));
	printf("sizeof(ary) %d, sizeof(ptr) %d\n",
		sizeof(ary), sizeof(ptr));
}