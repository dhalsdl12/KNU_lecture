//author: 2018115425 권오민
//datetime: 2021-09-30 11:53

#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <stdlib.h>

int main()
{
	char pw[1000] = "s123";
	char password[1000];
	char newpw[1000];
	char rnp[1000];
	struct termios info;

	printf("Changing password for you.\n");
	printf("Current password: ");
	system("stty -echo");
	//echo off
	gets(password);
	printf("\n");
	if (strcmp(pw, password) != 0)
	{
		//현재 비밀번호와 입력한 비밀번호가 다르다면 오류 출력
		printf("passwd: Authenication error\n");
		printf("passwd: password unchanged\n");
		info.c_lflag |= ECHO;
		printf("\n현재password: %s\n", pw);
		system("stty echo");
		exit(0);
	}

	printf("New password: ");
	gets(newpw);
	printf("\n");
	printf("Retype new password: ");
	gets(rnp);
	printf("\n");
	if (strcmp(newpw, rnp) == 0)
	{
		//새로운 비밀번호와 retype비밀번호가 같다면
		printf("password updated successfully\n");
		strcpy(pw, newpw);
	}
	else
	{
		//새로운 비밀번호와 retype비밀번호가 다르다면
		printf("Retype new password가 일치하지 않습니다\n");
		printf("passwd: password unchanged\n");
	}

	printf("\n현재password: %s\n", pw);
	system("stty echo");
	//마지막에 echo on;
	return 0;
}