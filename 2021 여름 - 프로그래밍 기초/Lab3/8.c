//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("���� �Է�: ");
	scanf("%d", &num);
	num = num & 255;
	num = num << 4;
	if (num < 178)
		printf("������ 8��Ʈ�� �������� 4��Ʈ �̵��� ���� \
178���� �۽��ϴ�.\n");
	else if (num > 178)
		printf("������ 8��Ʈ�� �������� 4��Ʈ �̵��� ���� \
178���� Ů�ϴ�.\n");
	else if (num == 178)
		printf("������ 8��Ʈ�� �������� 4��Ʈ �̵��� ���� \
178�� �����ϴ�.\n");

	return 0;
}