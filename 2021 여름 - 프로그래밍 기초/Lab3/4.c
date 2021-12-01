//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("정수1개 입력하세요 : \n");
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
	printf("입력한 수의 자릿수 %d이고\n", cnt);
	printf("각 자릿수의 합은 %d입니다.\n", sum);

	return 0;
}