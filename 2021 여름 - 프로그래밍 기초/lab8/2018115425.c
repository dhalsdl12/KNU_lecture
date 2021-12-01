//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 50 
#define NAME_SIZE 50 
#define ALBUM_SIZE 50

enum music_type { KPOP, POP, CLASSIC, OST };

typedef struct music {
	char title[TITLE_SIZE]; // �뷡 ����
	char singer[NAME_SIZE]; // ����
	char album[ALBUM_SIZE]; // �ٹ� �̸�
	enum music_type genre; // �帣
} MUSIC;

void insert(MUSIC m[], int *cnt)
{
	(*cnt)++;
	printf("���� : ");
	gets(m[*cnt].title);
	printf("���� : ");
	gets(m[*cnt].singer);
	printf("�ٹ� : ");
	gets(m[*cnt].album);
	printf("�帣(0: KPOP, 1: POP, 2: Classic, 3: OST) : ");
	scanf("%d", &m[*cnt].genre);
	while (m[*cnt].genre >= 4 || m[*cnt].genre < 0)
	{
		printf("�ش� �帣�� �����ϴ�.\n");
		printf("�帣�� �ٽ� �Է��ϼ���.\n");
		printf("�帣(0: KPOP, 1: POP, 2: Classic, 3: OST) : ");
		scanf("%d", &m[*cnt].genre);
	}
}
void print(MUSIC* m, int cnt)
{
	if (cnt == -1)
	{
		printf("�Էµ� ���̺��� �����ϴ�.\n");
		return;
	}
	for (int i = 0; i <= cnt; i++)
	{
		printf("----------------------\n");
		printf("���� : %s\n", m[i].title);
		printf("���� : %s\n", m[i].singer);
		printf("�ٹ� : %s\n", m[i].album);
		switch (m[i].genre) {
		case 0:
			printf("�帣 : KPOP\n");
			break;
		case 1:
			printf("�帣 : POP\n");
			break;
		case 2:
			printf("�帣 : CLASSIC\n");
			break;
		case 3:
			printf("�帣 : OST\n");
			break;
		}
	}
}
void search(MUSIC* m, int cnt)
{
	char title[50];
	int check = 0;

	if (cnt == -1)
	{
		printf("�Էµ� ���̺��� �����ϴ�.\n");
		return;
	}
	printf("���� : ");
	gets(title);

	for (int i = 0; i <= cnt; i++)
	{
		if (strcmp(title, m[i].title) == 0)
		{
			check = 1;
			printf("----------------------\n");
			printf("���� : %s\n", m[i].title);
			printf("���� : %s\n", m[i].singer);
			printf("�ٹ� : %s\n", m[i].album);
			switch (m[i].genre) {
			case 0:
				printf("�帣 : KPOP\n");
				break;
			case 1:
				printf("�帣 : POP\n");
				break;
			case 2:
				printf("�帣 : CLASSIC\n");
				break;
			case 3:
				printf("�帣 : OST\n");
				break;
			}
		}
	}
	if (check == 0)
	{
		printf("ã�� ������ ���̺� �����ϴ�.\n");
	}
}
int main()
{
	MUSIC m[10];
	int cnt = -1;
	int num;

	while (1)
	{
		printf("====================\n");
		printf("1. �߰�\n");
		printf("2. ���\n");
		printf("3. �˻�\n");
		printf("4. ����\n");
		printf("====================\n");

		printf("�޴��� �����Ͻÿ� : ");
		scanf("%d", &num);
		getchar();
		if (num == 4)
		{
			printf("���α׷� ����\n");
			break;
		}
		switch (num) {
		case 1:
			insert(m, &cnt);
			break;
		case 2:
			print(m, cnt);
			break;
		case 3:
			search(m, cnt);
			break;
		default:
			printf("������ �޴��� �����ϴ�.\n");
			printf("�ٽ� �޴��� �����ϼ���\n");
			break;
		}
	}
}