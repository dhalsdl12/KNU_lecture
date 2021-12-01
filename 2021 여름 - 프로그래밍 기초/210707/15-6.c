#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number; //번호
	char name[40]; //이름
	int mid; //중간성적
	int final; //기말성적
	int quiz; //퀴즈성적
};
typedef struct personscore pscore;

void printhead()
{
	printf("_________________________________________________________\n");
	printf("%8s %15s %10s %8s %8s\n", "번호", "이름", "중간", "기말", "퀴즈");
	printf("---------------------------------------------------------\n");
}
int main()
{
	char fname[] = "score.bin";
	FILE* fp;
	fp = fopen(fname, "wb");

	if (fp == NULL )
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	char line[80];
	int cnt = 0;
	pscore score;

	printf("이름과 성적(중간, 기말, 퀴즈)을 입력하세요.\n");
	while (1)
	{
		fgets(line, 80, stdin);
		if (feof(stdin))
			break;
		//표준입력의 한줄을 구조체의 멤버 별로 자료를 입력
		//sscanf(line, "%s %d %d %d", score.name, &score.mid, & score.final, & score.quiz);
		sscanf_s(line, "%s %d %d %d", score.name, 40,
			&score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, fp);
	}
	printf("%s 파일 저장 완료\n", fname);
	fclose(fp);

	fp = fopen(fname, "rb");

	if (fp == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	printhead();
	while (1)
	{
		fread(&score, sizeof(pscore), 1, fp);
		if (feof(fp))
			break;
		fprintf(stdout, "%6d%18s%8d%8d%8d\n",
			score.number, score.name, score.mid, score.final, score.quiz);
	}
	fclose(fp);
	return 0;
}