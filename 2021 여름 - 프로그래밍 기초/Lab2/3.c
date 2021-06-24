//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define pi 3.14
#define V(x) x*x*x*pi*4/3
#define S(x) x*x*pi*4

int main()
{
	double r;
	
	printf("반지름 입력 >> ");
	scanf("%lf", &r);

	printf("구 체적 : %lf\n", V(r));
	printf("구 표면적 : %lf\n", S(r));

	return 0;
}