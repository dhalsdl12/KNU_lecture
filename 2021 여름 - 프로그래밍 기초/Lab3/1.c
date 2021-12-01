//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0;
	int n = 0;
	int grade = 0;

	double avg;

	printf("성적입력을 마치려면 음수를 입력하시오.\n");
	printf("성적을 입력하시오\n");
	while (1)
	{
		scanf("%d", &grade);
		if (grade < 0)
			break;
		sum += grade;
		n++;
	}
	if (n == 0)
		printf("입력된 성적이 없습니다.\n");
	else
	{
		avg = (double)sum / n;
		printf("%d명의 평균은 %lf입니다.\n", n, avg);
	}

	return 0;
}