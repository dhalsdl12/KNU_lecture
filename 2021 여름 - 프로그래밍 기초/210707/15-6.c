#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct personscore
{
	int number; //��ȣ
	char name[40]; //�̸�
	int mid; //�߰�����
	int final; //�⸻����
	int quiz; //�����
};
typedef struct personscore pscore;

void printhead()
{
	printf("_________________________________________________________\n");
	printf("%8s %15s %10s %8s %8s\n", "��ȣ", "�̸�", "�߰�", "�⸻", "����");
	printf("---------------------------------------------------------\n");
}
int main()
{
	char fname[] = "score.bin";
	FILE* fp;
	fp = fopen(fname, "wb");

	if (fp == NULL )
	{
		printf("������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	char line[80];
	int cnt = 0;
	pscore score;

	printf("�̸��� ����(�߰�, �⸻, ����)�� �Է��ϼ���.\n");
	while (1)
	{
		fgets(line, 80, stdin);
		if (feof(stdin))
			break;
		//ǥ���Է��� ������ ����ü�� ��� ���� �ڷḦ �Է�
		//sscanf(line, "%s %d %d %d", score.name, &score.mid, & score.final, & score.quiz);
		sscanf_s(line, "%s %d %d %d", score.name, 40,
			&score.mid, &score.final, &score.quiz);
		score.number = ++cnt;
		fwrite(&score, sizeof(pscore), 1, fp);
	}
	printf("%s ���� ���� �Ϸ�\n", fname);
	fclose(fp);

	fp = fopen(fname, "rb");

	if (fp == NULL)
	{
		printf("������ ������ �ʽ��ϴ�.\n");
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