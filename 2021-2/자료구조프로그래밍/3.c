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
	//00. 노드가 하나도 없는 경우
	if (*root == NULL)
	{
		printf("노드가 없습니다.\n");
		return 1;
	}

	//01. 조회(노드 없으면 return, 있으면 02진행)
	if (search(key, *root) == NULL)
	{
		printf("삭제할 값( %d )이 없습니다.\n", key);
		return 1;
	}

	//02. 삭제노드주소(Node *cur)와 삭제 부모노드주소(Node *par) 탐색
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
	//cur위치 탐색완료
	//par위치 탐색완료(par가 NULL로 저장되어있다면 삭제 노드는 root 노드가 된다)

	//03. 삭제노드의 자식노드의 수를 확인
	if (cur->left == NULL && cur->right == NULL)		//03-1. 삭제노드의 자식노드 x
	{
		if (par == NULL)	//삭제 노드가 rootNode인 경우
		{
			*root = NULL;	//root 포인터에 NULL(노드 연결이 없음)
			free(cur);		//노드제거
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
	else if (cur->left == NULL || cur->right == NULL)	//03-2. 삭제노드의 자식노드 1
	{
		if (par == NULL)	//삭제 노드가 root 노드인 경우
		{
			if (cur->left != NULL)
				*root = cur->left;
		
			else
				*root = cur->right;
		}
		else				//삭제 노드가 root노드가 아닌경우
		{
			//자식노드 주소를 담을 포인터
			treePointer son = NULL;
			//son의 위치를 확인해서 저장
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
	else                         //03-3. 삭제노드의 자식노드 2
	{
		treePointer succ_par = cur;
		treePointer succ = cur->right;
		while (succ->left != NULL)
		{
			succ_par = succ;
			succ = succ->left;
		}
		//succ의 위치 succ->left==NULL 노드를 가리킨다
		//succ_par 위치 succ의 상위노드 가리킨다.

		//succ_par->right == succ ==> 위 반복작업을 한번도 수행하지 않은 상태
		//succ_par->right != succ ==> 위 반복작업을 수행해서 왼쪽 끝노드를 탐색한 상태
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
	//0. 중복키 존재 여부
	if (search(x, *root) != NULL)
	{
		printf("같은 값( %d )이 존재합니다.\n", x);
		return 1;
	}

	//1. 노드생성
	//2. 데이터값 넣기
	//3. 링크 NULL 초기화
	treePointer new = (treePointer)malloc(sizeof(*new));
	if (new == NULL)
	{
		printf("동적할당 실패!\n");
		exit(1);
	}
	new->key = x;
	new->left = NULL;
	new->right = NULL;

	//4. 노드x
	if (*root == NULL)
		*root = new;

	//5. 노드 1이상 존재
	else
	{
		treePointer cur = *root;	//삽입위치 탐색
		treePointer par = NULL;	//삽입위치의 부모노드 탐색

		while (cur != NULL)
		{
			par = cur;
			if (par->key > x)
				cur = cur->left;
			
			else if (par->key < x)
				cur = cur->right;
		}

		//par의 위치 탐색
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
	// 1 시작노드 주소 p 로 받음
	treePointer p = root;
	if (p == NULL)
		return NULL;

	// 2 p가 NULL일때까지 계속 반복
	while (p != NULL)
	{
		// 3 p->key와 x 를 비교 
		// 3-1 p->key == x		-> 노드주소 return
		// 3-1 p->key > x		-> p->left로 이동
		// 3-1 p->key < x		-> p->right로 이동
		if (p->key == x)
			return p;
		
		else if (p->key > x)
			p = p->left;
		
		else if (p->key < x)
			p = p->right;
	}

	//동일한 키가 없다
	//printf("해당 키가 존재하지 않습니다.\n"); -> 메인함수에서 출력함
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