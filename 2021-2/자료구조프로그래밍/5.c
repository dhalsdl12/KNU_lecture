//2018115425 권오민

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;
typedef struct leftist* leftistTree;
struct leftist {
	leftistTree left;
	leftistTree right;
	element data;
	int shortest;
};

leftistTree first(int data);
void freenode(leftistTree root);
void preorder(leftistTree root);
void inorder(leftistTree root);
void minMeld(leftistTree* a, leftistTree* b);
void minUnion(leftistTree* a, leftistTree* b);
int main(int argc, char* argv[])
{
	int num, cnt = 0;
	leftistTree input = NULL;	//입력받는 숫자를 저장하는 구조체
	leftistTree L = NULL, R = NULL, result = NULL;
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
	while (!feof(fp))
	{
		fscanf(fp, "%d ", &num);
		input = first(num);
		//숫자를 입력받으면 input구조체 안에 집어넣고 초기화를 시켜준다.

		if (num >= 0)
			minMeld(&result, &input);
			//num이 0보다 크면 insert. 결과값을 출력하기 위한 result와 초기화해준 input을 병합해준다.
		else
		{
			//num이 음수이면 delete를 해준다.
			if (result == NULL)
			{
				printf("min leftist tree is NULL\n");
				printf("NULL이라서 delete할 수가 없습니다\n\n");
				continue;
				//만약 result가 NULL이면 delete를 할 수 없기 때문에, printf로 알려준다.
			}
			else
			{
				L = result->left;
				R = result->right;
				result = NULL;
				//result가 null이 아닐때 root를 삭제해주면 된다.
				//root의 좌와 우를 합병해주면 된다.
				//L에 root의 left, R에 root의 right를 넣어주고 result를 NULL로 초기화 해준다.
				//그 다음 result에 L, R을 각각 합병해준다.
				//L에 R을 합병해서 result에 넣어줘도 똑같을거 같습니다.
				minMeld(&result, &L);
				minMeld(&result, &R);

				if (result == NULL)
				{
					printf("이번 delete로 min leftist tree가 NULL이 되었습니다\n\n");
					continue;
					//delete를 실행한 후 result가 NULL이 된다면 NULL이 되었다고 출력해준다.
					//preorder, inorder를 실행하면 안되기 때문에 continue해준다.
				}
			}
		}
		printf("preorder: ");
		preorder(result);
		printf("\ninorder: ");
		inorder(result);
		printf("\n\n");
	}
	freenode(result);
	freenode(L);
	freenode(R);
	freenode(input);

	fclose(fp);
}

//Tree 할당 해제
void freenode(leftistTree root)
{
	if (root)
	{
		freenode(root->left);
		freenode(root->right);
		free(root);
	}
}

//초기화 시켜주는 함수. 
//입력받은 num을 넣어주고 shortest를 1, left,right를 NULL로 초기화 시켜준다.
leftistTree first(int data) 
{
	leftistTree tmp;
	tmp = malloc(sizeof(*tmp));
	tmp->data.key = data;
	tmp->shortest = 1;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

//minMeld, minUnion은 수업 ppt를 참고했습니다.
void minMeld(leftistTree* a, leftistTree* b)
{
	if (!*a)
		*a = *b;
	else if (*b)
		minUnion(a, b);
	*b = NULL;
}
void minUnion(leftistTree* a, leftistTree* b)
{
	leftistTree temp;
	if ((*a)->data.key > (*b)->data.key)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (!(*a)->right)  
		(*a)->right = *b;
	else 
		minUnion(&(*a)->right, b);

	if (!(*a)->left) 
	{
		(*a)->left = (*a)->right;
		(*a)->right = NULL;
	}
	else if ((*a)->left->shortest < (*a)->right->shortest)
	{
		temp = (*a)->left;
		(*a)->left = (*a)->right;
		(*a)->right = temp;
	}
	(*a)->shortest = (!(*a)->right) ? 1 :
		(*a)->right->shortest + 1;
}
void preorder(leftistTree root)
{//preorder 출력 함수
	if (root)
	{
		printf("%d ", root->data.key);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(leftistTree root)
{//inorder 출력 함수
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data.key);
		inorder(root->right);
	}
}