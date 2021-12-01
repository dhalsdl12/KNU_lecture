//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b);
int main()
{
	char file[1000];
	int cnt1, cnt2;
	int* arr;
	int* arr2;
	int min = INT_MAX;

	//���� �̸��� �޾ƿɴϴ�.
	gets(file);

	//���� �̸��� 256�ں��� ū�� Ȯ���մϴ�.
	if (strlen(file) > 256)
	{
		printf("���� �̸��� 256�ں��� Ů�ϴ�.\n");
		exit(1);
	}

	//256�� �̳��� ������ �����մϴ�.
	FILE *fp = fopen(file, "r");

	//�ش������� �ִ��� Ȯ���մϴ�.
	if (fp == NULL)
	{
		printf("�ش� �̸��� ������ �����ϴ�.\n");
		exit(1);
	}

	//�ش������� ����ִ��� Ȯ���մϴ�.
	if (feof(fp)) {
		printf("������ ����ֽ��ϴ�.\n");
		exit(1);
	}

	//�ڷ��� ����, ������ ������ ������ �޽��ϴ�.
	fscanf(fp, "%d %d ", &cnt1, &cnt2);


	//�ڷ��� ������ ���� arr�� �����Ҵ� �մϴ�.
	arr = (int*)malloc(sizeof(int) * cnt1);
	//������ ������ ������ ���� arr2�� �����Ҵ� �մϴ�. (����� �ڷ�)
	arr2 = (int*)malloc(sizeof(int) * cnt2);


	//�ڷ��� ������ �°� for���� ������ ���ڸ� �ϳ��� �޾ƿɴϴ�.
	for (int i = 0; i < cnt1; i++)
	{
		//�ڷ� ������ �������� �ľ��մϴ�.
		if (feof(fp))
		{
			printf("�ڷ��� ������ �����մϴ�.\n");
			exit(1);
		}
		fscanf(fp, "%d ", &arr[i]);
	}

	//�ڷḦ �� �޾ƿԴ��� �ľ�
	/*for (int i = 0; i < cnt1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	//qosrt�� �̿��Ͽ��� ����
	qsort(arr, cnt1, sizeof(int), compare);

	//������ �� �Ǿ����� �ľ�
	/*for (int i = 0; i < cnt1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/


	//���� ������ ������ŭ ���մϴ�
	//ex)���ڰ� 3���� �־����ٸ�
	//0�� 2, 1��3 ����� ���Ͽ��� ���� ���̰� ���� �������� ���ؼ�
	//arr2�� �־��ݴϴ�.
	for (int i = 0; i < cnt1 - cnt2 + 1; i++)
	{
		if (arr[i + cnt2 - 1] - arr[i] < min)
		{
			for (int j = 0; j < cnt2; j++)
			{
				arr2[j] = arr[j + i];
			}
			min = arr[i + cnt2 - 1] - arr[i];
		}
	}

	//���� ��(arr2)�� ����մϴ�.
	for (int i = 0; i < cnt2; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	free(arr);
	free(arr2);
	fclose(fp);

	return 0;
}
//�������� �� �Լ�
int compare(const void* a, const void* b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	//a�� b���� ������
	if (n1 < n2)
		return -1; 
	//a�� b���� Ŭ��
	if (n1 > n2) 
		return 1;  
	//a�� b�� ������
	return 0; 
}