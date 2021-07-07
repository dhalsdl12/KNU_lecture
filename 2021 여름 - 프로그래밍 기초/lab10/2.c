//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int year;
	int month;
	int day;
}Date;
typedef struct {
	Date date;
	int account_num;
	char name[30];
	int balance;
} ACCOUNT;


void save(char bank[], ACCOUNT a[])
{
	FILE* fp;
	fp = fopen(bank, "r");

	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%d %d %d %d %s %d",
			&a[i].date.year, &a[i].date.month, &a[i].date.day,
			&a[i].account_num, &a[i].name, &a[i].balance);
	}
	fclose(fp);
}
void print(ACCOUNT a[])
{
	printf("-----------------------------------------------------\n");
	printf("개설년  월   일   계좌번호      예금주      통장잔액\n");
	printf("-----------------------------------------------------\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%5d %4d %4d %8d %15s %10d\n",
			a[i].date.year, a[i].date.month, a[i].date.day,
			a[i].account_num, a[i].name, a[i].balance);
	}
	printf("-----------------------------------------------------\n");
}
void maxaccount(char output[], ACCOUNT a[])
{
	ACCOUNT Max = a[0];
	FILE* fp;
	fp = fopen(output, "w");
	for (int i = 1; i < 5; i++)
	{
		if (Max.balance < a[i].balance)
			Max = a[i];
	}
	printf("\n[최대 통장 잔액 고객 정보]\n");
	printf("-----------------------------------------------------\n");
	printf("개설년  월   일   계좌번호      예금주      통장잔액\n");
	printf("-----------------------------------------------------\n");

	printf("%5d %4d %4d %8d %15s %10d\n",
		Max.date.year, Max.date.month, Max.date.day,
		Max.account_num, Max.name, Max.balance);
	printf("-----------------------------------------------------\n");
	
	fprintf(fp, "%5d %4d %4d %8d %15s %10d\n",
		Max.date.year, Max.date.month, Max.date.day,
		Max.account_num, Max.name, Max.balance);

	fclose(fp);
}
int main()
{
	char bank[] = "input.txt";
	char output[] = "output.txt";
	ACCOUNT account[5];

	save(bank, account);
	print(account);
	maxaccount(output, account);

	return 0;
}