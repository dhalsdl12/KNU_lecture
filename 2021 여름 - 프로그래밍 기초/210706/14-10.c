#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void mu(double* result, const double* a, const double* b)
{
	*result = *a * *b;
}
void d(double* result, double* a, double* b)
{
	*result = *a/ *b;
	++* a;
	(*b)++;
}
int main()
{
	double m = 0, n = 0, mult = 0, dev = 0;

	printf("두 실수 입력 ; ");
	scanf("%lf %lf", &m, &n);

	mu(&mult, &m, &n);
	d(&dev, &m, &n);

	printf("milt : %.2f, dev : %.2f\n", mult, dev);
	printf("m %.2f, n %.2f", m, n);
	
	return 0;
}