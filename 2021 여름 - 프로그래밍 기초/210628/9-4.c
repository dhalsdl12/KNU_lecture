#include <stdio.h>

int main()
{
	int td[][3] = { {1}, {1,2,3} };
	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", td[i][j]);
		printf("\n");
	}

	return 0;
}