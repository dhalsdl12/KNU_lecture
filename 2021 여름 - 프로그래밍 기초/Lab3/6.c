//2018115425 권오민

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

	printf("정수 데이터를 입력하세요 (종료 : 99999)\n");
	scanf("%d", &num);

	if (num == 99999)
	{
		printf("시작과 동시에 종료되었습니다.\n");
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
	printf("입력한 데이터의 개수 :\t\t\t%10d\n", cnt);
	printf("총합 :\t\t\t\t\t%10d\n", sum);
	printf("평균 :\t\t\t\t\t%10.2lf\n", avg);
	printf("최소 값 :\t\t\t\t%10d\n", min);
	printf("최대 값 :\t\t\t\t%10d\n", max);

	if(check20 == 1)
		printf("20보다 작은수가 있는가? :\t\t%10s\n", "true");
	else
		printf("20보다 작은수가 있는가? :\t\t%10s\n", "false");
	if(check10_90 == 1)
		printf("모든 수가 10에서 90사이의 정수인가 :\t%10s\n", "true");
	else
		printf("모든 수가 10에서 90사이의 정수인가 :\t%10s\n", "false");
	return 0;
}