//2018115425 �ǿ���

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
		printf("���� 1���� �Է��ϼ��� : ");
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
	printf("���α׷��� �����մϴ�.\n");
}

int fac(int n)
{
	if (n == 1) 
		return 1; 

	return n * fac(n - 1);
}