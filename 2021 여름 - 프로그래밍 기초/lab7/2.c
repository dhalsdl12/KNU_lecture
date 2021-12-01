//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char str[])
{
	for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
	{
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}
int main()
{
	char str[100];
	char* ptoken = NULL;


	printf("한줄의 문장을 입력하세요. -> \n");
	gets(str);
	printf("\n");

	printf("입력한 각각의 단어를 반대로 출력합니다. ->\n");
	ptoken = strtok(str, " ");
	while (ptoken != NULL)
	{
		reverse(ptoken);
		printf("%s ", ptoken);
		ptoken = strtok(NULL, " ");
	}
	printf("\n");

	return 0;
}