//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define pi 3.14
#define V(x) x*x*x*pi*4/3
#define S(x) x*x*pi*4

int main()
{
	double r;
	
	printf("������ �Է� >> ");
	scanf("%lf", &r);

	printf("�� ü�� : %lf\n", V(r));
	printf("�� ǥ���� : %lf\n", S(r));

	return 0;
}