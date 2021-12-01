#include	<stdio.h>
#include	<stdlib.h>
#include	<curses.h>
#include	<unistd.h>
#include	<string.h>
#include	<time.h>
#include	<pthread.h>
#include	<ctype.h>
#include	<signal.h>
#include	<sys/types.h>
#include	<sys/wait.h>

#define LINE 10
typedef struct w {
	char wordscr[30];
	int row;
	int col;
	int valid;
}www;
www hhh[10];
int rtword;
int intheart = 3, screenword = 0, rowline = 0, score = 0;
char inputtext[30];
char heart[2] = "3";
char* b = "                                                ";
char* l = "------------------------------------------";
char word[10][30];

void finish();
void wrongmenu();
void firstmenu();
void game(int num);
void strword(void* none);
void find(char* inputtext);
void secondmenu();
void textfile(int num);
int main() {
	char num;
	char menu[4][30] = { "Rain Typing Practice", "1. Game Start",
					   "2. Text File Info", "3. Exit" };
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	initscr();
	while (1)
	{
		clear();
		refresh();
		move(0, 0);
		addstr(l);
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				move(i + 1, 0);
				printw("        %s", menu[i]);
				move(i + 2, 0);
				addstr(l);
				continue;
			}
			move(i + 3, 0);
			printw("        %s", menu[i]);
		}
		move(8, 0);
		addstr(l);
		move(9, 0);
		addstr("        input : ");
		move(10, 0);
		addstr(l);
		move(9, 17);
		scanw("%c", &num);
		refresh();
		if (num == '1')
			firstmenu();
		else if (num == '2')
			secondmenu();
		else if (num == '3')
			finish();
		else
			wrongmenu();
	}
	endwin();
	return 0;
}
void wrongmenu()
{
	move(4, 0);
	addstr("        |      Wrong Menu      |          ");
	move(5, 0);
	addstr("        |   Menu num 1, 2, 3   |          ");
	move(6, 0);
	addstr("        |    Press '1, 2, 3'   |          ");
	move(9, 17);
	addstr("   ");
	move(9, 17);
	refresh();
	sleep(1);
}
void finish()
{
	clear();
	move(LINE / 2 - 2, 0);
	addstr("         ----------------------           ");
	move(LINE / 2 - 1, 0);
	addstr("        |     Exit Program     |          ");
	move(LINE / 2, 0);
	addstr("        |  Good Bye! 3seconds  |          ");
	move(LINE / 2 + 1, 0);
	addstr("         ----------------------           ");
	refresh();
	sleep(3);
	endwin();
	exit(0);
}
void secondmenu()
{
	char num;
	char menu[4][30] = { "The File List", "easy.txt","normal.txt","hard.txt" };

	clear();
	move(0, 0);
	addstr(l);
	move(8, 0);
	addstr(l);
	move(9, 0);
	addstr("        input : ");
	move(10, 0);
	addstr(l);
	move(11, 0);
	addstr("End Press 'q'               Back Press 'b'");
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				move(i + 1, 0);
				printw("        %s          ", menu[i]);
				move(i + 2, 0);
				addstr(l);
				continue;
			}
			move(i + 3, 0);
			printw("        %d. %s               ", i, menu[i]);
		}
		move(9, 17);
		scanw("%c", &num);
		refresh();
		if (num == '1' || num == '2' || num == '3')
			break;
		else if (num == 'b')
			return;
		else if (num == 'q')
			finish();
		else
			wrongmenu();
	}
	textfile(num - 48);
}
void textfile(int num)
{
	char menu[3][30] = { "easy.txt", "normal.txt", "hard.txt" };
	FILE* fp;
	int i = 0, count = 0, child_info = -1;
	int pid;
	char check[30];

	if ((pid = fork()) == -1)
		perror("fork");
	else if (pid == 0)
	{
		fp = fopen(menu[num - 1], "r");
		while (fgets(check, 30, fp) != NULL)
			count++;
		fclose(fp);
		fp = fopen(menu[num - 1], "r");
		move(0, 0);
		addstr(l);
		move(1, 0);
		printw("        %s voca             ", menu[num - 1]);
		move(2, 0);
		addstr(l);
		while (fgets(check, 30, fp) != NULL)
		{
			move(i + 3, 0);
			printw("        %s", check);
			i++;
		}
		move(i + 3, 0);
		addstr(l);
		refresh();
		getch();
		exit(0);
	}
	else
	{
		if (wait(&child_info) == -1)
			perror("wait");
		secondmenu();
	}
	return;
}
void firstmenu()
{
	char num;
	char menu[4][30] = { "The Level Of Difficulty", "Easy Mode",
					   "Normal Mode", "Hard Mode" };
	clear();
	move(0, 0);
	addstr(l);
	move(8, 0);
	addstr(l);
	move(9, 0);
	addstr("        input : ");
	move(10, 0);
	addstr(l);
	move(11, 0);
	addstr("End Press 'q'               Back Press 'b'");
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				move(i + 1, 0);
				printw("        %s          ", menu[i]);
				move(i + 2, 0);
				addstr(l);
				continue;
			}
			move(i + 3, 0);
			printw("        %d. %s               ", i, menu[i]);
		}
		move(9, 17);
		scanw("%c", &num);
		refresh();
		if (num == '1' || num == '2' || num == '3')
			break;
		else if (num == 'b')
			return;
		else if (num == 'q')
			finish();
		else
			wrongmenu();
	}
	refresh();
	game(num - 48);
}
void game(int num)
{
	char file[3][20] = { "easy.txt","normal.txt","hard.txt" };
	char check[30];
	int random, * check1;
	int cnt = 0, wordnum = 0, breakpoint = 0, timer = 3;
	screenword = 0;
	rowline = 0;
	score = 0;
	intheart = 3;
	strcpy(heart, "3");
	int pid;
	int child_info = -1;
	if ((pid = fork()) == -1)
		perror("fork");
	else if (pid == 0)
	{
		for (int i = 1; i < LINE; i++)
		{
			move(i, 0);
			addstr(b);
		}
		pthread_t t;
		clear();
		while (1)
		{
			if (timer == 0)
				break;
			move(LINE / 2 - 2, 0);
			addstr("         ----------------------           ");
			move(LINE / 2 - 1, 0);
			printw("        |    Wait %d seconds    |          ", timer);
			move(LINE / 2, 0);
			addstr("         ----------------------           ");
			refresh();
			sleep(1);
			timer--;
		}
		clear();
		move(0, 0);
		if (num == 1)
			addstr("---------------Easy Level-----------------");
		else if (num == 2)
			addstr("---------------Normal Level---------------");
		else
			addstr("---------------Hard Level-----------------");
		FILE* fp = fopen(file[num - 1], "r");
		while (fgets(check, 30, fp) != NULL)
			wordnum++;
		check1 = malloc(sizeof(int) * wordnum);
		for (int i = 0; i < wordnum; i++)
			check1[i] = 0;
		fclose(fp);
		move(0, 0);
		fp = fopen(file[num - 1], "r");
		srand(time(NULL));
		while (fgets(check, 30, fp) != NULL)
		{
			random = rand() % (wordnum);
			while (1)
			{
				if (check1[random] == 0)
				{
					check1[random] = 1;
					break;
				}
				else
					random = rand() % (wordnum);
			}
			if (random < 10)
			{
				int len = strlen(check);
				check[len - 1] = '\0';
				strcpy(word[random], check);
				cnt++;
			}
			if (cnt == 10)
				break;
		}
		fclose(fp);
		move(LINE, 0);
		addstr("------------------------------------------");
		move(LINE + 1, 0);
		addstr(" ENTER :                        HEART :   ");
		move(LINE + 1, 40);
		addstr(heart);
		move(LINE + 2, 0);
		addstr("------------------------------------------");
		move(LINE + 3, 0);
		addstr("                       finish Press 'quit'");
		move(LINE + 1, 9);
		refresh();

		pthread_create(&t, NULL, strword, NULL);
		while (1)
		{
			if (score == 10 || intheart == 0 || rowline == LINE)
				break;
			for (int i = 0; i < 30; )
			{
				char ch = getch();
				if (ch == '\n')
				{
					inputtext[i] = '\0';
					if (strcmp(inputtext, "quit") == 0)
					{
						intheart = 0;
						breakpoint = 1;
						for (int j = 0; j < 30; j++)
							inputtext[j] = '\0';
						refresh();
						break;
					}
					find(inputtext);
					for (int j = 0; j < 30; j++)
					{
						inputtext[j] = '\0';
					}
					move(LINE + 1, 0);
					addstr(" ENTER :                        HEART :   ");
					move(LINE + 1, 40);
					addstr(heart);
					move(LINE + 1, 9);
					refresh();
					break;
				}
				else if (ch == 127)
				{
					if (i == 0)
					{
						move(LINE + 1, 9);
						addstr("                     ");
						continue;
					}
					inputtext[i - 1] = '\0';
					i--;
					move(LINE + 1, 9);
					addstr("                     ");
					move(LINE + 1, 9);
					addstr(inputtext);
				}
				else
				{
					inputtext[i] = ch;
					i++;
					move(LINE + 1, 9);
					addstr(inputtext);
				}
				refresh();
			}
			if (breakpoint == 1)
				break;
		}
		pthread_join(t, NULL);
		refresh();
		exit(0);
	}
	else
	{
		if (wait(&child_info) == -1)
			perror("wait");
		firstmenu();
	}
}
void find(char* inputtext)
{
	for (int i = 0; i < screenword; i++)
	{
		if (strcmp(inputtext, hhh[i].wordscr) == 0)
		{
			score++;
			strcpy(hhh[i].wordscr, "");
			hhh[i].valid = 1;
			move(hhh[i].row, 0);
			addstr(b);
			move(LINE + 1, 40);
			refresh();
		}
	}
}
void strword(void* none)
{
	int time = 1;
	while (1)
	{
		if (intheart == 0 || score == 10)
			break;
		if (screenword != 0)
		{
			for (int i = rowline; i < screenword; i++)
				hhh[i].row++;
		}
		if (screenword < 10)
		{
			strcpy(hhh[screenword].wordscr, word[screenword]);
			hhh[screenword].row = 1;
			hhh[screenword].col = rand() % 35 + 1;
			hhh[screenword].valid = 0;
		}
		screenword++;
		if (screenword > 10)
			screenword--;
		for (int j = 0; j < screenword; j++)
		{
			if (hhh[j].row == LINE)
			{
				strcpy(hhh[j].wordscr, "");
				hhh[j].row--;
				if (hhh[j].valid == 0)
					intheart--;
				rowline++;
				if (intheart == 2)
					strcpy(heart, "2");
				else if (intheart == 1)
					strcpy(heart, "1");
				else if (intheart == 0)
					strcpy(heart, "0");

				move(LINE + 1, 40);
				addstr(heart);
				refresh();
			}
			if (j == 9)
			{
				if (hhh[9].row > 1)
				{
					move(hhh[9].row - 1, 0);
					addstr(b);
					refresh();
				}
			}
			move(hhh[j].row, 0);
			addstr(b);
			move(hhh[j].row, hhh[j].col);
			addstr(hhh[j].wordscr);
			refresh();
		}
		move(LINE + 1, 9);
		sleep(time);
		if (rowline == 10 || score == 10)
			break;
	}
	for (int i = 1; i < LINE; i++)
	{
		move(i, 0);
		addstr(b);
	}
	move(LINE / 2 - 1, 0);
	addstr("          -----Game Over------            ");
	move(LINE / 2, 0);
	printw("             Your Score %d                ", score);
	move(LINE / 2 + 1, 0);
	addstr("          ----Press'Enter'----            ");
	refresh();
	getch();
}
