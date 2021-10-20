//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1
#define MALLOC(p,s) \
	if(!((p) = malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
	exit(EXIT_FAILURE); \
}

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
};
listPointer* arr;

int n, cyclecheck, check;
int firstnumber = 0;
int stack[50000];
int* visited;

void checkedCycle(listPointer, int, int);
void put(int a, listPointer* first);
void printcycle();
void dfs(int v);
int main(int argc, char* argv[])
{
	int n, edge;
	int m, m1, a, b;
	int print[1000];
	int printcnt = 0;
	int firstcycle = 0;
	int vvv = 0;

	FILE* fp;
	if (argc != 2)
	{
		printf("error!\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("fp NULL\n");
		exit(1);
	}
	fscanf(fp, "%d %d ", &n, &edge);

	MALLOC(arr, sizeof(listPointer) * n);
	MALLOC(visited, sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = NULL;
		visited[i] = 0;
	}
	for (int i = 0; i < edge; i++)
	{
		fscanf(fp, "%d %d ", &a, &b);
		put(b - 1, &arr[a - 1]);
		put(a - 1, &arr[b - 1]);
		//양방향으로 linkedlist를 만들어줍니다.

		if (firstcycle == 0)
		{
			//하나씩 만들때마다 cycle이 되는지 아닌지 체크해줍니다.
			cyclecheck = 0;
			firstnumber = 0;
			check = a - 1;
			checkedCycle(arr[a - 1], -1, a - 1);
			if (cyclecheck == 1)
				firstcycle = 1;
			//한번 cycle이 나오면 그 것을 stack에 저장해두고
			//이미 나왔기 때문에 다음부터는 cyclecheck를 해주지 않습니다.
		}
	}
	dfs(0);//1기준으로 dfs로 visited 확인
	for (int i = 1; i < n; i++)
	{
		if (visited[i] == 0)
		{
			//visited가 0이라면 1과 연결이 되어있지 않기 때문에
			//not linked입니다.
			printf("not tree, not linked vertex\n");
			printf("{ %d, %d }\n", 1, i + 1);
			vvv = 1;
			break;
		}
	}
	if (cyclecheck == 1)
	{
		printcycle();
	}
	if (vvv == 0 && cyclecheck == 0)
		printf("결론 : tree 입니다.\n");
	else
		printf("\n결론 : tree 아닙니다.\n");
}
void dfs(int v) {
	//모든 vertex가 연결이 되어있는지 아닌지
	//판단하기 위해서 dfs를 사용하였습니다.
	listPointer w;
	visited[v] = TRUE;
	for (w = arr[v]; w; w = w->link)
		if (!visited[w->data])
			dfs(w->data);
}
void checkedCycle(listPointer node, int pre, int cur) 
{
	//pre는 이전의 값, cur은 현재의 값을 전달 받기 위한 변수입니다.
	int number;
	while (node)
	{
		if (node->data == check && pre != node->data)
		{
			//cycle이 되었기 때문에 cyclecheck를 1로 바꾸어줍니다.
			cyclecheck = 1;
			number = 1;
			stack[firstnumber++] = node->data;
			break;
		}
		else if (pre != node->data)
		{
			//cycle이 되지않으면 그 값을 stack에 넣어줍니다.
			stack[firstnumber++] = node->data;
			checkedCycle(arr[node->data], cur, node->data);
			if (number = 1)
				break;
			firstnumber--;
			//만약 cycle이 안되었다면 그 전 값을 하나 지워주고 다음으로 넘어가야해서
			//firstnumber을 하나 빼줍니다.
		}
		if (node->link)
			node = node->link;
		else
			break;
	}
}
void printcycle()
{
	//cycle이 되었을때 tree가 아니기 때문에 cycle을 출력해줍니다.
	printf("not tree, cycle\n");
	printf("{ ");
	for (int i = 0; i < firstnumber; i++)
	{
		printf("%d, ", stack[i] + 1);
	}
	printf("%d }\n", stack[0] + 1);
}
void put(int a, listPointer* first) 
{  
	//vertex와 edge를 받았을때 넣어주기 위한 put함수
	listPointer new;
	listPointer cur = *first;
	if (cur == NULL || a < (*first)->data)
	{
		//cur이 비어있거나 a가 처음값보다 작을떄 실행
		MALLOC(new, sizeof(*new));

		new->link = *first;
		new->data = a;
		*first = new;
	}
	else 
	{
		while (cur->link != NULL && cur->link->data < a)
			cur = cur->link;
		if (cur->link == NULL)
		{ 
			//a가 마지막에 있는 값보다 크다면 실행
			MALLOC(new, sizeof(*new));

			cur->link = new;
			new->link = NULL;
			new->data = a;
		}
		else 
		{ 
			//a가 주어진 값보다 작다면 실행
			MALLOC(new, sizeof(*new));

			new->link = cur->link;
			cur->link = new;
			new->data = a;
		}
	}
}