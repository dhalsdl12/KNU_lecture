//2018115425 권오민

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

	//파일 이름을 받아옵니다.
	gets(file);

	//파일 이름이 256자보다 큰지 확인합니다.
	if (strlen(file) > 256)
	{
		printf("파일 이름이 256자보다 큽니다.\n");
		exit(1);
	}

	//256자 이내면 파일을 오픈합니다.
	FILE *fp = fopen(file, "r");

	//해당파일이 있는지 확인합니다.
	if (fp == NULL)
	{
		printf("해당 이름의 파일이 없습니다.\n");
		exit(1);
	}

	//해당파일이 비어있는지 확인합니다.
	if (feof(fp)) {
		printf("파일이 비어있습니다.\n");
		exit(1);
	}

	//자료의 개수, 선택할 숫자의 개수를 받습니다.
	fscanf(fp, "%d %d ", &cnt1, &cnt2);


	//자료의 개수에 맞춰 arr를 동적할당 합니다.
	arr = (int*)malloc(sizeof(int) * cnt1);
	//선택할 숫자의 개수에 맞춰 arr2를 동적할당 합니다. (출력할 자료)
	arr2 = (int*)malloc(sizeof(int) * cnt2);


	//자료의 개수에 맞게 for문을 돌려서 숫자를 하나씩 받아옵니다.
	for (int i = 0; i < cnt1; i++)
	{
		//자료 개수가 부족한지 파악합니다.
		if (feof(fp))
		{
			printf("자료의 개수가 부족합니다.\n");
			exit(1);
		}
		fscanf(fp, "%d ", &arr[i]);
	}

	//자료를 잘 받아왔는지 파악
	/*for (int i = 0; i < cnt1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/

	//qosrt를 이용하여서 정렬
	qsort(arr, cnt1, sizeof(int), compare);

	//정렬이 잘 되었는지 파악
	/*for (int i = 0; i < cnt1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/


	//비교할 숫자의 개수만큼 비교합니다
	//ex)숫자가 3개로 주어졌다면
	//0과 2, 1과3 등등을 비교하여서 가장 차이가 가장 작을때를 구해서
	//arr2에 넣어줍니다.
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

	//구한 값(arr2)를 출력합니다.
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
//오름차순 비교 함수
int compare(const void* a, const void* b)
{
	int n1 = *(int*)a;
	int n2 = *(int*)b;
	//a가 b보다 작을때
	if (n1 < n2)
		return -1; 
	//a가 b보다 클때
	if (n1 > n2) 
		return 1;  
	//a와 b가 같을떄
	return 0; 
}