//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	short int row;
	short int col;
}element;
element queue[10000];	//이동한 말의 위치를 담는 큐
element result[10000];	//결과값 (말의 이동경로)

typedef struct {
	short int vert;
	short int horiz;
}offsets;
offsets move[8] = { 
	{1,2},{2,1},{2,-1},{1,-2},
	{-1,-2},{-2,-1},{-2,1},{-1,2} 
};
//말이 어떻게 이동하는지 담는 move구조체

FILE* fp;

void nullcheck()
{
	if (feof(fp))
	{
		printf("자료의 개수가 부족합니다.\n");
		exit(1);
	}
	//자료에서 입력받은 수가 4개보다 작은지 판단하는 함수
}
int main()
{
	char file[1000];
	int x1, y1, x2, y2;

	//파일 이름을 받아옵니다.
	gets(file);

	//파일 이름이 256자보다 큰지 확인합니다.
	if (strlen(file) > 256)
	{
		printf("파일 이름이 256자보다 큽니다.\n");
		exit(1);
	}

	//256자 이내면 파일을 오픈합니다.
	fp = fopen(file, "r");

	//해당파일이 있는지 확인합니다.
	if (fp == NULL)
	{
		printf("해당 이름의 파일이 없습니다.\n");
		exit(1);
	}

	//해당파일이 비어있는지 확인합니다.
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
		printf("좌표값이 이상합니다.\n");
		exit(1);
	}

	int a[8][8][2];		//a[x][y][0 or 1] 0이면 x,y 좌표 이전에 말의 x좌표
						//				  1이면 x,y 좌표 이전에 말의 y좌표
	int check = 0;
	int n = 0;
	int first = 0;

	printf("시작점 : (%d, %d)  종점 : (%d, %d)\n", x1, y1, x2, y2);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 2; k++)
				a[i][j][k] = -1;
				//전부 -1로 두고, 코드를 진행하면서 값을 대입한다.

	queue[0].row = x1;
	queue[0].col = y1;
	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			++n;
			queue[n].row = queue[first].row + move[i].vert;
			queue[n].col = queue[first].col + move[i].horiz;
			//move[i]로 인해서 이동한 말의 좌표를 queue에 넣는다.

			if (queue[n].row < 0 || queue[n].col < 0 || queue[n].row > 7 || queue[n].col > 7)
			{
				n--;
				continue;
				//좌표값이 0보다 작거나 7보다 크면 continue를 걸고 n--해서 한칸을 돌려준다.
			}
			//printf("%d zz : %d %d\n", i, queue[n].row, queue[n].col);

			if (a[queue[n].row][queue[n].col][0] == -1)
			{
				a[queue[n].row][queue[n].col][0] = queue[first].row;
				a[queue[n].row][queue[n].col][1] = queue[first].col;
				//a배열의 x값이 -1이라는 것은 이전의 좌표가 있지 않다는 것이기 때문에
				//queue[n]에 오기 직전의 값을 a에 넣는다
			}
			if (queue[n].row == x2 && queue[n].col == y2)
			{
				check = 1;
				break;
				//queue[n]이 도착하면 break를 건다.
			}
		}
		if (check == 1)
			break;
		first++;
		//queue의 첫번째 값을 다음으로 넘겨준다.
		//미로찾기와 비슷한 개념
	}
	int x, y;		//노선을 판단하기 위해 넣은 변수
	int cnt = 0;	//몇개를 이동한지 알기위해 넣은 변수

	x = queue[n].row;	//x는 마지막 도착한 위치의 x값
	y = queue[n].col;	//y는 마지막 도착한 위치의 y값

	while (1)
	{
		result[cnt].row = x;
		result[cnt].col = y;
		//결과값 처음에 x,y를 넣는다.

		//printf("result : %d %d\n", result[cnt].row, result[cnt].col);
		//printf("cnt = %d\n", cnt);

		if (result[cnt].row == x1 && result[cnt].col == y1)
			break;
		//처음으로 돌아왔을때 break를 한다.

		x = a[result[cnt].row][result[cnt].col][0];
		y = a[result[cnt].row][result[cnt].col][1];
		//처음이 아니라면 x,y의 값을 이전 위치로 돌려주고 반복.
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