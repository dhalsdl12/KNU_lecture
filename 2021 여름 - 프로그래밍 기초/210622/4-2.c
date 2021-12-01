#include <stdio.h>

#define MESSAGE "프로그램 언어의 학습은 일번언어의 학습과\
같이 반복학습이 중요하다"
#define PI 3.141592
#define VOLUME(r) 4*PI*CUBE(r)/3
#define SQUARE(x) x*x
#define CUBE(x) SQUARE(x)*x
#define MULT(x, y) x*y

int main()
{
	double r = 2.32;;
	
	printf("r %.2lf - 구 체적 %.2lf\n", r, VOLUME(r));
	printf("실수 %.2f의 제곱은 %.2f입니다\n", 4.29, SQUARE(4.29));
	printf("실수 %.2f의 세 제곱은 %.2f입니다\n", 3.0, CUBE(3.00));
	printf("실수 %.2f와 %.2f의 곱은 %.2f입니다\n", 2.78, 3.62, 
		MULT(2.78, 3.62));
	puts(MESSAGE);
}