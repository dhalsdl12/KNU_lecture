//author: 2018115425 권오민
//datetime: 2021-10-07 11:50

/* sigdemo1.c - shows how a signal handler works.
 *	      - run this and press Ctrl-C a few times
 */

#include 	<stdio.h>
#include	<signal.h>
#include	<unistd.h>
#include	<stdlib.h>

int main(void)
{
	void f(int);		/* declare the handler	*/
	int i;
	signal(SIGINT, f);	/* install the handler	*/

	system("stty -echo");	//ctrl c받을때 뜨지않게 하기위해서 echo를 끈다
	for (i = 0; i < 5; i++) {	/* do something else	*/
		printf("hello\n");
		sleep(1);
	}

	system("stty echo");
	return 0;
}

void f(int signum)		/* this function is called */
{
	int input;

	printf("	Interrupted! OK to quit (y/n)? ");
	system("stty echo");	//getchar할때는 보여야하기때문에 echo를 켠다
	while (1) {
		switch (input = getchar()) {
		case 'y':
		case 'Y':
			getchar();
			exit(0);
		case 'n':
		case 'N':
		case EOF:
			getchar();
			system("stty -echo");
			return;
		default:
			printf("	cannot understand %c, ", input);
			printf("Please type y or no : ");
			getchar();
		}
	}
}