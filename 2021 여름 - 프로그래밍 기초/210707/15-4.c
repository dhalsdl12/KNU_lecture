#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	FILE* f;
	if
		(argc != 2)
	{
		printf("Usage: list filename\n");
		exit(1);
	}
	f = fopen
	(argv[1], "r");
	if (!f)
	{
		printf("File Open Error.\n");
		exit(1);
	}
	int ch, cnt = 0;
	printf
	("%4d: ", ++cnt);
	while ((ch = fgetc(f)) != EOF)
	{
		putchar(ch);

		if (ch == '\r' || ch == 0x0D)
			printf("\\r");
		if (ch == '\n')
			printf("%4d: ", ++cnt);
	}
	printf("\n");
	fclose(f);

	return 0;
}