//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	do
	{
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ����\n");
		printf("�ϳ��� �����Ͻÿ�\n");
		scanf("%d", &num);

		if (num == 1 || num == 2 || num == 3)
			break;
	} while (1);
	printf("���õ� �޴��� %d\n", num);

	return 0;
}