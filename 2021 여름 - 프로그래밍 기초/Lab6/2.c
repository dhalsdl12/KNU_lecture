//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int lotto_number()
{
	int a;
	while (1)
	{
		printf("Lotto 실행 회수 입력 (1~5회) : ");
		scanf("%d", &a);
		if (a <= 5 && a >= 1)
			break;
	}
	return a;
}
int check_same(int lotto[], int num, int lotto_num)
{
	int check = 0;
	
	for (int i = 0; i < num; i++)
	{
		if (lotto[i] == lotto_num)
			check = 1;
	}
	return check;
}
void random_num(int lotto[])
{
	int check = 0;
	for (int i = 0; i < 6; i++)
	{
		lotto[i] = rand() % 45 + 1;
		check = check_same(lotto, i, lotto[i]);
		if (check == 1)
			i--;
	}
}
void print_lotto(int lotto[])
{
	for (int i = 0; i < 6; i++)
	{
		printf("%4d", lotto[i]);
	}
	printf("\n");
}
int main()
{
	int num;
	int lotto[6] = { 0 };

	srand(time(NULL));

	num = lotto_number();
	for (int i = 0; i < num; i++)
	{
		random_num(lotto);
		print_lotto(lotto);
	}

	return 0;
}