//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int x, y;
	printf("2���� ��ǥ x�� y���� �Է��Ͻÿ� (��: 3 5) ");
	scanf("%d %d", &x, &y);

	if (x > 0 && y > 0)
		printf("1��и�\n");
	else if (x < 0 && y > 0)
		printf("2��и�\n");
	else if (x < 0 && y < 0)
		printf("3��и�\n");
	else if (x > 0 && y < 0)
		printf("4��и�\n");

	return 0;
}