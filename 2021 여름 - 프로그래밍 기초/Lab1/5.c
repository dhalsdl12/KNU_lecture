//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("10���� ���� �Է� >> ");
	scanf("%d", &num);
	printf("10����: %d, 8����: %#o, 16��: %#x\n\n", num, num, num);

	printf("8���� ���� �Է� (��: 77)>> ");
	scanf("%o", &num);
	printf("10����: %d, 8����: %#o, 16��: %#x\n\n", num, num, num);

	printf("16���� ���� �Է� (��: 1a0)>> ");
	scanf("%x", &num);
	printf("10����: %d, 8����: %#o, 16��: %#x\n\n", num, num, num);

	printf("8���� ���� �Է� (��: 077)>> ");
	scanf("%o", &num);
	printf("10����: %d, 8����: %o, 16��: %x\n\n", num, num, num);

	printf("16���� ���� �Է� (��: 0x1a0)>> ");
	scanf("%x", &num);
	printf("10����: %d, 8����: %o, 16��: %x\n\n", num, num, num);

	return 0;
}