//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void not2(int b, int c);
void result1(int a, int b);
void result2(int a, int b, int c);
void result3(int a, int b, int c);
int main()
{
	int a, b, c;
	printf("2차 방정식의 계수 a b c를 입력하시오 : ");
	scanf("%d %d %d", &a, &b, &c);

	if (a == 0)
		not2(b, c);
	else if (b * b - 4 * a * c == 0)
		result1(a, b);
	else if (b * b - 4 * a * c > 0)
		result2(a, b, c);
	else
		result3(a, b, c);
	return 0;
}

void not2(int b, int c)
{
	printf("|2차 방정식아님| 근 : %lf\n", -c / (double)b);
}
void result1(int a, int b)
{
	printf("근은 중근 %lf입니다.\n", -b / ((double)a * 2));
}
void result2(int a, int b, int c)
{
	printf("근은 %lf, %lf입니다.",
		(-b + sqrt(b * b - 4 * a * c)) / (double)(2 * a),
		(-b - sqrt(b * b - 4 * a * c)) / (double)(2 * a));
}
void result3(int a, int b, int c)
{
	printf("허근 %lf + %lfi, %lf - %lfi입니다.",
		-b / (double)(2 * a), sqrt(abs(b * b - 4 * a * c)) / (double)(2 * a),
		-b / (double)(2 * a), -sqrt(abs(b * b - 4 * a * c)) / (double)(2 * a));
}