#include <stdio.h>

#define myprint(x) printf(x);\
				puts("");

int main()
{
	myprint("매크로로 출력하기");
	printf("출력함수로 출력하기\n");

	return 0;
}