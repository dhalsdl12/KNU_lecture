#include <stdio.h>

int main()
{
	int m = 100, n = 200, tmp;
	int* pn = &n;
	int* pm = &m;
	printf("%d %d\n", m, n);

	tmp = *pm;
	*pm = *pn;
	*pn = tmp;
	printf("%d %d\n", m, n);

	tmp = m;
	m = n;
	n = tmp;
	printf("%d %d\n", m, n);

	return 0;
}