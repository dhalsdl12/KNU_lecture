#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	double x, y, reuslt;
	int op;

	printf("�Ǽ� �Է� 2��: ");
	scanf("%lf %lf", &x, &y);
	printf("1+ 2- 3* 4/ : ");
	scanf("%d", &op);

	switch (op) {
	case 1:
		printf("%.2f + %.2f = %.2f\n", x, y, x + y);
		break;
	case 2:
		printf("%.2f + %.2f = %.2f\n", x, y, x - y);
		break;
	case 3:
		printf("%.2f + %.2f = %.2f\n", x, y, x * y);
		break;
	case 4:
		printf("%.2f + %.2f = %.2f\n", x, y, x / y);
		break;
	default:
		printf("��ȣ �߸� ������\n");
		break;
	}
}