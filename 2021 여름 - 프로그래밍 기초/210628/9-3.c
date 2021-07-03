#include <stdio.h>

#define ROWSIZE 2
#define COLSIZE 3

int main()
{
	int td[ROWSIZE][COLSIZE];
	int cnt = 1;

	for (int i = 0; i < ROWSIZE; i++)
	{
		for (int j = 0; j < COLSIZE; j++)
			td[i][j] = cnt++;
	}
	for (int i = 0; i < ROWSIZE; i++)
	{
		for (int j = 0; j < COLSIZE; j++)
			printf("td[%d][%d] == %d ", i, j, td[i][j]);
		printf("\n");
	}
}