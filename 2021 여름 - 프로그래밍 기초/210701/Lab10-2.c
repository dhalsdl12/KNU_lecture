#include <stdio.h>

void counter(int count)
{
	if (count == 0)
	{
		printf("finish\n");
		return;
	}
	counter(count - 1);
	printf("count : %d\n", count);
}
int main()
{
	counter(10);

	return 0;
}