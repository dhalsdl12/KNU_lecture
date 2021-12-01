#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int input;

	printf("정수 입력 : ");
	scanf("%d", &input);

	printf("입력값 : %d\n", input);
	printf("주소값: %u(10), %p(16)\n", (unsigned)&input, &input);
	printf("주소값: %d(10), %#x(16)\n", (int)&input, (unsigned)&input);
	printf("주소값 크기 : %d\n", sizeof(&input));

	printf("주소값: %u(10), %p(16)\n", &input, &input);
	printf("주소값: %d(10), %#x(16)\n", &input, &input);
}