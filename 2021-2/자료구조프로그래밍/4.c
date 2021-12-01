//2018115425 �ǿ���

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
		//��������� linkedlist�� ������ݴϴ�.

		if (firstcycle == 0)
		{
			//�ϳ��� ���鶧���� cycle�� �Ǵ��� �ƴ��� üũ���ݴϴ�.
			cyclecheck = 0;
			firstnumber = 0;
			check = a - 1;
			checkedCycle(arr[a - 1], -1, a - 1);
			if (cyclecheck == 1)
				firstcycle = 1;
			//�ѹ� cycle�� ������ �� ���� stack�� �����صΰ�
			//�̹� ���Ա� ������ �������ʹ� cyclecheck�� ������ �ʽ��ϴ�.
		}
	}
	dfs(0);//1�������� dfs�� visited Ȯ��
	for (int i = 1; i < n; i++)
	{
		if (visited[i] == 0)
		{
			//visited�� 0�̶�� 1�� ������ �Ǿ����� �ʱ� ������
			//not linked�Դϴ�.
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
		printf("��� : tree �Դϴ�.\n");
	else
		printf("\n��� : tree �ƴմϴ�.\n");
}
void dfs(int v) {
	//��� vertex�� ������ �Ǿ��ִ��� �ƴ���
	//�Ǵ��ϱ� ���ؼ� dfs�� ����Ͽ����ϴ�.
	listPointer w;
	visited[v] = TRUE;
	for (w = arr[v]; w; w = w->link)
		if (!visited[w->data])
			dfs(w->data);
}
void checkedCycle(listPointer node, int pre, int cur) 
{
	//pre�� ������ ��, cur�� ������ ���� ���� �ޱ� ���� �����Դϴ�.
	int number;
	while (node)
	{
		if (node->data == check && pre != node->data)
		{
			//cycle�� �Ǿ��� ������ cyclecheck�� 1�� �ٲپ��ݴϴ�.
			cyclecheck = 1;
			number = 1;
			stack[firstnumber++] = node->data;
			break;
		}
		else if (pre != node->data)
		{
			//cycle�� ���������� �� ���� stack�� �־��ݴϴ�.
			stack[firstnumber++] = node->data;
			checkedCycle(arr[node->data], cur, node->data);
			if (number = 1)
				break;
			firstnumber--;
			//���� cycle�� �ȵǾ��ٸ� �� �� ���� �ϳ� �����ְ� �������� �Ѿ���ؼ�
			//firstnumber�� �ϳ� ���ݴϴ�.
		}
		if (node->link)
			node = node->link;
		else
			break;
	}
}
void printcycle()
{
	//cycle�� �Ǿ����� tree�� �ƴϱ� ������ cycle�� ������ݴϴ�.
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
	//vertex�� edge�� �޾����� �־��ֱ� ���� put�Լ�
	listPointer new;
	listPointer cur = *first;
	if (cur == NULL || a < (*first)->data)
	{
		//cur�� ����ְų� a�� ó�������� ������ ����
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
			//a�� �������� �ִ� ������ ũ�ٸ� ����
			MALLOC(new, sizeof(*new));

			cur->link = new;
			new->link = NULL;
			new->data = a;
		}
		else 
		{ 
			//a�� �־��� ������ �۴ٸ� ����
			MALLOC(new, sizeof(*new));

			new->link = cur->link;
			cur->link = new;
			new->data = a;
		}
	}
}