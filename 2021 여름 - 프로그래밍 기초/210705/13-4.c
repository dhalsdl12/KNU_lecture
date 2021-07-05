#include <stdio.h>

struct lecture {
	char name[20];
	int type;
	int cre;
	int hours;
};
typedef struct lecture lecture;

char* lectype[] = { "����","�Ϲݼ���","�����ʼ�","��������" };
char* head[] = { "���¸�","���±���","����","�ü�" };

int main()
{
	lecture course[] = { {"human", 0,2,2},
						{"c",1,3,3},
						{"python", 2,3,3},
						{"mobile",2,3,4},
						{"java",3,3,4} };
	int arysize = sizeof(course) / sizeof(course[0]);

	printf("�迭ũ��:%d\n\n", arysize);
	printf("%12s  %12s %6s %6s\n", head[0], head[1], head[2], head[3]);
	printf("=======================================\n");

	for (int i = 0; i < arysize; i++)
		printf("%16s %10s %5d %5d\n", course[i].name,
			lectype[course[i].type], course[i].cre, course[i].hours);
	return 0;
}