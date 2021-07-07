#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int fwrite_ex()
{
	int buffer[SIZE] = { 10,20,30,40,50 };
	FILE* fp;

	fp = fopen("binary.bin", "wb");

	fwrite(buffer, sizeof(int), SIZE, fp);
	fclose(fp);

	return 0;
}
int fread_ex()
{
	int buffer[SIZE];
	FILE* fp;

	fp = fopen("binary.bin", "rb");

	fread(buffer, sizeof(int), SIZE, fp);

	printf("%d\n", buffer[0]);
	for (int i = 0; i < SIZE; i++)
		printf("%d ", buffer[i]);
	printf("\n");
	fclose(fp);

	return 0;
}
int main()
{
	fwrite_ex();
	fread_ex();

	return 0;
}