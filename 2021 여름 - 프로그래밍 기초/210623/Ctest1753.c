#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
	int vertex;
	int weight;
}element;
element* node;

int** array;
int* distance;
int* found;
int stack[100][1];

void shortestPath(int v, int n);
int choose(int n);
int main(int argc, char** argv)
{
	int num, edge;
	int f = 0;
	int arr[100];
	int q = 0;
	int v1, v2, w;
	int start;

	scanf("%d %d", &num, &edge);
	scanf("%d", &start);
	array = (int**)malloc(sizeof(int*) * num);
	distance = (int*)malloc(sizeof(int) * num);
	found = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
	{
		distance[i] = 100000000;
		found[i] = -1;
		array[i] = (int*)malloc(sizeof(int) * num);

		for (int j = 0; j < num; j++)
		{
			array[i][j] = 100000000;
			if (i == j) array[i][j] = 0;
		}
	}

	for (int i = 0; i < edge; i++)
	{
		scanf("%d %d %d", &v1, &v2, &w);
		array[v1 - 1][v2 - 1] = w;
	}

	shortestPath(start - 1, num);

	for (int f = 0; f < num; f++)
	{
		if (f == num)
			printf("0\n");
		else {
			int k = stack[f][0];
			arr[q++] = k;
			while (1)
			{
				k = stack[k - 1][0];
				if (k == 0)
					break;
				arr[q++] = k;
			}
			if (distance[f] == 100000000)
				printf("INF\n");
			else
				printf("%d\n", distance[f]);
		}
	}

	for (int i = 0; i < num; i++)
		free(array[i]);
	free(array);
}

void shortestPath(int v, int n)
{
	int i, u, w;
	for (i = 0; i < n; i++)
	{
		found[i] = 0;
		distance[i] = array[v][i];
	}
	found[v] = 1;
	distance[v] = 0;
	for (int i = 0; i < n - 2; i++)
	{
		u = choose(n);
		found[u] = 1;
		for (w = 0; w < n; w++)
		{
			if (!found[w])
				if (u < 0)
					continue;
				else if (distance[u] + array[u][w] < distance[w])
				{
					distance[w] = distance[u] + array[u][w];
					stack[w][0] = u + 1;
				}
		}
	}
}
int choose(int n)
{
	int i, min, minpos;
	min = 100000000;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}