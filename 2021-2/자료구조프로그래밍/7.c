//2018115425 �ǿ���
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
    {   //parent�� null�϶� ���� �����Ҵ��� �Ͽ��� ���� �־��ݴϴ�.
        *unbal = TRUE;
        *par = malloc(sizeof(avl));
        (*par)->left = NULL;
        (*par)->right = NULL;
        (*par)->bf = 0;
        (*par)->data = x;
    }
    else if (x < (*par)->data)
    {
        //x�� parent�� �����ͺ��� ������ left�� ���� ���� �������ش�.
        //�׷��鼭 �Ʒ� �ڵ���� ��� ����
        Insert(&(*par)->left, x, unbal);
        if (*unbal)
        {
            //unbalanced�ϴٸ� parent�� bf�� üũ���ش�.
            switch ((*par)->bf) {
            case -1:
                //-1�̶�� rightchild���� 1�� ũ��.
                //�׶� �������� ���´ٸ� bf�� 0�� �ȴ�.
                (*par)->bf = 0;
                *unbal = FALSE;
                break;
            case 0:
                //0�϶� bf�� 1 �Ǵ� -1�� �ȴ�.
                //�̶��� ���ʿ� ������ bf�� 1�� �ȴ�.
                (*par)->bf = 1;
                break;
            case 1:
                //1�϶� left�� �� ������ bf�� 2�� �Ǳ⶧����
                //�̶��� leftRotation�� �Ѵ�.
                Lrotate(par, unbal);
                break;
            }
        }
    }
    else if (x > (*par)->data)
    {
        //x < (*parent)->data�� ���������� �ݴ�Ǵ� �����Դϴ�.
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
        //left right�Ѵ� �� �� ���ٸ� ������ ���Դϴ�.
        //���� ������ ���̶�� ������ݴϴ�.
        *unbal = FALSE;
        printf("The key is already in the tree\n\n");
        check = 1;
    }
}
void Lrotate(avlP* par, int* unbal)
{
    //rotation�� ���ٶ� �ڽİ�, ���ָ� �����Ѵ�.
    avlP grand, child;

    //left�̱� ������ �ڽ��� �θ��� leftchild�Դϴ�.
    child = (*par)->left;

    if (child->bf == 1)
    {
        /* LL rotation */
        (*par)->left = child->right;
        child->right = *par;
        (*par)->bf = 0;
        (*par) = child;
        //�θ��� left�� child�� right��
        //child�� right�� �θ��
        //�׸��� child�� �θ�� �ٲ��ݴϴ�.
        //ppt�� �ִ� ȸ�� ���ø� ���� �߽��ϴ�.
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
    //rightRotation�� leftRotation��
    //��� �κп��� �ݴ��̱� ������
    //�ڵ��� left, right�� �ݴ�� �Ͽ����ϴ�.
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
{//print�ϱ� ���� �Լ�
    printf("preorder: ");
    preorder(root);
    printf("\ninorder: ");
    inorder(root);
    printf("\n\n");
}
void preorder(avlP root)
{//preorder ��� �Լ�
    if (root)
    {
        printf("(%d, %d) ", root->data, root->bf);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(avlP root)
{//inorder ��� �Լ�
    if (root)
    {
        inorder(root->left);
        printf("(%d, %d) ", root->data, root->bf);
        inorder(root->right);
    }
}