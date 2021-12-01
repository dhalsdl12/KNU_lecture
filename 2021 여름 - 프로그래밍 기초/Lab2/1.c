//2018115425 ±Ç¿À¹Î

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	printf("(01) %d\n", 3 && 1 || 0);
	printf("(02) %d\n", 5 - 1 != sizeof(int));
	printf("(03) %d\n", 3 == 4 ? 3 - 5 : 4 % 3);
	printf("(04) %d\n", 0 || !2);
	printf("(05) %d\n", ~~5 >> 2 << 3 << 1);
	printf("(06) %d\n", 3 / !0 == 0);
	printf("(07) %lf\n", (double)(int)3.4 + 5.5);
	printf("(08) %d\n", 1 | 3 & 11);
	printf("(09) %d\n", sizeof('a') + sizeof(char));
	int a, b;
	a = 1;
	printf("(10) a:%d\n", a);
	b = a = 3;
	printf("(10) a:%d b:%d\n", a, b);
	
	a = 16;
	printf("(11) %d\n", a);
	a << 2;
	printf("(11) %d\n", a);
	a <<= 2;
	printf("(11) %d\n", a);

	return 0;
}