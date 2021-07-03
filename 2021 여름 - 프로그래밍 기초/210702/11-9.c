#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char dest[80] = "java";
	char source[80] = "C is a language";

	printf("%s\n", strcpy(dest, source));
	printf("%s\n", dest);

	printf("%s\n", strncpy(dest, "C#", 2));
	printf("%s\n", strncpy(dest, "C#", 3));

	printf("%s\n", strcat(dest, source));
	printf("%s\n", dest);
	printf("%s\n", strncat(dest, source, 3));

	return 0;
}