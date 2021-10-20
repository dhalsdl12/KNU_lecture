#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void do_ls(char[], int);
int compare(const void* a, const void* b)
{
	return strcmp(a, b);
}
int main(int ac, char* av[])
{
	int c, n = 0;
	if (ac == 1)
		do_ls(".", 0);
	else
	{
		while ((c = getopt(ac, av, "rq")) != -1)
		{
			switch (c) {
			case 'r':
				n = 1;
				break;
			case 'q':
				n = 2;
				break;
			case '?':
				exit(1);
				break;
			}
		}
		do_ls(".", n);
	}
}
void do_ls(char dirname[], int n)
{
	DIR* dir_ptr;	/* the directory */
	struct dirent* direntp;	/* each entry	 */
	char str[100][256];
	int i = 0;

	if ((dir_ptr = opendir(dirname)) == NULL)
		fprintf(stderr, "ls1: cannot open %s\n", dirname);
	else
	{
		while ((direntp = readdir(dir_ptr)) != NULL)
		{
			strcpy(str[i], direntp->d_name);
			i++;
		}
		if (n == 0)
		{
			qsort((void*)str, i, sizeof(str[0]), compare);

			for (int j = 0; j < i; j++)
				printf("%s\n", str[j]);
		}
		else if (n == 1)
		{
			qsort((void*)str, i, sizeof(str[0]), compare);

			for (int j = i - 1; j >= 0; j--)
				printf("%s\n", str[j]);
		}
		else if (n == 2)
		{
			for (int j = 0; j < i; j++)
				printf("%s\n", str[j]);
		}
		closedir(dir_ptr);
	}
}