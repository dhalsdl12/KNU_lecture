//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	int sum = 0;
	double avg;
	int min;
	int max;
	int cnt = 0;
	int check20 = 0;
	int check10_90 = 1;

	printf("���� �����͸� �Է��ϼ��� (���� : 99999)\n");
	scanf("%d", &num);

	if (num == 99999)
	{
		printf("���۰� ���ÿ� ����Ǿ����ϴ�.\n");
		exit(EXIT_FAILURE);
	}
	sum = num;
	min = num;
	max = num;
	cnt++;
	if (check20 == 0)
		if (num < 20)
			check20 = 1;
	if (check10_90 == 1)
		if (num < 10 || num > 90)
			check10_90 = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 99999)
			break;
		cnt++;
		sum += num;
		if (min > num)
			min = num;
		if (max < num)
			max = num;

		if (check20 == 0)
			if (num < 20)
				check20 = 1;
		if (check10_90 == 1)
			if (num < 10 || num > 90)
				check10_90 = 0;
	}
	avg = sum / (double)cnt;
	printf("�Է��� �������� ���� :\t\t\t%10d\n", cnt);
	printf("���� :\t\t\t\t\t%10d\n", sum);
	printf("��� :\t\t\t\t\t%10.2lf\n", avg);
	printf("�ּ� �� :\t\t\t\t%10d\n", min);
	printf("�ִ� �� :\t\t\t\t%10d\n", max);

	if(check20 == 1)
		printf("20���� �������� �ִ°�? :\t\t%10s\n", "true");
	else
		printf("20���� �������� �ִ°�? :\t\t%10s\n", "false");
	if(check10_90 == 1)
		printf("��� ���� 10���� 90������ �����ΰ� :\t%10s\n", "true");
	else
		printf("��� ���� 10���� 90������ �����ΰ� :\t%10s\n", "false");
	return 0;
}