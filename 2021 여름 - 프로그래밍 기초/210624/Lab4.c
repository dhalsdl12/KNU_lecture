#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	enum color {red, green, blue};
	int input;

	printf("0red 1green 2blue : ");
	scanf("%d", &input);

	switch (input) {
	case red:
		printf("red\n");
		break;
	case green:
		printf("green\n");
		break;
	case blue:
		printf("blue\n");
		break;
	default:
		printf("no color\n");
	}
}