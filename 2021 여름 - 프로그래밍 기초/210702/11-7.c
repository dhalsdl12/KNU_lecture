#include <stdio.h>
#include <string.h>

int main()
{
	char src[50] = "https://www.wisualstudio.com";
	char dst[50];

	printf("src = %s\n", src);
	printf("src size = %d\n", strlen(src));
	memcpy(dst, src, strlen(src) + 1);

	printf("dst = %s\n", dst);
	printf("dst size = %d\n", strlen(dst));

	memcpy(src, "�ȳ��ϼ���!", strlen("�ȳ��ϼ���!") + 1);
	printf("src = %s\n", src);
	printf("src size = %d\n", strlen(src));

	char ch = ':';
	char* ret;
	ret = memchr(dst, ch, strlen(dst));
	printf("���� %c �ڿ��� ���ڿ� %s  �� �ִ�.\n", ch, ret);
}