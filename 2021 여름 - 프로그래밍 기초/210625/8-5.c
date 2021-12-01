#include <stdio.h>

int main()
{
	char* pc = (char*)100;
	int* pi = (int*)100;
	double* pd = (double*)100;
	//pd = 100;		//경고발생

	printf("%u  %u  %u\n", 
		(int)(pc - 1), (int)(pc - 0), (int)(pc + 1));
	printf("%u  %u  %u\n",
		(int)(pi - 1), (int)(pi - 0), (int)(pi + 1));
	printf("%u  %u  %u\n",
		(int)(pd - 1), (int)(pd - 0), (int)(pd + 1));

	return 0;
}