#include <stdio.h>

typedef struct {
	double real;
	double img;
}complex;

void print(complex com)
{
	printf("%5.1f + %5.1fi\n", com.real, com.img);
}
complex pair1(complex com)
{
	com.img = -com.img;
	return com;
}
void pair2(complex* com)
{
	com->img = -com->img;
}

int main()
{
	complex com = { 3.4,4.8 };
	complex pcom;

	print(com);

	pcom = pair1(com);
	print(pcom);

	pair2(&pcom);
	print(pcom);

	return 0;
}