#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* fname = "basic.txt";
	FILE* f;

	char name[30] = "∞≠πÃ¡§";
	int point = 99;

	f = fopen(fname, "w");
	if (f == NULL)
	{
		printf("file NULL\n");
		exit(1);
	}

	fprintf(f, "name: %s, score: %d\n", name, point);
	fclose(f);

	printf("name: %s, score: %d\n", name, point);
	printf("file open\n");

	return 0;
}