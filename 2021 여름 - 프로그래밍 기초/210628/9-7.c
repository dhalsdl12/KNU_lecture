#include <stdio.h>

int main()
{
	int score[] = { 89,98,76 };

	printf("%p, %p\n", score, &score[0]);
	printf("%d, %d\n", *score, score[0]);
	
	for (int i = 0; i < 3; i++)
		printf("%2d %10p %6d\n", i, (score + i), *(score + i));
}