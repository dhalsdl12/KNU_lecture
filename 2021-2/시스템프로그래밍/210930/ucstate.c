//author: 2018115425 권오민
//datetime: 2021-09-30 11:53

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>

int main(void)
{
	struct termios info;
	int rv;

	rv = tcgetattr(0, &info);	/* read values from driver */

	if (rv == -1) {
		perror("tcgetattr");
		exit(1);
	}

	if (info.c_oflag & OLCUC)
		printf(" OLCUC is on, since its bit is 1\n");
	else
		printf(" OLCUC is OFF, since its bit is 0\n");
}
