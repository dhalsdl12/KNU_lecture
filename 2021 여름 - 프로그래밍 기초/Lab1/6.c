//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define sq2(x) x*x
#define sq4(x) sq2(x)*sq2(x)

int main()
{
	float num;

	printf("x�� ���� �Ǽ��� �Է��Ͻÿ� : ");
	scanf("%f", &num);

	printf("x�� ������ %.1f�Դϴ�.\n", sq2(num));
	printf("x�� �������� %.1f�Դϴ�.\n", sq4(num));

	return 0;
}