//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	printf("���� 1���� �Է��Ͻÿ� : \n");
	scanf("%d", &num);
	printf("\n\n");

	switch (num) {
	case 1:
		printf("%d�� �θ����ڴ� I�Դϴ�.\n", num);
		break;
	case 2:
		printf("%d�� �θ����ڴ� II�Դϴ�.\n", num);
		break;
	case 3:
		printf("%d�� �θ����ڴ� III�Դϴ�.\n", num);
		break;
	case 4:
		printf("%d�� �θ����ڴ� IV�Դϴ�.\n", num);
		break;
	case 5:
		printf("%d�� �θ����ڴ� V�Դϴ�.\n", num);
		break;
	case 6:
		printf("%d�� �θ����ڴ� VI�Դϴ�.\n", num);
		break;
	case 7:
		printf("%d�� �θ����ڴ� VII�Դϴ�.\n", num);
		break;
	case 8:
		printf("%d�� �θ����ڴ� VIII�Դϴ�.\n", num);
		break;
	case 9:
		printf("%d�� �θ����ڴ� IX�Դϴ�.\n", num);
		break;
	case 10:
		printf("%d�� �θ����ڴ� X�Դϴ�.\n", num);
		break;
	default:
		printf("1~10�� ���ڰ� �ƴմϴ�.\n");
	}

	return 0;
}