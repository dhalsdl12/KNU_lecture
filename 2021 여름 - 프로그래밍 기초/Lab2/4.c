//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a, b, c;

	printf("�� ���� �Է� >> ");
	scanf("%d %d %d", &a, &b, &c);

	printf("max : %d", a > b ? (a > c ? a : c) : (b > c ? b : c));

	return 0;
}