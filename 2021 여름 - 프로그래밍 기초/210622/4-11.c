#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	float pi;
	char c1, c2;

	printf("������ : ");
	scanf("%f", &pi);
	printf("������ : %f\n", pi);

	printf("�����ڸ� �������� �� ���ڸ� �Է�\n");
	getchar();
	scanf("%c %c", &c1, &c2);
	printf("%c %c\n", c1, c2);
}