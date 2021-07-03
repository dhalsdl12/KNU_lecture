#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "I am an engineer.";
	char* ptoken = NULL;

	ptoken = strtok(s, " ");
	while (ptoken != NULL)
	{
		printf("%s\n", ptoken);
		ptoken = strtok(NULL, " ");
	}

	return 0;
}