//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

int main()
{
	char input_string[21];
	char display_string[21];
	int len, cnt = 0;
	
	printf("광고문구를 입력하시오 : ");
	gets(input_string);
	len = strlen(input_string);

	Sleep(500);
	system("cls"); //화면 지우는 명령어
	
	while (1)
	{
		strncpy(display_string, input_string + 1, len+1);
		display_string[len-1] = input_string[0];
		printf("%s\n", display_string);
		Sleep(500);
		system("cls");
		strcpy(input_string, display_string);
		cnt++;

		if (cnt == 30)
			break;
	}
}