#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int main()
{
	long seconds = (long)time(NULL);
	srand(seconds);

	printf("1~%3d사이의 난수 5개: \n", max);

	for (int i = 0; i < 5; i++)
	{
		printf("%5d ", rand() % max + 1);
	}
	puts("");

	return 0;
}