//2018115425 �ǿ���
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
	if(!((p) = malloc(s))){ \
		fprintf(stderr, "insufficient memory"); \
	exit(EXIT_FAILURE); \
}

typedef struct splay_tree* splaytree;
typedef struct splay_tree {
    int data;
    splaytree left, right;
    splaytree par;
};
splaytree tree;
splaytree bal;
int check = 1;

void del(splaytree root);
void Splay(splaytree root);
void LRotation(splaytree root);
void RRotation(splaytree root);
splaytree SplayInsert(splaytree root, int num, splaytree pa);
void print(splaytree root);
void preorder(splaytree root);
void inorder(splaytree root);
int main(int argc, char* argv[])
{
    int num;
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
        tree = SplayInsert(tree, num, NULL);
        Splay(bal); 
        print(tree);
    }
    del(tree);
    fclose(fp);

    return 0;
}
void del(splaytree root)
{ //tree�� free���ֱ� ���� �Լ�
    if (root)
    {
        del(root->left);
        del(root->right);
        free(root);
    }
}
splaytree SplayInsert(splaytree root, int num, splaytree p)
{   //insert���ִ� �Լ�
    //����Լ��� �̿��ؼ� Ǯ�����ϴ�. par�� �־��ֱ� ���ؼ�
    splaytree tmp;
    if (root == NULL)
    {
        MALLOC(tmp, sizeof(*tmp));
        tmp->data = num;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->par = p;

        bal = tmp;
        return tmp;
    }
    else
    {
        //num���� root�� data������ ū�� �������� �Ǵ��մϴ�.
        //���� insert�� left, right�� ����� ������ݴϴ�.
        //�׶� �θ��� ���� root�� �˴ϴ�.
        if (num < root->data)
            root->left = SplayInsert(root->left, num, root);  
        else if(num > root->data)
            root->right = SplayInsert(root->right, num, root);
        else
        {   //���� �������� check�� 0���� ���༭ ���� �����Ѵٰ� ������ݴϴ�.
            check = 0;
            return root;
        }
        return root;
    }
}
void Splay(splaytree root)
{   //splay���ִ� �Լ�
    while (root->par)
    {
        splaytree par = root->par;
        splaytree grandpar = par->par;
        if (root->par->par == NULL)
        {
            //grandpar�� �������� rotation�� �ѹ��� ���ݴϴ�.
            if (root->par->right == root)
                RRotation(root);
            else
                LRotation(root);
        }
        else
        {
            //grandpar�����ϰ� left, right�� par�� ���ٸ� �Ʒ��� ����..
            if (grandpar->right == par && par->right == root)
            { 
                RRotation(par);
                RRotation(root);
            }
            else if (grandpar->left == par && par->left == root)
            { 
                LRotation(par);
                LRotation(root);
            }
            //������ LR or RL�̸� �Ʒ��� ���� ���ݴϴ�.
            //grandpar�� ������ rotation�� �ι��մϴ�.
            else { 
                if (root->par->right == root)
                {
                    RRotation(root);
                    LRotation(root);
                }
                else
                {
                    LRotation(root);
                    RRotation(root);
                }
            }
        }
    }
}
void LRotation(splaytree root)
{   //root�� root->par�� �����ϰ� �ٲپ��ָ鼭 �߽��ϴ�.
    //���� ppt�� �ִ� �ڷḦ �����Ͽ��� par, child�� �ٲٴ� �۾��� �߽��ϴ�.
    splaytree par = root->par;
    splaytree tmp = NULL;

    if (!par) 
        return;
    par->left = tmp = root->right;
    root->right = par;

    root->par = par->par;
    par->par = root;
    if (tmp)
        tmp->par = par;
    if (root->par)
    {
        if (root->par->left == par)
            root->par->left = root;
        else
            root->par->right = root;
    }
    else
        tree = root;
} 
void RRotation(splaytree root)
{   //LRotation�� ������ �������, ���⸸ �ݴ�� �Ͽ��� �߽��ϴ�.
    splaytree par = root->par;
    splaytree tmp = NULL;
    if (!par) 
        return;
    par->right = tmp = root->left;
    root->left = par;

    root->par = par->par;
    par->par = root;
    if (tmp)
        tmp->par = par;
    if (root->par)
    {
        if (root->par->left == par)
            root->par->left = root;
        else
            root->par->right = root;
    }
    else
        tree = root;
}
void print(splaytree root)
{//print�ϱ� ���� �Լ�
    if (check == 1)
    {
        printf("preorder: ");
        preorder(root);
        printf("\ninorder: ");
        inorder(root);
        printf("\n\n");
    }
    else
        printf("���� ���� �����մϴ�.\n\n");
    check = 1;
}
void preorder(splaytree root)
{//preorder ��� �Լ�
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(splaytree root)
{//inorder ��� �Լ�
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}