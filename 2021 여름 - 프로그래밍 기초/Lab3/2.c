//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	do
	{
		printf("1. 파일\n");
		printf("2. 편집\n");
		printf("3. 보기\n");
		printf("하나를 선택하시오\n");
		scanf("%d", &num);

		if (num == 1 || num == 2 || num == 3)
			break;
	} while (1);
	printf("선택된 메뉴는 %d\n", num);

	return 0;
}