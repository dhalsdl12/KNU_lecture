#include <stdio.h>

#define KPOP 50000000
#define PI 3.14
#define PRT printf("메크로 상수 예제 종료\n")

int main()
{
	double radius = 2.83;

	printf("한국인구: %d명\n", KPOP);
	printf("원 면적: %f\n", radius * radius * PI);
	PRT;

	return 0;
}