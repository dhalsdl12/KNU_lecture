//2018115425 ±Ç¿À¹Î

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define W 10
#define H 10

void orig(int image[][W], char i[])
{
	FILE* img;
	img = fopen(i, "a");

	printf("[Original image]\n");
	fprintf(img, "[Original image]\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%d ", image[i][j]);
			fprintf(img, "%d ", image[i][j]);
		}
		printf("\n");
		fprintf(img, "\n");
	}
	printf("\n");
	fprintf(img, "\n");
	fclose(img);
}
void rotate(int image[][W], char i[])
{
	FILE* img;
	img = fopen(i, "a");
	printf("[Rotate CCW90]\n");
	fprintf(img, "[Rotate CCW90]\n");
	for (int i = W - 1; i >= 0; i--)
	{
		for (int j = 0; j < W; j++)
		{
			printf("%d ", image[j][i]);
			fprintf(img, "%d ", image[j][i]);
		}
		printf("\n");
		fprintf(img, "\n");
	}
	printf("\n");
	fprintf(img, "\n");
	fclose(img);
}
void mirror(int image[][W], char i[])
{
	FILE* img;
	img = fopen(i, "a");
	printf("[Mirror image]\n");
	fprintf(img, "[Mirror image]\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = W - 1; j >= 0; j--)
		{
			printf("%d ", image[i][j]);
			fprintf(img, "%d ", image[i][j]);
		}
		printf("\n");
		fprintf(img, "\n");
	}
	printf("\n");
	fprintf(img, "\n");
	fclose(img);
}
void reverse(int image[][W], char i[])
{
	FILE* img;
	img = fopen(i, "a");
	printf("[Reverse image]\n");
	fprintf(img, "[Reverse image]\n");
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (image[i][j] == 0)
			{
				printf("%d ", 1);
				fprintf(img, "%d ", 1);
			}
			else if (image[i][j] == 1)
			{
				printf("%d ", 0);
				fprintf(img, "%d ", 0);
			}
		}
		printf("\n");
		fprintf(img, "\n");
	}
	printf("\n");
	fprintf(img, "\n");
	fclose(img);
}
void arr(int image[][W], char fname[])
{
	FILE* fp;
	fp = fopen(fname, "r");

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			fscanf(fp, "%d", &image[i][j]);
		}
	}
	fclose(fp);
}
int main()
{
	int image[H][W];
	char fname[] = "num4.txt";
	char i[] = "image_out.txt";

	arr(image, fname);
	orig(image, i);
	rotate(image, i);
	reverse(image, i);
	mirror(image, i);

	return 0;
}