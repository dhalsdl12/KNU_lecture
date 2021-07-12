#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* pi = NULL;

	pi = (int*)malloc(sizeof(int));
	if (pi == NULL)
	{
		printf("메모리 할당에 문제가 있습니다.");
		exit(1);
	}

	*pi = 3;
	printf("주소값: pi= 0x%x, 저장값 *pi= %d\n", pi, *pi);
	free(pi);

	return 0;
}