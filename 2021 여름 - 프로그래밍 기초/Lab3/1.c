//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0;
	int n = 0;
	int grade = 0;

	double avg;

	printf("�����Է��� ��ġ���� ������ �Է��Ͻÿ�.\n");
	printf("������ �Է��Ͻÿ�\n");
	while (1)
	{
		scanf("%d", &grade);
		if (grade < 0)
			break;
		sum += grade;
		n++;
	}
	if (n == 0)
		printf("�Էµ� ������ �����ϴ�.\n");
	else
	{
		avg = (double)sum / n;
		printf("%d���� ����� %lf�Դϴ�.\n", n, avg);
	}

	return 0;
}