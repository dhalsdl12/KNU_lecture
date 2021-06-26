//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int cnt = 0;
	char c;

	srand(time(NULL));
	char ans = 97 + rand()%26;

	printf("정답 확인 : %c\n", ans);
	printf("알파벳 소문자 하나를 추측해 보시오.\n");
	do {
		scanf("%c", &c);
		getchar();
		cnt++;
		if (c > ans)
			printf("입력한 문자의 아스키 코드 값이 더 큽니다.\n");
		else if(c < ans)
			printf("입력한 문자의 아스키 코드 값이 더 작습니다.\n");
		if (c == ans)
		{
			printf("정답입니다! 시도횟수는 %d번!\n", cnt);
			break;
		}
	} while (1);

	return 0;
}