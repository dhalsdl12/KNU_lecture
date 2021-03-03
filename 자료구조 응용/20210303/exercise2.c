#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

int list[MAX_SIZE];
int num_cnt = 0;

void selection_sort();
int read_data(char infile[], int list[]);
int binsearch(int searchnum, int left, int right);

void main(int argc, char** argv)
{
	int i = 0;
	int result = 0;
	int searchnum = 0;

	if (argc != 2)
	{
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

	searchnum = list[0];
	result = binsearch(searchnum, 1, num_cnt);
	printf("%d", result - 1);
}
int binsearch(int searchnum, int left, int right)
{
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (searchnum < list[mid])
			right = mid - 1;
		else if (searchnum > list[mid])
			left = mid + 1;
		else if (searchnum == list[mid])
			return mid;
		mid = (left + right) / 2;
	}
	return -1;
}
void selection_sort()
{
	int min, tmp;
	for (int i = 1; i < num_cnt - 1; i++)
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

	if (!(fp = fopen(infile, "r")))
	{
		fprintf(stderr, "failed to open file\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d ", &(list[size]));
		size++;
	}
	fclose(fp);

	return size;
}