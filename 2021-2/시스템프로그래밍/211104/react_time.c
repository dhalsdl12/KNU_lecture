//author : 2018115425 권오민
//datetime : 2021-10-21 am 11:11

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>

int main()
{
	struct termios ttystate;
	struct timeval start, end;
	int num, input, time;
	double min = 999999;
	double max = 0;
	double sum = 0;
	double diff;

	tcgetattr(0, &ttystate);
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	tcsetattr(0, TCSANOW, &ttystate);
	//echo랑 icanon을 꺼준다. 입력을 받을때 안보이고, 엔터키를 입력하지않아도 되도록.

	for (int i = 0; i < 10; i++)
	{
		time = rand() % 3 + 1;
		//시간을 1~3초로 랜덤으로 설정
		num = rand() % 10;
		//num을 0~9로 랜덤으로 설정
		printf("<A random interval of time (1 to 3 sec)>\n");
		sleep(time);
		printf("%d\n", num);

		gettimeofday(&start, NULL);
		//입력받기 시작할때 시간 정보
		while (1)
		{
			input = getchar() - '0';
			if (input == num)
				break;
			//input과 num이 같을때 까지 반복한다.
		}
		gettimeofday(&end, NULL);
		//입력이 끝났을때 시간 정보

		diff = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) / 1000000);
		//얼마나 걸린지 알기위한 diff 계산
		printf("<A user presses the %d>\n", input);

		//최대, 최소, sum구하기
		if (diff > max)
			max = diff;
		if (diff < min)
			min = diff;
		sum += diff;
		fflush(stdout);
	}
	printf("\n");
	printf("The minimum time: %.1f sec\n", min);
	printf("The maximum time: %.1f sec\n", max);
	printf("The average time: %.1f sec\n", sum / 10);

	//echo와 icanon을 다시 켜준다.
	tcgetattr(0, &ttystate);
	ttystate.c_lflag |= ICANON;
	ttystate.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &ttystate);
}