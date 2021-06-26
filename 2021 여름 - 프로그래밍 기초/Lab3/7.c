//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int fac(int n);
int main()
{
	int num;
	int fa;
	int sum = 0;
	while(1)
	{
		printf("정수 1개를 입력하세요 : ");
		scanf("%d", &num);
		if (num < 0)
			break;
		for (int i = 1; i <= num; i++)
		{
			fa = fac(i);
			printf("%d! = %d\n", i, fa);
			sum += fa;
		}
		printf("--------------\n");
		printf("total = %d\n", sum);
	}
	printf("프로그램을 종료합니다.\n");
}

int fac(int n)
{
	if (n == 1) 
		return 1; 

	return n * fac(n - 1);
}