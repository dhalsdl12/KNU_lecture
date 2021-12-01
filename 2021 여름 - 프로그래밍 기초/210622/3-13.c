#include <stdio.h>

int main()
{
	enum DAY { sun, mon, tue, wed, thu, fri, sat };
	printf("sun : %d\n", sun);
	printf("wed : %d\n", wed);

	enum SHAPE {point, line, tri = 3, rect, octa = 8, circle};
	printf("line: %d, rect: %d, circle: %d\n", line, rect, circle);

	enum bool{ False, True };
	enum pl {c = 1972, cpp = 1983, java = 1995, csharp = 2000};
	printf("false: %d, cpp:%d, csharp: %d\n", False, cpp, csharp);

	return 0;
}