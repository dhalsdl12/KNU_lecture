//2018115425 권오민

#include <stdio.h>

void trans(int data[], int array[][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = data[i * 3 + j];
		}
	}
}
void print_2array(int array[][3], int row, int col)
{
	printf("1차원 배열을 2차원 배열로 (4X3) 변환\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%3d", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void print_1array(int data[], int onesize)
{
	printf("1차원 배열\n");
	for (int i = 0; i < onesize; i++)
	{
		printf("%3d", data[i]);
	}
	printf("\n");
}
int main()
{
	int data[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int array[4][3] = { 0 };
	int onesize = sizeof(data) / sizeof(int);
	int row = sizeof(array) / sizeof(array[0]);
	int col = sizeof(array[0]) / sizeof(array[0][0]);

	trans(data, array, row, col);
	print_1array(data, onesize);
	print_2array(array, row, col);
}