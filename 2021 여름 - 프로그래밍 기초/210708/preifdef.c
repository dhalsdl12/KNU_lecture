#include <stdio.h>

#define DEBUG
#define LIMIT 20

int main()
{
	long prod = 1;
	for (int i = 1; i <= LIMIT; i++)
	{
		prod *= i;

#ifdef DEBUG
		if (i % 5 == 0)
			printf("DEBUG : 1���� %d������ ���� %d�Դϴ�\n", i, prod);
#endif
	}
	printf("1���� %d������ ���� %d�Դϴ�\n", LIMIT, prod);

	return 0;
}