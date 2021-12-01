//2018115425 권오민
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
{ //tree를 free해주기 위한 함수
    if (root)
    {
        del(root->left);
        del(root->right);
        free(root);
    }
}
splaytree SplayInsert(splaytree root, int num, splaytree p)
{   //insert해주는 함수
    //재귀함수를 이용해서 풀었습니다. par를 넣어주기 위해서
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
        //num값이 root의 data값보다 큰지 작은지를 판단합니다.
        //그후 insert를 left, right로 나누어서 재귀해줍니다.
        //그때 부모의 값은 root가 됩니다.
        if (num < root->data)
            root->left = SplayInsert(root->left, num, root);  
        else if(num > root->data)
            root->right = SplayInsert(root->right, num, root);
        else
        {   //값이 같을때는 check를 0으로 해줘서 값이 존재한다고 출력해줍니다.
            check = 0;
            return root;
        }
        return root;
    }
}
void Splay(splaytree root)
{   //splay해주는 함수
    while (root->par)
    {
        splaytree par = root->par;
        splaytree grandpar = par->par;
        if (root->par->par == NULL)
        {
            //grandpar이 없을때는 rotation을 한번만 해줍니다.
            if (root->par->right == root)
                RRotation(root);
            else
                LRotation(root);
        }
        else
        {
            //grandpar존재하고 left, right가 par와 같다면 아래와 같이..
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
            //방향이 LR or RL이면 아래와 같이 해줍니다.
            //grandpar이 있으면 rotation을 두번합니다.
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
{   //root와 root->par을 적절하게 바꾸어주면서 했습니다.
    //수업 ppt에 있는 자료를 참고하여서 par, child를 바꾸는 작업을 했습니다.
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
{   //LRotation과 동일한 방식으로, 방향만 반대로 하여서 했습니다.
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
{//print하기 위한 함수
    if (check == 1)
    {
        printf("preorder: ");
        preorder(root);
        printf("\ninorder: ");
        inorder(root);
        printf("\n\n");
    }
    else
        printf("같은 값이 존재합니다.\n\n");
    check = 1;
}
void preorder(splaytree root)
{//preorder 출력 함수
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(splaytree root)
{//inorder 출력 함수
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}