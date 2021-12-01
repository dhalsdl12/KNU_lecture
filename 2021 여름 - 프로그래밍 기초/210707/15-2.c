#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[] = "grade.txt";
	FILE* f;
	char name[30];
	int point1, point2, cnt = 0;

	f = fopen(fname, "w");
	if (f == NULL)
	{
		exit(1);
	}

	printf("name mid final : ");
	scanf("%s %d %d", name, &point1, &point2);
	fprintf(f, "%d %s %d %d\n", ++cnt, name, point1, point2);
	fclose(f);

	f = fopen(fname, "r");
	if (f == NULL)
	{
		exit(1);
	}
	fscanf(f, "%d %s %d %d\n", &cnt, name, &point1, &point2);
	fprintf(stdout, "\n%6s %16s %10s %8s\n", "번호", "이름", "중간",
		"기말");
	fprintf(stdout, "%5d %18s %8d %8d\n", cnt, name, point1, point2);

	return 0;
}