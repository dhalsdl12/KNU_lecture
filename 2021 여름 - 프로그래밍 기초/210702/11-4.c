#include <stdio.h>
#include <conio.h>

int main()
{
	char ch;
	
	printf("enter ?? \n");
	while ((ch = getchar()) != 'q')
		putchar(ch);

	printf("\n문자를 누를때마다 두번 출력 >> \n");
	while ((ch = _getche()) != 'q')
		putchar(ch);

	printf("\n문자를 누르면 한번 출력 >> \n");
	while ((ch = _getch()) != 'q')
		_putch(ch);
	printf("\n");

	return 0;
}