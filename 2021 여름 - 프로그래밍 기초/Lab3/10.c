//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int mask = 0xffff;

	printf("���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &num);

	num = num & mask;
	printf("�Է°� %d�� ���� 16��Ʈ�� 8������ %#o, \
16������ %#x\n", num, num, num);

	return 0;
}