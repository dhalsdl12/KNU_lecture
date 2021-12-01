//2018115425 �ǿ���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	short int row;
	short int col;
}element;
element queue[10000];	//�̵��� ���� ��ġ�� ��� ť
element result[10000];	//����� (���� �̵����)

typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[8] = { 
	{1,2},{2,1},{2,-1},{1,-2},
	{-1,-2},{-2,-1},{-2,1},{-1,2} 
};
//���� ��� �̵��ϴ��� ��� move����ü

FILE* fp;

void nullcheck()
{
	if (feof(fp))
	{
		printf("�ڷ��� ������ �����մϴ�.\n");
		exit(1);
	}
	//�ڷῡ�� �Է¹��� ���� 4������ ������ �Ǵ��ϴ� �Լ�
}
int main()
{
	char file[1000];
	int x1, y1, x2, y2;

	//���� �̸��� �޾ƿɴϴ�.
	gets(file);

	//���� �̸��� 256�ں��� ū�� Ȯ���մϴ�.
	if (strlen(file) > 256)
	{
		printf("���� �̸��� 256�ں��� Ů�ϴ�.\n");
		exit(1);
	}

	//256�� �̳��� ������ �����մϴ�.
	fp = fopen(file, "r");

	//�ش������� �ִ��� Ȯ���մϴ�.
	if (fp == NULL)
	{
		printf("�ش� �̸��� ������ �����ϴ�.\n");
		exit(1);
	}

	//�ش������� ����ִ��� Ȯ���մϴ�.
	nullcheck();

	fscanf(fp, "%d ", &x1);
	nullcheck();
	fscanf(fp, "%d ", &y1);
	nullcheck();
	fscanf(fp, "%d ", &x2);
	nullcheck();
	fscanf(fp, "%d ", &y2);

	if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 ||
		x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7)
	{
		printf("��ǥ���� �̻��մϴ�.\n");
		exit(1);
	}

	int a[8][8][2];		//a[x][y][0 or 1] 0�̸� x,y ��ǥ ������ ���� x��ǥ
						//				  1�̸� x,y ��ǥ ������ ���� y��ǥ
	int check = 0;
	int n = 0;
	int first = 0;

	printf("������ : (%d, %d)  ���� : (%d, %d)\n", x1, y1, x2, y2);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 2; k++)
				a[i][j][k] = -1;
				//���� -1�� �ΰ�, �ڵ带 �����ϸ鼭 ���� �����Ѵ�.

	queue[0].row = x1;
	queue[0].col = y1;
	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			++n;
			queue[n].row = queue[first].row + move[i].vert;
			queue[n].col = queue[first].col + move[i].horiz;
			//move[i]�� ���ؼ� �̵��� ���� ��ǥ�� queue�� �ִ´�.

			if (queue[n].row < 0 || queue[n].col < 0 || queue[n].row > 7 || queue[n].col > 7)
			{
				n--;
				continue;
				//��ǥ���� 0���� �۰ų� 7���� ũ�� continue�� �ɰ� n--�ؼ� ��ĭ�� �����ش�.
			}
			//printf("%d zz : %d %d\n", i, queue[n].row, queue[n].col);

			if (a[queue[n].row][queue[n].col][0] == -1)
			{
				a[queue[n].row][queue[n].col][0] = queue[first].row;
				a[queue[n].row][queue[n].col][1] = queue[first].col;
				//a�迭�� x���� -1�̶�� ���� ������ ��ǥ�� ���� �ʴٴ� ���̱� ������
				//queue[n]�� ���� ������ ���� a�� �ִ´�
			}
			if (queue[n].row == x2 && queue[n].col == y2)
			{
				check = 1;
				break;
				//queue[n]�� �����ϸ� break�� �Ǵ�.
			}
		}
		if (check == 1)
			break;
		first++;
		//queue�� ù��° ���� �������� �Ѱ��ش�.
		//�̷�ã��� ����� ����
	}
	int x, y;		//�뼱�� �Ǵ��ϱ� ���� ���� ����
	int cnt = 0;	//��� �̵����� �˱����� ���� ����

	x = queue[n].row;	//x�� ������ ������ ��ġ�� x��
	y = queue[n].col;	//y�� ������ ������ ��ġ�� y��

	while (1)
	{
		result[cnt].row = x;
		result[cnt].col = y;
		//����� ó���� x,y�� �ִ´�.

		//printf("result : %d %d\n", result[cnt].row, result[cnt].col);
		//printf("cnt = %d\n", cnt);

		if (result[cnt].row == x1 && result[cnt].col == y1)
			break;
		//ó������ ���ƿ����� break�� �Ѵ�.

		x = a[result[cnt].row][result[cnt].col][0];
		y = a[result[cnt].row][result[cnt].col][1];
		//ó���� �ƴ϶�� x,y�� ���� ���� ��ġ�� �����ְ� �ݺ�.
		cnt++;
	}
	
	printf("(%d, %d)", x1, y1);
	for (int i = cnt - 1; i >= 0; i--)
	{
		printf(" -> ");
		printf("(%d, %d)", result[i].row, result[i].col);
	}

	fclose(fp);
}