#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int type, point;

	printf("1,2 : ");
	scanf("%d", &type);
	printf("score : ");
	scanf("%d", &point);

	if (type == 1)
	{
		if (point >= 70)
			printf("pass\n");
		else
			printf("fail\n");
	}
	else if (type == 2)
	{
		if (point >= 60)
			printf("pass\n");
		else
			printf("fail\n");
	}
}