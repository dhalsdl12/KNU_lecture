//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int num;
	char name[10];
	float mid;
	float final;
	float total;
	double average;
}SCORE;

int main()
{
	char in[] = "input.txt";
	char out[] = "output.txt";
	int num;
	FILE* fp;
	FILE* fpp;
	int n;

	SCORE* score;

	fp = fopen(in, "r");
	fpp = fopen(out, "w");
	if (fp == NULL || fpp == NULL)
	{
		printf("fp is null\n");
		exit(EXIT_FAILURE);
	}

	fscanf(fp, "%d", &num);
	score = (SCORE*)malloc(sizeof(SCORE) * num);

	printf("순서    이름   중간  기말  총점  평균\n");
	printf("---------------------------------------\n");
	fprintf(fpp, "순서    이름   중간  기말  총점  평균\n");
	fprintf(fpp, "---------------------------------------\n");
	for (int i = 0; i < num; i++)
	{
		fscanf(fp, "%d %s %f %f", &score[i].num, score[i].name,
			&score[i].mid, &score[i].final);
		score[i].total = score[i].mid + score[i].final;
		score[i].average = score[i].total / 2;
		
		printf("%2d %10s %5.1f %5.1f %5.1f %5.1f\n", score[i].num, 
			score[i].name, score[i].mid, score[i].final,
			score[i].total, score[i].average);
		fprintf(fpp, "%2d %10s %5.1f %5.1f %5.1f %5.1f\n", 
			score[i].num, score[i].name, score[i].mid, score[i].final,
			score[i].total, score[i].average);
	}

	fclose(fp);
	fclose(fpp);
	free(score);

	return 0;
}