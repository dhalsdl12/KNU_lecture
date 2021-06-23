#include <stdio.h>

int main()
{
	const double RATE = 0.03;
	int deposit = 800000;

	printf("이자율: %f\n", RATE);
	printf("계좌 잔고: %d\n", deposit);
	printf("이자액: %f\n", deposit * RATE);

	return 0;
}