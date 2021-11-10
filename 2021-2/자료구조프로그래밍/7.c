//2018115425 권오민
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MALLOC(p,s) \
	if(!((p) = malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
	exit(EXIT_FAILURE); \
}
typedef struct avl* avlP;
struct avl {
    avlP left;
    avlP right;
    int data;
    int bf;
};
typedef struct avl avl;
int check = 0;

void freenode(avlP root)
{
    if (root)
    {
        freenode(root->left);
        freenode(root->right);
        free(root);
    }
}

void print();
void inorder(avlP root);
void preorder(avlP root);
void Lrotate(avlP* par, int* unbal);
void Rrotate(avlP* par, int* unbal);
void Insert(avlP* par, int x, int* unbal);
int main(int argc, char* argv[])
{
    avlP par = NULL;
    int num, unbalanced = FALSE;
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

        Insert(&par, num, &unbalanced);
        if (check == 0)
            print(par);
        else
            check = 0;
    }

    freenode(par);
    fclose(fp);
    return 0;
}
void Insert(avlP* par, int x, int* unbal)
{
    if (!*par)
    {   //parent가 null일때 새로 동적할당을 하여서 집어 넣어줍니다.
        *unbal = TRUE;
        *par = malloc(sizeof(avl));
        (*par)->left = NULL;
        (*par)->right = NULL;
        (*par)->bf = 0;
        (*par)->data = x;
    }
    else if (x < (*par)->data)
    {
        //x가 parent의 데이터보다 작을때 left로 가서 새로 생성해준다.
        //그러면서 아래 코드들을 계속 실행
        Insert(&(*par)->left, x, unbal);
        if (*unbal)
        {
            //unbalanced하다면 parent의 bf를 체크해준다.
            switch ((*par)->bf) {
            case -1:
                //-1이라면 rightchild쪽이 1이 크다.
                //그때 왼쪽으로 들어온다면 bf가 0이 된다.
                (*par)->bf = 0;
                *unbal = FALSE;
                break;
            case 0:
                //0일땐 bf가 1 또는 -1이 된다.
                //이때는 왼쪽에 들어오면 bf가 1이 된다.
                (*par)->bf = 1;
                break;
            case 1:
                //1일때 left에 또 들어오면 bf가 2가 되기때문에
                //이때는 leftRotation을 한다.
                Lrotate(par, unbal);
                break;
            }
        }
    }
    else if (x > (*par)->data)
    {
        //x < (*parent)->data와 동일하지만 반대되는 내용입니다.
        Insert(&(*par)->right, x, unbal);
        if (*unbal)
        {
            switch ((*par)->bf) {
            case 1:
                (*par)->bf = 0;
                *unbal = FALSE;
                break;
            case 0:
                (*par)->bf = -1;
                break;
            case -1:
                Rrotate(par, unbal);
                break;
            }
        }
    }
    else
    {
        //left right둘다 갈 수 없다면 동일한 값입니다.
        //따라서 동일한 값이라고 출력해줍니다.
        *unbal = FALSE;
        printf("The key is already in the tree\n\n");
        check = 1;
    }
}
void Lrotate(avlP* par, int* unbal)
{
    //rotation을 해줄땐 자식과, 손주를 봐야한다.
    avlP grand, child;

    //left이기 때문에 자식은 부모의 leftchild입니다.
    child = (*par)->left;

    if (child->bf == 1)
    {
        /* LL rotation */
        (*par)->left = child->right;
        child->right = *par;
        (*par)->bf = 0;
        (*par) = child;
        //부모의 left를 child의 right로
        //child의 right를 부모로
        //그리고 child를 부모로 바꿔줍니다.
        //ppt에 있는 회전 예시를 보고 했습니다.
    }
    else
    {
        /*LR rotation */
        grand = child->right;
        child->right = grand->left;
        grand->left = child;
        (*par)->left = grand->right;
        grand->right = *par;

        switch (grand->bf) {
        case 1:
            (*par)->bf = -1;
            child->bf = 0;
            break;
        case 0:
            (*par)->bf = child->bf = 0;
            break;
        case -1:
            (*par)->bf = 0;
            child->bf = 1;
        }
        *par = grand;
    }
    (*par)->bf = 0;
    *unbal = FALSE;
}
void Rrotate(avlP* par, int* unbal) {
    //rightRotation은 leftRotation과
    //모든 부분에서 반대이기 때문에
    //코드의 left, right만 반대로 하였습니다.
    avlP grand, child;
    child = (*par)->right;
    if (child->bf == -1)
    {
        /* RR Rotation */
        (*par)->right = child->left;
        child->left = *par;
        (*par)->bf = 0;
        (*par) = child;
    }
    else
    {
        /* RL Rotataion */
        grand = child->left;
        child->left = grand->right;
        grand->right = child;
        (*par)->right = grand->left;
        grand->left = *par;
        switch (grand->bf) {
        case -1:
            (*par)->bf = 1;
            child->bf = 0;
            break;
        case 0:
            (*par)->bf = child->bf = 0;
            break;
        case 1:
            (*par)->bf = 0;
            child->bf = -1;
            break;
        }
        *par = grand;
    }
    (*par)->bf = 0;
    *unbal = FALSE;
}
void print(avlP root)
{//print하기 위한 함수
    printf("preorder: ");
    preorder(root);
    printf("\ninorder: ");
    inorder(root);
    printf("\n\n");
}
void preorder(avlP root)
{//preorder 출력 함수
    if (root)
    {
        printf("(%d, %d) ", root->data, root->bf);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(avlP root)
{//inorder 출력 함수
    if (root)
    {
        inorder(root->left);
        printf("(%d, %d) ", root->data, root->bf);
        inorder(root->right);
    }
}