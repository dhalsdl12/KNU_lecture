#include <stdio.h>
#include <conio.h>

int main()
{
	char ch;
	
	printf("enter ?? \n");
	while ((ch = getchar()) != 'q')
		putchar(ch);

	printf("\n���ڸ� ���������� �ι� ��� >> \n");
	while ((ch = _getche()) != 'q')
		putchar(ch);

	printf("\n���ڸ� ������ �ѹ� ��� >> \n");
	while ((ch = _getch()) != 'q')
		_putch(ch);
	printf("\n");

	return 0;
}