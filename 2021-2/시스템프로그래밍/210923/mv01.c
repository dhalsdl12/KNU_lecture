#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 4096
#define COPYMODE 0644

int isFileOrDir(char* s)
{
	if (access(s, F_OK) == 0)
	{
		FILE* fp = fopen(s, "w");
		if (fp)
		{
			fclose(fp);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 2;
	}
}
int main(int ac, char* av[])
{
	int result;
	int isfile = isFileOrDir(av[2]);
	int in_fd, out_fd, n_chars;
	char buf[BUFFERSIZE];
	char check[1000];

	if (access(av[1], F_OK) != 0) {
		printf("av[1]의 파일이 존재하지 않음\n");
		exit(0);
	}
	if (isfile == 0)
	{
		strcat(av[2], "/");
		strcat(av[2], av[1]);
		if (access(av[2], F_OK) == 0)
		{
			printf("같은 이름의 파일이 존재\n");
			exit(0);
		}
		FILE* fp = fopen(av[2], "w");
		fclose(fp);

		in_fd = open(av[1], O_RDONLY);
		out_fd = creat(av[2], COPYMODE);
		while ((n_chars = read(in_fd, buf, BUFFERSIZE)) > 0)
			write(out_fd, buf, n_chars);
		remove(av[1]);
	}
	else if (isfile == 1)
	{
		printf("같은 이름의 파일이 존재\n");
	}
	else if (isfile == 2)
	{
		result = rename(av[1], av[2]);
		if (result == 0)
		{
			printf("The file is renamed successfully.\n");
		}
		else
		{
			printf("The file could not be renamed.\n");
		}
	}
}