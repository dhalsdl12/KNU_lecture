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

	memcpy(src, "안녕하세요!", strlen("안녕하세요!") + 1);
	printf("src = %s\n", src);
	printf("src size = %d\n", strlen(src));

	char ch = ':';
	char* ret;
	ret = memchr(dst, ch, strlen(dst));
	printf("문자 %c 뒤에는 문자열 %s  이 있다.\n", ch, ret);
}