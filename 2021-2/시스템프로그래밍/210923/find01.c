#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void find(char* name)
{
	char name2[1000];
	DIR* dp;
	struct dirent* dent;

	if ((dp = opendir(name)) == NULL)
	{
		return;
	}

	while ((dent = readdir(dp)) != NULL) {
		if (strcmp(dent->d_name, "..") == 0 || strcmp(dent->d_name, ".") == 0)
			continue;

		strcpy(name2, name);
		strcat(name2, "/");
		strcat(name2, dent->d_name);
		printf("%s\n", name2);

		find(name2);
	}

	closedir(dp);
}
int main(int ac, char* av[])
{
	printf("%s\n", av[1]);
	find(av[1]);

	return 0;
}
