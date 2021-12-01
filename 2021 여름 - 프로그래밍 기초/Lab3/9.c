//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("정수 입력 : ");
	scanf("%d", &n);

	int mask1 = 0xf000;
	printf("(1)0으로 지정한 수 : %d\n", n & ~mask1);
	
	int mask2 = 0;
	mask2 |= 1 << (13 - 1);
	mask2 |= 1 << (14 - 1);
	mask2 |= 1 << (15 - 1);
	mask2 |= 1 << (16 - 1);
	printf("(2)1으로 지정한 수 : %d\n", n | mask2);

	int mask3 = 0;
	for (int i = 13; i <= 16; i++)
	{
		mask3 |= 1 << (i - 1);
	}
	printf("(3)0은 1로 1은 0으로 : %d\n", n ^ mask3);
}