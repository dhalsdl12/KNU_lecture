//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int re(float h, float w);
int main()
{
	float h, w;
	int result;

	printf("키, 몸무게 입력 >> ");
	scanf("%f %f", &h, &w);

	result = re(h, w);

	if (result)
		printf("정상 입니다\n");
	else
		printf("비만 입니다\n");

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