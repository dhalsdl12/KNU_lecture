//author : 2018115425 권오민
//datetime : 21-11-18 11:16

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>

#define 	oops(m,x)	{ perror(m); exit(x); }

int main(int ac, char **av)
{
	int	thepipe[2],		/* two file descriptors */
		newfd,			/* useful for pipes	*/
		pid;			/* and the pid		*/

	if ( ac !=4 ) {
		fprintf( stderr, "usage : pipe cmd1 cmd2 cmd3\n" );
		exit(1);
	}

	if ( pipe ( thepipe ) == -1)	
		oops ("Cannot get a pipe", 1);
	if ( (pid = fork()) == -1 )	
		oops("Cannot fork", 2);

	/*-------------------------------------------------------*/
	/*	Right here, there are two processes		*/
	/*	parent will read from pipe			*/
	if ( pid > 0 ){			/* parent will exec av[2] 	*/
		close( thepipe[1] );	/* parent doesn't write to pipe */
		if ( dup2(thepipe[0], 0) == -1)
			oops("could not redirect stdin" ,3);		
		close( thepipe[0] );	/* stdin is duped, close pipe	*/
		
		//아래부분을 추가했습니다.
		//pipe를 하나 새로 생성해준다.
		if ( pipe ( thepipe ) == -1)	
			oops ("Cannot get a pipe", 1);
		//fork를 한번 더 해준다.
		if ( (pid = fork()) == -1 )	
			oops("Cannot fork", 2);
		
		//그때 자식이 2번째 값이니까 처리해주고
		if(pid == 0)
		{
			close(thepipe[0]);		/* stdout is duped, close pipe	*/
			if ( dup2(thepipe[1], 1) == -1 )
				oops("could not redirect stdout", 4);
			execlp ( av[2], av[2], NULL);
			oops(av[2], 5);
		}
		
		//그때 부모는 3번째 값이니까 처리해준다.
		else
		{
			close(thepipe[1]);
			if ( dup2(thepipe[0], 0) == -1)
				oops("could not redirect stdin" ,3);	
			close(thepipe[0]);
			execlp ( av[3], av[3], NULL);
			
			oops(av[3], 5);
		}
	}

	/* child execs av[1] and writes into pipe */
	else{
		close( thepipe[0] );		/* child doesn't read from pipe	*/
		if ( dup2(thepipe[1], 1) == -1 )
			oops("could not redirect stdout", 4);

		close(thepipe[1]);		/* stdout is duped, close pipe	*/
		execlp ( av[1], av[1], NULL);
		oops(av[1], 5);
	}
}
