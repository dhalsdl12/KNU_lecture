#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[] = "score.txt";
	FILE* f;
	char names[80];
	int cnt = 0;

	f = fopen(fname, "w");

	printf("name, mid, final : \n");
	while (1)
	{
		fgets(names, 80, stdin);
		if (feof(stdin))
			break;
		fprintf(f, "%d ", ++cnt);
		fputs(names, f);
		
	}
	fclose(f);

	return 0;
}