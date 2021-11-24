//2018115425 �ǿ���
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct ttnode* tttree;
typedef struct ttnode {
    int node;
    int data[SIZE - 1];
    tttree child[SIZE];
    //size���� ��Ÿ���� ���ؼ�, �迭�� data, child�� ����
}ttnode;
tttree tree = NULL;
tttree printarr[10000]; //print�ϱ����� list �迭

int nodecheck = 0;
int check[10000] = { 0, };

void del(tttree root);
void nodeinsert(int);
int checkinsert(tttree, int, int*, tttree*);
void printtree(tttree begin);
void main(int argc, char* argv[])
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
        for (int i = 0; i < 10000; i++)
            check[i] = 0;
        fscanf(fp, "%d ", &num);
        nodeinsert(num);
        if (nodecheck == 0)
        {
            //���� �������� ������ insert�� ���.
            printf("Root: ");
            printtree(tree);
            printf("\n");
        }
        else if (nodecheck == 1)
        {
            printf("Key���� �̹� �����մϴ�!\n\n");
            nodecheck = 0;
        }
    }

    del(tree);
    fclose(fp);

    return 0;
}
void del(tttree root)
{ //tree�� free���ֱ� ���� �Լ�
    //�̺κ��� ��� �� �𸣰ڽ��ϴ�.
    //�׷��� ���̳ʸ� Ʈ������ �Ҵ� �������ٶ�����
    //�ٸ� �߰������� �����߽��ϴ�.
    if (root)
    {
        del(root->child[0]);
        del(root->child[1]);
        del(root->child[2]);
        free(root);
    }
}
void nodeinsert(int data)
{
    tttree newnode;
    int key;
    int checknode;

    //node���� �����ϴ��� Ȥ�� ��� ��ġ�ϴ��� ���� �޾ƿ��� �Լ�.
    checknode = checkinsert(tree, data, &key, &newnode);

    if (checknode == 0)
        nodecheck = 1;
    //checknode�� 0�̸� ���� �̹� ������
    //1�̸� ���� ���������ʾƼ� ������ �������.
    if (checknode == 1)
    {
        tttree leftnode = tree;
        tree = calloc(1, sizeof(ttnode));
        tree->node = 1;
        tree->data[0] = key;
        tree->child[0] = leftnode;
        tree->child[1] = newnode;
    }
}
int checkinsert(tttree root, int data, int* key, tttree* newnode)
{
    //���� ���翩�ο� child�� �� ���� ������ִ� �Լ�.
    tttree newptr;
    tttree lastptr;
    int position, nodecnt, middle;
    int newkey, lastkey;
    int checkvalue;

    if (root == NULL)
    {
        //ptr�� null�̸� �־��ְ� �ٷ� 1 ����.
        *newnode = NULL;
        *key = data;
        return 1;
    }
    //nodtcnt�� ptr�� ����� node�� �־��ش�.
    nodecnt = root->node;
    position = 0;
    while (position < nodecnt)
    {
        //position�� nodecnt���� �������� �ݺ�
        //���� key�� ������ break;
        if (data < root->data[position])
            break;
        //���ٸ� ���� ���� �����ϱ⶧���� return 0
        else if (data == root->data[position])
            return 0;

        position++;
    }
    checkvalue = checkinsert(root->child[position], data, &newkey, &newptr);

    //�����ϴ� ���� 1�� �ƴ϶�� �� ���� �������ش�.
    if (checkvalue != 1)
        return checkvalue;

    //�ڸ��� �γ��Ҷ� �����ϴ� �κ�.
    if (nodecnt < SIZE - 1)
    {
        //position���� ã���ش�
        position = 0;
        while (position < nodecnt)
        {
            if (newkey <= root->data[position])
                break;
            position++;
        }
        //i�� position���� Ŭ ���� --���ָ鼭
        //data�� child���� �������ش�.
        for (int i = nodecnt; i > position; i--)
        {
            root->data[i] = root->data[i - 1];
            root->child[i + 1] = root->child[i];
        }

        //position��ġ�� newkey�� ptr�� �־��ش�.
        root->data[position] = newkey;
        root->child[position + 1] = newptr;

        root->node++;

        return 2;
    }
    //position�� size-1�̶�� last�� new���� �־��ش�.
    if (position == SIZE - 1)
    {
        lastkey = newkey;
        lastptr = newptr;
    }
    else
    {
        tttree tmp;
        lastkey = root->data[SIZE - 2];
        lastptr = root->child[SIZE - 1];

        for (int i = SIZE - 2; i > position; i--)
        {
            root->data[i] = root->data[i - 1];

            tmp = root->child[i];
            root->child[i] = NULL;
            root->child[i + 1] = tmp;
        }
        root->data[position] = newkey;
        root->child[position + 1] = newptr;
    }

    //mid�� 2/2�� 1�̴�.
    middle = (SIZE - 1) / 2;
    //key�� data[1]�� ���� �־��ش�.
    (*key) = root->data[middle];

    //������ �Ҵ��� ���ְ�
    (*newnode) = calloc(1, sizeof(ttnode));
    //node ���� middle���� �ȴ�.
    root->node = middle;

    //newnode�� node�� 1�� �ȴ�.
    (*newnode)->node = SIZE - 1 - middle;

    //�� ���� �ű⿡ �´� �ڽİ� ����� ������ �ٲ��ش�.
    for (int i = 0; i < (*newnode)->node; i++)
    {
        tttree tmp2;
        int childnum = i + middle + 1;

        tmp2 = root->child[childnum];
        root->child[childnum] = NULL;
        (*newnode)->child[i] = tmp2;

        if (i < (*newnode)->node - 1)
        {
            (*newnode)->data[i] = root->data[childnum];
        }
        else
        {
            (*newnode)->data[i] = lastkey;
        }
    }
    (*newnode)->child[(*newnode)->node] = lastptr;

    return 1;
}
void printtree(tttree root)
{
    //print ���ִ� �Լ�.
    int first = 0;
    int rear = 1, front;
    int cnt = 2;
    printarr[0] = root;

    //linked list�� ���� printarr�� �ʱⰪ�� root�� �ְ� while������ �����ش�.
    while (first < rear)
    {
        front = rear;
        if (first != 0)
        {
            printf("Level %d: ", cnt);
            cnt++;
        }
        while (first < front)
        {
            if (printarr[first]->data[1] != 0)
            {
                printf("( ");
                if (check[printarr[first]->data[0]] == 0)
                {
                    printf("%d ", printarr[first]->data[0]);
                    check[printarr[first]->data[0]] = 1;
                }
                if (check[printarr[first]->data[1]] == 0)
                {
                    printf("%d ", printarr[first]->data[1]);
                    check[printarr[first]->data[1]] = 1;
                }
                printf(") ");

                if (printarr[first]->child[0])
                {
                    printarr[rear] = printarr[first]->child[0];
                    rear++;
                }
                if (printarr[first]->child[1])
                {
                    printarr[rear] = printarr[first]->child[1];
                    rear++;
                }
                if (printarr[first]->child[2])
                {
                    printarr[rear] = printarr[first]->child[2];
                    rear++;
                }
            }
            else {
                if (check[printarr[first]->data[0]] == 0)
                {
                    printf("( ");
                    printf("%d ", printarr[first]->data[0]);
                    printf(") ");
                    check[printarr[first]->data[0]] = 1;
                }
                if (printarr[first]->child[0])
                {
                    printarr[rear] = printarr[first]->child[0];
                    rear++;
                }
                if (printarr[first]->child[1])
                {
                    printarr[rear] = printarr[first]->child[1];
                    rear++;
                }
            }
            first++;
        }
        printf("\n");
    }
}