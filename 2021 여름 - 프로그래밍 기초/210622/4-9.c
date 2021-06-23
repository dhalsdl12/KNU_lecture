#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int year = 0;
	printf("year : ");
	scanf("%d", &year);
	printf("year : %d\n\n", year);

	int month, day;
	printf("birth : ");
	scanf("%d - %d - %d", &year, &month, &day);
	printf("birthday : %d-%d-%d\n", year, month, day);

	return 0;
}