#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	int key;
	treePointer left;
	treePointer right;
};

void freenode(treePointer root)
{
	if (root)
	{
		freenode(root->left);
		freenode(root->right);
		free(root);
	}
}
int deleteNode(int key, treePointer *root);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
treePointer search(int x, treePointer root);
int insertNode(int x, treePointer *root);
int main(int argc, char* argv[])
{
	FILE* fp;
	int num, check;
	treePointer root = NULL;

	if (argc != 2)
	{
		printf("error\n");
		exit(1);
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("fp is null\n");
		exit(1);
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d ", &num);
		if (num >= 0)
			check = insertNode(num, &root);

		else
			check = deleteNode(num * (-1), &root);


		if (check == 0)
		{
			printf("preorder : ");
			preorder(root);
			printf("\ninorder : ");
			inorder(root);
			printf("\n");
		}
	}

	freenode(root);
}
int deleteNode(int key, treePointer* root)
{
	//00. ��尡 �ϳ��� ���� ���
	if (*root == NULL)
	{
		printf("��尡 �����ϴ�.\n");
		return 1;
	}

	//01. ��ȸ(��� ������ return, ������ 02����)
	if (search(key, *root) == NULL)
	{
		printf("������ ��( %d )�� �����ϴ�.\n", key);
		return 1;
	}

	//02. ��������ּ�(Node *cur)�� ���� �θ����ּ�(Node *par) Ž��
	treePointer cur = *root;
	treePointer par = NULL;
	while (cur->key != key)
	{
		par = cur;
		if (cur->key > key)
			cur = cur->left;
		
		else
			cur = cur->right;
	}
	//cur��ġ Ž���Ϸ�
	//par��ġ Ž���Ϸ�(par�� NULL�� ����Ǿ��ִٸ� ���� ���� root ��尡 �ȴ�)

	//03. ��������� �ڽĳ���� ���� Ȯ��
	if (cur->left == NULL && cur->right == NULL)		//03-1. ��������� �ڽĳ�� x
	{
		if (par == NULL)	//���� ��尡 rootNode�� ���
		{
			*root = NULL;	//root �����Ϳ� NULL(��� ������ ����)
			free(cur);		//�������
		}
		else
		{
			if (par->left == cur)
				par->left = NULL;
			else
				par->right = NULL;
			free(cur);
		}
	}
	else if (cur->left == NULL || cur->right == NULL)	//03-2. ��������� �ڽĳ�� 1
	{
		if (par == NULL)	//���� ��尡 root ����� ���
		{
			if (cur->left != NULL)
				*root = cur->left;
		
			else
				*root = cur->right;
		}
		else				//���� ��尡 root��尡 �ƴѰ��
		{
			//�ڽĳ�� �ּҸ� ���� ������
			treePointer son = NULL;
			//son�� ��ġ�� Ȯ���ؼ� ����
			if (cur->left != NULL)
				son = cur->left;
			else
				son = cur->right;

			if (par->left == cur)
				par->left = son;
			
			else
				par->right = son;
		}
		free(cur);
	}
	else                         //03-3. ��������� �ڽĳ�� 2
	{
		treePointer succ_par = cur;
		treePointer succ = cur->right;
		while (succ->left != NULL)
		{
			succ_par = succ;
			succ = succ->left;
		}
		//succ�� ��ġ succ->left==NULL ��带 ����Ų��
		//succ_par ��ġ succ�� ������� ����Ų��.

		//succ_par->right == succ ==> �� �ݺ��۾��� �ѹ��� �������� ���� ����
		//succ_par->right != succ ==> �� �ݺ��۾��� �����ؼ� ���� ����带 Ž���� ����
		if (succ_par->right == succ)
		{
			cur->key = succ->key;
			succ_par->right = succ->right;
		}
		else
		{
			succ_par->left = succ->left;
			cur->key = succ->key;
		}
		free(succ);
	}
	return 0;
}
int insertNode(int x, treePointer *root) {
	//0. �ߺ�Ű ���� ����
	if (search(x, *root) != NULL)
	{
		printf("���� ��( %d )�� �����մϴ�.\n", x);
		return 1;
	}

	//1. ������
	//2. �����Ͱ� �ֱ�
	//3. ��ũ NULL �ʱ�ȭ
	treePointer new = (treePointer)malloc(sizeof(*new));
	if (new == NULL)
	{
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	new->key = x;
	new->left = NULL;
	new->right = NULL;

	//4. ���x
	if (*root == NULL)
		*root = new;

	//5. ��� 1�̻� ����
	else
	{
		treePointer cur = *root;	//������ġ Ž��
		treePointer par = NULL;	//������ġ�� �θ��� Ž��

		while (cur != NULL)
		{
			par = cur;
			if (par->key > x)
				cur = cur->left;
			
			else if (par->key < x)
				cur = cur->right;
		}

		//par�� ��ġ Ž��
		//cur == NULL
		if (par->key > x)
			par->left = new;
		else
			par->right = new;
	}
	return 0;
}
treePointer search(int x, treePointer root)
{
	// 1 ���۳�� �ּ� p �� ����
	treePointer p = root;
	if (p == NULL)
		return NULL;

	// 2 p�� NULL�϶����� ��� �ݺ�
	while (p != NULL)
	{
		// 3 p->key�� x �� �� 
		// 3-1 p->key == x		-> ����ּ� return
		// 3-1 p->key > x		-> p->left�� �̵�
		// 3-1 p->key < x		-> p->right�� �̵�
		if (p->key == x)
			return p;
		
		else if (p->key > x)
			p = p->left;
		
		else if (p->key < x)
			p = p->right;
	}

	//������ Ű�� ����
	//printf("�ش� Ű�� �������� �ʽ��ϴ�.\n"); -> �����Լ����� �����
	return NULL;
}
void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		printf("%d ", ptr->key);
		inorder(ptr->right);
	}
}
void preorder(treePointer ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->key);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}