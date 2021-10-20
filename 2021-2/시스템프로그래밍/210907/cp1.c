/** cp1.c
 *		version 1 of cp - uses read and wirte with tunable buffer size
 *		usage: cp1 src dest
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define BUFFERSIZE 4096
#define COPYMODE 0644

void oops(char*, char*, int);
int main(int ac, char* av[])
{
	int in_fd, out_fd, n_chars;
	char buf[BUFFERSIZE];
	char check[1000];

	/* check args */
	if (ac == 3)
	{
		if (strcmp(av[1], av[2]) == 0)
			oops(av[1], av[2], 0);
		/* open files */
		if ((in_fd = open(av[1], O_RDONLY)) == -1)
			oops("Cannot open ", av[1], 1);

		if ((out_fd = creat(av[2], COPYMODE)) == -1)
			oops("Cannot creat ", av[2], 1);

		/* copy files */
		while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
			if (write(out_fd, buf, n_chars) != n_chars)
				oops("Write error to ", av[2], 1);

		if (n_chars == -1)
			oops("Read error from ", av[1], 1);

		/* close files */
		if (close(in_fd) == -1 || close(out_fd) == -1)
			oops("Error closing files", "", 1);
	}

	else if (ac == 4)
	{
		if (strcmp(av[1], "-i") != 0)
		{
			printf("잘못된 명령어입니다\n");
			exit(1);
		}

		if (strcmp(av[2], av[3]) == 0)
			oops(av[2], av[3], 0);

		if ((in_fd = open(av[2], O_RDONLY)) == -1)
			oops("Cannot open ", av[2], 1);

		printf("cp1: '%s'를 덮어쓸까요 (y/n)?", av[3]);

		while (1)
		{
			scanf("%s", check);

			if (strcmp(check, "y") == 0)
				break;
			else if (strcmp(check, "n") == 0)
				break;
		}
		if (strcmp(check, "y") == 0)
		{
			if ((out_fd = creat(av[3], COPYMODE)) == -1)
				oops("Cannot creat ", av[3], 1);

			while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
				if (write(out_fd, buf, n_chars) != n_chars)
					oops("Write error to ", av[3], 1);

			if (n_chars == -1)
				oops("Read error from ", av[2], 1);

			/* close files */
			if (close(in_fd) == -1 || close(out_fd) == -1)
				oops("Error closing files", "", 1);
		}
	}
	else
	{
		fprintf(stderr, "usage: %s source destination\n", *av);
		exit(1);
	}
}

void oops(char* s1, char* s2, int n)
{
	if (n == 0)
	{
		printf("cp1: '%s' 와  '%s' 는 같은 파일\n", s1, s2);
		exit(1);
	}
	else if (n == 1)
	{
		fprintf(stderr, "Error: %s ", s1);
		perror(s2);
		exit(1);
	}
}