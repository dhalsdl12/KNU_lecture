#include <stdio.h>

int main()
{
	const double RATE = 0.03;
	int deposit = 800000;

	printf("������: %f\n", RATE);
	printf("���� �ܰ�: %d\n", deposit);
	printf("���ھ�: %f\n", deposit * RATE);

	return 0;
}