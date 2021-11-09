//2018115425 �ǿ���

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
	leftistTree input = NULL;	//�Է¹޴� ���ڸ� �����ϴ� ����ü
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
		//���ڸ� �Է¹����� input����ü �ȿ� ����ְ� �ʱ�ȭ�� �����ش�.

		if (num >= 0)
			minMeld(&result, &input);
			//num�� 0���� ũ�� insert. ������� ����ϱ� ���� result�� �ʱ�ȭ���� input�� �������ش�.
		else
		{
			//num�� �����̸� delete�� ���ش�.
			if (result == NULL)
			{
				printf("min leftist tree is NULL\n");
				printf("NULL�̶� delete�� ���� �����ϴ�\n\n");
				continue;
				//���� result�� NULL�̸� delete�� �� �� ���� ������, printf�� �˷��ش�.
			}
			else
			{
				L = result->left;
				R = result->right;
				result = NULL;
				//result�� null�� �ƴҶ� root�� �������ָ� �ȴ�.
				//root�� �¿� �츦 �պ����ָ� �ȴ�.
				//L�� root�� left, R�� root�� right�� �־��ְ� result�� NULL�� �ʱ�ȭ ���ش�.
				//�� ���� result�� L, R�� ���� �պ����ش�.
				//L�� R�� �պ��ؼ� result�� �־��൵ �Ȱ����� �����ϴ�.
				minMeld(&result, &L);
				minMeld(&result, &R);

				if (result == NULL)
				{
					printf("�̹� delete�� min leftist tree�� NULL�� �Ǿ����ϴ�\n\n");
					continue;
					//delete�� ������ �� result�� NULL�� �ȴٸ� NULL�� �Ǿ��ٰ� ������ش�.
					//preorder, inorder�� �����ϸ� �ȵǱ� ������ continue���ش�.
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

//Tree �Ҵ� ����
void freenode(leftistTree root)
{
	if (root)
	{
		freenode(root->left);
		freenode(root->right);
		free(root);
	}
}

//�ʱ�ȭ �����ִ� �Լ�. 
//�Է¹��� num�� �־��ְ� shortest�� 1, left,right�� NULL�� �ʱ�ȭ �����ش�.
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

//minMeld, minUnion�� ���� ppt�� �����߽��ϴ�.
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
{//preorder ��� �Լ�
	if (root)
	{
		printf("%d ", root->data.key);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(leftistTree root)
{//inorder ��� �Լ�
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data.key);
		inorder(root->right);
	}
}