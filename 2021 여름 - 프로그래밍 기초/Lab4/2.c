//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10];
	int min, max;
	int sum = 0;
	printf("���� 10���� �Է��ϼ��� : \n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (i == 0)
		{
			min = arr[i];
			max = arr[i];
		}
		sum += arr[i];
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	printf("������: %d\n", sum);
	printf("�ִ�: %d\n", max);
	printf("�ּڰ�: %d\n", min);

	return 0;
}