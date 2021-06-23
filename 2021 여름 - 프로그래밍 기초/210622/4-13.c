#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char a = '\0';
	puts("문자 하나 입력: ");
	a = getchar();
	putchar(a);
	putchar('\n');

	return 0;
}