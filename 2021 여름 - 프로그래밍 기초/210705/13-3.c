#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct student {
		int sum;
		char* dept;
		char name[12];
	};
	struct student hong = { 201800001, "��ǻ���а�", "ȫ�浿" };
	
	struct student na = { 201800002 };
	struct student bae = { 201800003 };

	scanf("%s", na.name);

	na.dept = "��ǻ���а�";
	bae.dept = "�����а�";
	memcpy(bae.name, "���", 7);
	strcpy(bae.name, "���");
	strcpy_s(bae.name, 7, "���");

	printf("%d %s %s\n", hong.sum, hong.dept, hong.name);
	printf("%d %s %s\n", na.sum, na.dept, na.name);
	printf("%d %s %s\n", bae.sum, bae.dept, bae.name);

	struct student one;
	one = bae;
	if (one.sum == bae.sum)
	{
		printf("same\n");
	}
	if (one.sum == bae.sum && !strcmp(one.name, bae.name) &&
		!strcmp(one.dept, bae.dept))
	{
		printf("same\n");
	}

	return 0;
}