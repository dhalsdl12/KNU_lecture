//2018115425 �ǿ���

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
{//delete�� �ϱ����� �Լ�.
	if (cnt_min == 0)
	{
		printf("delete�� interval heap�� �����ϴ�.\n\n");
		return;
	}
	int usedsize;
	int par = 1;
	in_min[1] = in_min[cnt_min];

	//�������� �ִ� ���� ���� ���� ��Ʈ ��忡 �÷��ش�.
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

	//�׸��� minheap�� �̿��Ͽ��� ��ü���ش�.
	//min���鸸 �̿��ϸ� �Ǳ⶧���� �׳� �ٷ� minheap�� ����Ͽ����ϴ�.
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

			//Ȥ�ó� min���� max������ Ŀ���ٸ� ��ü���ְ� ���� �ݺ��Ѵ�.
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
		printf("interval heap�� ������ϴ�.\n\n");
	else
		print();
}
void ins(int data)
{//�����ϴ� �Լ�
	int cur;
	int par;
	if (cnt_min == 0)
	{
		cnt_min++;
		in_min[cnt_min] = data;
		//�ƿ� ����������� root�� min���� �־��ش�.
	}
	else
	{
		if (cnt_min == cnt_max)
		{
			//������ �� �°� ����������
			//�� �������� min�� �־��ش�.
			in_min[++cnt_min] = data;
			cur = cnt_min;
			par = cnt_min / 2;

			//ó���� �� ���� �θ� ����� ���� ū������ ū��, ���������� ������ �ľ��Ѵ�.
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
			}//�˸°� ��ü������

			//�θ�� ������ index���� �������ְ�
			cur = par;
			par = cur / 2;

			//minheap, maxheap�� �ߴ���ó�� �θ� ���� �����ָ鼭
			//���� ��ü���ش�.
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
			//������ ��忡 min���� ������ ���⼭ ���ش�.

			if (in_min[cnt_min] > data)
			{//���� ���� min������ �۴ٸ� ��ü���ְ�
				//min, maxheap�� �ߴ���ó�� �ö󰡸鼭 ��ü���ش�.
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
			{//������ ����� min������ �����Ͱ��� ũ�ٸ�
				//�׳� ������ ����� max�� �־��ְ�
				//min, max heap�� �ߴ��� ó�� ��ü���ش�.
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
{//print�ϱ� ���� �Լ�
	printf("preorder: ");
	preorder(1);
	printf("\ninorder: ");
	inorder(1);
	printf("\n\n");
}
void preorder(int n)
{//preorder ��� �Լ�
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
{//inorder ��� �Լ�
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