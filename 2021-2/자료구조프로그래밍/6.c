//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int in_min[10100];
int in_max[10100];
int cnt_min = 0, cnt_max = 0;

void print();
void ins(int data);
void del();
void preorder(int n);
void inorder(int n);
int main(int argc, char* argv[])
{
	FILE* fp;
	int num;

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
	for (int i = 0; i < 10100; i++)
	{
		in_min[i] = -1;
		in_max[i] = -1;
	}
	while (!feof(fp))
	{
		fscanf(fp, "%d ", &num);
		if (num >= 0)
			ins(num);
		else
			del();
	}
}
void del()
{//delete를 하기위한 함수.
	if (cnt_min == 0)
	{
		printf("delete할 interval heap이 없습니다.\n\n");
		return;
	}
	int usedsize;
	int par = 1;
	in_min[1] = in_min[cnt_min];

	//마지막에 있는 값중 작은 값을 루트 노드에 올려준다.
	if (cnt_min > cnt_max)
	{
		cnt_min--;
		in_min[cnt_min + 1] = -1;
	}
	else
	{
		in_min[cnt_min] = in_max[cnt_max--];
		in_max[cnt_max + 1] = -1;
	}
	usedsize = cnt_min;
	int leftmin = 2;
	int rightmin = 3;

	//그리고 minheap을 이용하여서 교체해준다.
	//min값들만 이용하면 되기때문에 그냥 바로 minheap을 사용하였습니다.
	while (1)
	{
		int selectchild = 1;

		if (leftmin > usedsize)
			break;
		if (rightmin > usedsize)
			selectchild = leftmin;
		else
		{
			if (in_min[leftmin] > in_min[rightmin])
				selectchild = rightmin;
			else
				selectchild = leftmin;
		}

		if (in_min[selectchild] < in_min[par])
		{
			int tmp = in_min[par];
			in_min[par] = in_min[selectchild];
			in_min[selectchild] = tmp;

			//혹시나 min값이 max값보다 커진다면 교체해주고 위를 반복한다.
			if (in_min[selectchild] > in_max[selectchild])
			{
				tmp = in_min[selectchild];
				in_min[selectchild] = in_max[selectchild];
				in_max[selectchild] = tmp;
			}
			par = selectchild;
		}
		else
			break;
		leftmin = par * 2;
		rightmin = par * 2 + 1;
	}
	if (cnt_min == 0)
		printf("interval heap이 비었습니다.\n\n");
	else
		print();
}
void ins(int data)
{//삽입하는 함수
	int cur;
	int par;
	if (cnt_min == 0)
	{
		cnt_min++;
		in_min[cnt_min] = data;
		//아예 비어있을때는 root의 min값에 넣어준다.
	}
	else
	{
		if (cnt_min == cnt_max)
		{
			//갯수가 딱 맞게 차있을때는
			//그 다음값의 min에 넣어준다.
			in_min[++cnt_min] = data;
			cur = cnt_min;
			par = cnt_min / 2;

			//처음에 들어간 값이 부모 노드의 값중 큰값보다 큰지, 작은값보다 작은지 파악한다.
			if (in_min[par] > in_min[cur])
			{
				int tmp = in_min[par];
				in_min[par] = in_min[cur];
				in_min[cur] = tmp;
			}
			if (in_max[par] < in_min[cur])
			{
				int tmp = in_max[par];
				in_max[par] = in_min[cur];
				in_min[cur] = tmp;
			}//알맞게 교체해준후

			//부모와 현재의 index값을 변경해주고
			cur = par;
			par = cur / 2;

			//minheap, maxheap을 했던거처럼 부모 노드와 비교해주면서
			//값을 교체해준다.
			while (cur > 1 &&
				(in_min[par] > in_min[cur] || in_max[par] < in_max[cur]))
			{
				if (in_min[par] > in_min[cur])
				{
					int tmp = in_min[par];
					in_min[par] = in_min[cur];
					in_min[cur] = tmp;
				}
				if (in_max[par] < in_max[cur])
				{
					int tmp = in_max[par];
					in_max[par] = in_max[cur];
					in_max[cur] = tmp;
				}
				cur = par;
				par = cur / 2;
			}
		}
		else
		{
			//마지막 노드에 min값만 있을때 여기서 해준다.

			if (in_min[cnt_min] > data)
			{//들어온 값이 min값보다 작다면 교체해주고
				//min, maxheap을 했던거처럼 올라가면서 교체해준다.
				in_max[++cnt_max] = in_min[cnt_min];
				in_min[cnt_min] = data;

				cur = cnt_min;
				par = cnt_min / 2;

				while (cur > 1 &&
					(in_min[par] > in_min[cur] || in_max[par] < in_min[cur]))
				{
					if (in_min[par] > in_min[cur])
					{
						int tmp = in_min[par];
						in_min[par] = in_min[cur];
						in_min[cur] = tmp;
					}
					if (in_max[par] < in_min[cur])
					{
						int tmp = in_max[par];
						in_max[par] = in_min[cur];
						in_min[cur] = tmp;
					}
					cur = par;
					par = cur / 2;
				}
			}
			else
			{//마지막 노드의 min값보다 데이터값이 크다면
				//그냥 마지막 노드의 max에 넣어주고
				//min, max heap을 했던거 처럼 교체해준다.
				in_max[++cnt_max] = data;

				cur = cnt_min;
				par = cnt_min / 2;

				while (cur > 1 &&
					(in_min[par] > in_max[cur] || in_max[par] < in_max[cur]))
				{
					if (in_min[par] > in_max[cur])
					{
						int tmp = in_min[par];
						in_min[par] = in_max[cur];
						in_max[cur] = tmp;
					}
					if (in_max[par] < in_max[cur])
					{
						int tmp = in_max[par];
						in_max[par] = in_max[cur];
						in_max[cur] = tmp;
					}
					cur = par;
					par = cur / 2;
				}
			}
		}
	}
	print();
}
void print()
{//print하기 위한 함수
	printf("preorder: ");
	preorder(1);
	printf("\ninorder: ");
	inorder(1);
	printf("\n\n");
}
void preorder(int n)
{//preorder 출력 함수
	if (n <= cnt_min)
	{
		printf("(%d, ", in_min[n]);
		if (in_max[n] != -1)
			printf("%d) ", in_max[n]);
		else
			printf(") ");
		preorder(2 * n);
		preorder(2 * n + 1);
	}
}
void inorder(int n)
{//inorder 출력 함수
	if (n <= cnt_min)
	{
		inorder(2 * n);
		printf("(%d, ", in_min[n]);
		if (in_max[n] != -1)
			printf("%d) ", in_max[n]);
		else
			printf(") ");
		inorder(2 * n + 1);
	}
}