#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* pi = NULL;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL)
	{
		printf("�޸� �Ҵ翡 ������ �ֽ��ϴ�.");
		exit(1);
	}

	*pi = 3;
	printf("�ּҰ�: pi= 0x%x, ���尪 *pi= %d\n", pi, *pi);
	free(pi);

	return 0;
}