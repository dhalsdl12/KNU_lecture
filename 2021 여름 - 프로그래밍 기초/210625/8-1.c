#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int input;

	printf("���� �Է� : ");
	scanf("%d", &input);

	printf("�Է°� : %d\n", input);
	printf("�ּҰ�: %u(10), %p(16)\n", (unsigned)&input, &input);
	printf("�ּҰ�: %d(10), %#x(16)\n", (int)&input, (unsigned)&input);
	printf("�ּҰ� ũ�� : %d\n", sizeof(&input));

	printf("�ּҰ�: %u(10), %p(16)\n", &input, &input);
	printf("�ּҰ�: %d(10), %#x(16)\n", &input, &input);
}