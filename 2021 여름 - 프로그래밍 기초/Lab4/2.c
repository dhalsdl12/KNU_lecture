//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[10];
	int min, max;
	int sum = 0;
	printf("정수 10개를 입력하세요 : \n");
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
	printf("누적합: %d\n", sum);
	printf("최댓값: %d\n", max);
	printf("최솟값: %d\n", min);

	return 0;
}