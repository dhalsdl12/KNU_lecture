#include <stdio.h>

#define enumstr(a) (#a)

int main()
{
	enum elist {test1 = 1, test2, test3, test4};
	char* test;

	for (int i = 1; i <= 4; i++)
	{
		test = enumstr()
		printf("%s\n", "elist[i]");
	}
}