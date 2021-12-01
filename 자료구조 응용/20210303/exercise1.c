#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
int num_cnt = 0;

void selection_sort();
int read_data(char infile[], int list[]);

void main(int argc, char** argv)
{
	int i = 0;

	/*FILE* fp = fopen(argv[1], "r");
	while (1)
	{
		fscanf(fp, "%d", &list[i++]);
		if (feof(fp))
		{
			num_cnt = i;
			break;
		}
	}*/
	if (argc != 2) {
		fprintf(stderr, " E usage : [program] [file name]\n");
		exit(EXIT_FAILURE);
	}

	num_cnt = read_data(argv[1], list);

	if (argc != 2)
	{
		fprintf(stderr, " E usage : [program] [file name]\n");
		exit(EXIT_FAILURE);
	}

	selection_sort();

	for (int i = 0; i < num_cnt; i++)
	{
		printf("%d ", list[i]);
	}
}
void selection_sort()
{
	int min, tmp;
	for (int i = 0; i < num_cnt-1; i++)
	{
		min = i;
		for (int j = i + 1; j < num_cnt; j++)
		{
			if (list[j] < list[min])
			{
				tmp = list[min];
				list[min] = list[j];
				list[j] = tmp;
			}
		}
	}
}
int read_data(char infile[], int list[]) {
	FILE* fp;
	int size = 0;

	// 1. open file
	if (!(fp = fopen(infile, "r"))) {
		fprintf(stderr, "failed to open file\n");
		exit(EXIT_FAILURE);
	}

	// 2. read input data
	while (!feof(fp)) {
		fscanf(fp, "%d ", &(list[size]));
		size++;
	}
	fclose(fp);

	return size;
}