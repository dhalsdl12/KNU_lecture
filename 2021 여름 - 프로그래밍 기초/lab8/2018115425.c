//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE_SIZE 50 
#define NAME_SIZE 50 
#define ALBUM_SIZE 50

enum music_type { KPOP, POP, CLASSIC, OST };

typedef struct music {
	char title[TITLE_SIZE]; // 노래 제목
	char singer[NAME_SIZE]; // 가수
	char album[ALBUM_SIZE]; // 앨범 이름
	enum music_type genre; // 장르
} MUSIC;

void insert(MUSIC m[], int *cnt)
{
	(*cnt)++;
	printf("제목 : ");
	gets(m[*cnt].title);
	printf("가수 : ");
	gets(m[*cnt].singer);
	printf("앨범 : ");
	gets(m[*cnt].album);
	printf("장르(0: KPOP, 1: POP, 2: Classic, 3: OST) : ");
	scanf("%d", &m[*cnt].genre);
	while (m[*cnt].genre >= 4 || m[*cnt].genre < 0)
	{
		printf("해당 장르가 없습니다.\n");
		printf("장르를 다시 입력하세요.\n");
		printf("장르(0: KPOP, 1: POP, 2: Classic, 3: OST) : ");
		scanf("%d", &m[*cnt].genre);
	}
}
void print(MUSIC* m, int cnt)
{
	if (cnt == -1)
	{
		printf("입력된 테이블이 없습니다.\n");
		return;
	}
	for (int i = 0; i <= cnt; i++)
	{
		printf("----------------------\n");
		printf("제목 : %s\n", m[i].title);
		printf("가수 : %s\n", m[i].singer);
		printf("앨범 : %s\n", m[i].album);
		switch (m[i].genre) {
		case 0:
			printf("장르 : KPOP\n");
			break;
		case 1:
			printf("장르 : POP\n");
			break;
		case 2:
			printf("장르 : CLASSIC\n");
			break;
		case 3:
			printf("장르 : OST\n");
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
		printf("입력된 테이블이 없습니다.\n");
		return;
	}
	printf("제목 : ");
	gets(title);

	for (int i = 0; i <= cnt; i++)
	{
		if (strcmp(title, m[i].title) == 0)
		{
			check = 1;
			printf("----------------------\n");
			printf("제목 : %s\n", m[i].title);
			printf("가수 : %s\n", m[i].singer);
			printf("앨범 : %s\n", m[i].album);
			switch (m[i].genre) {
			case 0:
				printf("장르 : KPOP\n");
				break;
			case 1:
				printf("장르 : POP\n");
				break;
			case 2:
				printf("장르 : CLASSIC\n");
				break;
			case 3:
				printf("장르 : OST\n");
				break;
			}
		}
	}
	if (check == 0)
	{
		printf("찾는 음악이 테이블에 없습니다.\n");
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
		printf("1. 추가\n");
		printf("2. 출력\n");
		printf("3. 검색\n");
		printf("4. 종료\n");
		printf("====================\n");

		printf("메뉴를 선택하시오 : ");
		scanf("%d", &num);
		getchar();
		if (num == 4)
		{
			printf("프로그램 종료\n");
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
			printf("선택한 메뉴가 없습니다.\n");
			printf("다시 메뉴를 선택하세요\n");
			break;
		}
	}
}