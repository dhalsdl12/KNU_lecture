#include <stdio.h>

#define MESSAGE "���α׷� ����� �н��� �Ϲ������ �н���\
���� �ݺ��н��� �߿��ϴ�"
#define PI 3.141592
#define VOLUME(r) 4*PI*CUBE(r)/3
#define SQUARE(x) x*x
#define CUBE(x) SQUARE(x)*x
#define MULT(x, y) x*y

int main()
{
	double r = 2.32;;
	
	printf("r %.2lf - �� ü�� %.2lf\n", r, VOLUME(r));
	printf("�Ǽ� %.2f�� ������ %.2f�Դϴ�\n", 4.29, SQUARE(4.29));
	printf("�Ǽ� %.2f�� �� ������ %.2f�Դϴ�\n", 3.0, CUBE(3.00));
	printf("�Ǽ� %.2f�� %.2f�� ���� %.2f�Դϴ�\n", 2.78, 3.62, 
		MULT(2.78, 3.62));
	puts(MESSAGE);
}