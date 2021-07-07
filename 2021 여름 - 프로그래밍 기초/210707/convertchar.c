#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(void)
{
	FILE* f1, * f2;
	if ((f1 = fopen("convertchar.c", "r")) == NULL)
	{
		printf("cannot open this file\n");
		exit(1);
	}
	if ((f2 = fopen("my_convertchar.c", "w")) == NULL)
	{
		printf("cannot open this file\n");
		fclose(f1);
		exit(1);
	}
	char a;
	while ((a = getc(f1)) != EOF)
	{
		if (isalpha(a))
			if (islower(a))
				a = toupper(a);
			else if (isupper(a))
				a = tolower(a);
		putc(a, f2);
	}
	fclose(f1);
	fclose(f2);
	printf("File my_convertchar.c is created!!!\n");

	return 0;
}