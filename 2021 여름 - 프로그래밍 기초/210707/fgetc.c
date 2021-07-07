#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	char fname[] = "char.txt";
	FILE* f;

	f = fopen(fname, "w");

	puts("input(exit x) >> ");

	int ch;

	while ((ch = _getche()) != 'x')
	{
		fputc(ch, f);
	}
	fclose(f);
	puts("");

	f = fopen(fname, "r");

	while ((ch = fgetc(f)) != EOF)
	{
		_putch(ch);
	}
	fclose(f);
	puts("");
	
	return 0;
}