//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	printf("정수 입력: ");
	scanf("%d", &num);
	num = num & 255;
	num = num << 4;
	if (num < 178)
		printf("최하위 8비트를 왼쪽으로 4비트 이동한 값이 \
178보다 작습니다.\n");
	else if (num > 178)
		printf("최하위 8비트를 왼쪽으로 4비트 이동한 값이 \
178보다 큽니다.\n");
	else if (num == 178)
		printf("최하위 8비트를 왼쪽으로 4비트 이동한 값이 \
178과 같습니다.\n");

	return 0;
}