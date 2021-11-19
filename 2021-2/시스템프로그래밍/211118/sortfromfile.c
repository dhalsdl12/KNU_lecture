//author : 2018115425 권오민
//datetime : 21-11-18 11:16

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	if(argc != 2)
 	{
		printf("error");
	  	exit(1);
  	}

	//0인 stdin을 닫아주고
  	close(0);
	//read로 열어준다
  	open(argv[1], O_RDONLY);
	//그다음 execlp를 써서 srot해준다.
  	execlp("sort", "sort", NULL);
}