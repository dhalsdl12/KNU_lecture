//2018115425 �ǿ���

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


	printf("������ ������ �Է��ϼ���. -> \n");
	gets(str);
	printf("\n");

	printf("�Է��� ������ �ܾ �ݴ�� ����մϴ�. ->\n");
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