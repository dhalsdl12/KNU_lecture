//2018115425 �ǿ���

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

	printf("���� Ȯ�� : %c\n", ans);
	printf("���ĺ� �ҹ��� �ϳ��� ������ ���ÿ�.\n");
	do {
		scanf("%c", &c);
		getchar();
		cnt++;
		if (c > ans)
			printf("�Է��� ������ �ƽ�Ű �ڵ� ���� �� Ů�ϴ�.\n");
		else if(c < ans)
			printf("�Է��� ������ �ƽ�Ű �ڵ� ���� �� �۽��ϴ�.\n");
		if (c == ans)
		{
			printf("�����Դϴ�! �õ�Ƚ���� %d��!\n", cnt);
			break;
		}
	} while (1);

	return 0;
}