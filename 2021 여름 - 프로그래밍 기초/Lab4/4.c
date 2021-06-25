//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("정수 1개를 입력하시오 : \n");
	scanf("%d", &num);
	printf("\n\n");

	switch (num) {
	case 1:
		printf("%d의 로마숫자는 I입니다.\n", num);
		break;
	case 2:
		printf("%d의 로마숫자는 II입니다.\n", num);
		break;
	case 3:
		printf("%d의 로마숫자는 III입니다.\n", num);
		break;
	case 4:
		printf("%d의 로마숫자는 IV입니다.\n", num);
		break;
	case 5:
		printf("%d의 로마숫자는 V입니다.\n", num);
		break;
	case 6:
		printf("%d의 로마숫자는 VI입니다.\n", num);
		break;
	case 7:
		printf("%d의 로마숫자는 VII입니다.\n", num);
		break;
	case 8:
		printf("%d의 로마숫자는 VIII입니다.\n", num);
		break;
	case 9:
		printf("%d의 로마숫자는 IX입니다.\n", num);
		break;
	case 10:
		printf("%d의 로마숫자는 X입니다.\n", num);
		break;
	default:
		printf("1~10의 숫자가 아닙니다.\n");
	}

	return 0;
}