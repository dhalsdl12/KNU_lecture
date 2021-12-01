#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	float pi;
	char c1, c2;

	printf("원주율 : ");
	scanf("%f", &pi);
	printf("원주율 : %f\n", pi);

	printf("구분자를 공백으로 두 문자를 입력\n");
	getchar();
	scanf("%c %c", &c1, &c2);
	printf("%c %c\n", c1, c2);
}