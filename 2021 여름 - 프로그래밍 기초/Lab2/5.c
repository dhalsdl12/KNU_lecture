//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int re(float h, float w);
int main()
{
	float h, w;
	int result;

	printf("Ű, ������ �Է� >> ");
	scanf("%f %f", &h, &w);

	result = re(h, w);

	if (result)
		printf("���� �Դϴ�\n");
	else
		printf("�� �Դϴ�\n");

	return 0;
}

int re(float h, float w)
{
	float result;
	result = (h - 100) * 0.9;

	if (w <= result)
		return 1;
	else
		return 0;
}