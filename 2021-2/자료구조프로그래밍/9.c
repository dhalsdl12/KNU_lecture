//2018115425 권오민
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

typedef struct ttnode* tttree;
typedef struct ttnode {
    int node;
    int data[SIZE - 1];
    tttree child[SIZE];
    //size별로 나타내기 위해서, 배열로 data, child를 설정
}ttnode;
tttree tree = NULL;
tttree printarr[10000]; //print하기위한 list 배열

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
            //값이 존재하지 않을때 insert값 출력.
            printf("Root: ");
            printtree(tree);
            printf("\n");
        }
        else if (nodecheck == 1)
        {
            printf("Key값이 이미 존재합니다!\n\n");
            nodecheck = 0;
        }
    }

    del(tree);
    fclose(fp);

    return 0;
}
void del(tttree root)
{ //tree를 free해주기 위한 함수
    //이부분은 사실 잘 모르겠습니다.
    //그래서 바이너리 트리에서 할당 해제해줄때에서
    //다른 중간값들을 대입했습니다.
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

    //node값이 존재하는지 혹은 어디에 위치하는지 값을 받아오는 함수.
    checknode = checkinsert(tree, data, &key, &newnode);

    if (checknode == 0)
        nodecheck = 1;
    //checknode가 0이면 값이 이미 존재함
    //1이면 값이 존재하지않아서 새로이 만들어줌.
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
    //값의 존재여부와 child의 수 등을 계산해주는 함수.
    tttree newptr;
    tttree lastptr;
    int position, nodecnt, middle;
    int newkey, lastkey;
    int checkvalue;

    if (root == NULL)
    {
        //ptr이 null이면 넣어주고 바로 1 리턴.
        *newnode = NULL;
        *key = data;
        return 1;
    }
    //nodtcnt에 ptr의 연결된 node를 넣어준다.
    nodecnt = root->node;
    position = 0;
    while (position < nodecnt)
    {
        //position이 nodecnt보다 작을때를 반복
        //만약 key가 작으면 break;
        if (data < root->data[position])
            break;
        //같다면 같은 값이 존재하기때문에 return 0
        else if (data == root->data[position])
            return 0;

        position++;
    }
    checkvalue = checkinsert(root->child[position], data, &newkey, &newptr);

    //삽입하는 값인 1이 아니라면 그 값을 리턴해준다.
    if (checkvalue != 1)
        return checkvalue;

    //자리가 널널할때 실행하는 부분.
    if (nodecnt < SIZE - 1)
    {
        //position값을 찾아준다
        position = 0;
        while (position < nodecnt)
        {
            if (newkey <= root->data[position])
                break;
            position++;
        }
        //i가 position보다 클 동안 --해주면서
        //data와 child값을 변경해준다.
        for (int i = nodecnt; i > position; i--)
        {
            root->data[i] = root->data[i - 1];
            root->child[i + 1] = root->child[i];
        }

        //position위치에 newkey와 ptr을 넣어준다.
        root->data[position] = newkey;
        root->child[position + 1] = newptr;

        root->node++;

        return 2;
    }
    //position이 size-1이라면 last에 new값을 넣어준다.
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

    //mid는 2/2라서 1이다.
    middle = (SIZE - 1) / 2;
    //key에 data[1]의 값을 넣어준다.
    (*key) = root->data[middle];

    //새로이 할당을 해주고
    (*newnode) = calloc(1, sizeof(ttnode));
    //node 값은 middle값이 된다.
    root->node = middle;

    //newnode의 node는 1이 된다.
    (*newnode)->node = SIZE - 1 - middle;

    //그 다음 거기에 맞는 자식과 노드의 값들을 바꿔준다.
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
    //print 해주는 함수.
    int first = 0;
    int rear = 1, front;
    int cnt = 2;
    printarr[0] = root;

    //linked list로 만든 printarr에 초기값에 root를 넣고 while문으로 돌려준다.
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