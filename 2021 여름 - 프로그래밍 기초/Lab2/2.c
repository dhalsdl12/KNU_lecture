//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int num;
	printf("���� õ�� ������ �ϳ��� ���� �Է� >> ");

	scanf("%d", &num);

	printf("�Է��� �� %d�� ", num);
	if (num >= 10000)
	{
		printf("%d�� ", num / 10000);
		num %= 10000;
	}
	if (num >= 1000)
	{
		printf("%dõ ", num / 1000);
		num %= 1000;
	}
	if (num >= 100)
	{
		printf("%d�� ", num / 100);
		num %= 100;
	}
	if (num >= 10)
	{
		printf("%d�� ", num/10);
		num %= 10;
	}
	if (num >= 1)
	{
		printf("%d", num);
	}
	printf("�Դϴ�.\n");

	return 0;
}