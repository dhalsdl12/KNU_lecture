#include <stdio.h>

int main()
{
	int val = 0x61626364;
	int* pi = &val;
	char* pc = (char*)&val;

	printf("value	%0#x	%p\n", val, pi);

	for (int i = 0; i <= 3; i++)
	{
		char ch = *(pc + i);
		printf("*(pc+%d)	%0#6x	%2c	%p\n", 
			i, ch, ch, pc + i);
	}
	return 0;
}