#include <stdio.h>
#include <stdarg.h>

double avg(int cnt, ...)
{
	va_list argp;

	va_start(argp, cnt);

	double total = 0;
	for (int i = 0; i < cnt; i++)
		total += va_arg(argp, double);

	va_end(argp);

	return total;
}
int main()
{
	printf("ЦђБе %.2f\n", avg(5, 1.2, 2.1, 3.6, 4.3, 5.8)/5);
	return 0;
}