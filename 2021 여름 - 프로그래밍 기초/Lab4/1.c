//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("���� 1���� �Է��ϼ��� : \n");
	scanf("%d", &num);
	printf("\n");

	printf("5�� ����� ������ ��� Ȧ�� :\n");
	for (int i = 1; i <= num; i++)
	{
		if (i % 5 != 0)
		{
			if (i % 2 == 1)
				printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}