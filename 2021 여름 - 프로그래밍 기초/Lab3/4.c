//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("����1�� �Է��ϼ��� : \n");
	scanf("%d", &num);

	int cnt = 0;
	int sum = 0;
	while (1)
	{
		if (num / 10 != 0)
		{
			sum += num % 10;
			num = num / 10;
			cnt++;
		}
		else
		{
			sum += num;
			cnt++;
			break;
		}
	}
	printf("\n");
	printf("�Է��� ���� �ڸ��� %d�̰�\n", cnt);
	printf("�� �ڸ����� ���� %d�Դϴ�.\n", sum);

	return 0;
}