//author : 2018115425 권오민
//datetime : 21-11-11 20:42

#include	<stdio.h>
#include	<string.h>
#include	"smsh.h"


enum states	{ NEUTRAL, WANT_THEN, THEN_BLOCK, WANT_ELSE, ELSE_BLOCK };
//else를 체크해주기 위해서 want_else와 else_block를 추가했습니다.
enum results	{ SUCCESS, FAIL };

static int if_state	= NEUTRAL;
static int if_state2 = NEUTRAL;
static int if_result	= SUCCESS;
static int last_stat	= 0;

int	syn_err(char *);

int ok_to_execute()
{
	int	rv = 1; 	/* default is positive */
	
	//if_state2를 추가하여서 그게 then_block인지 else_block인지 판단하고
	//if_result와 함께 조건을 이루어서 출력할지 말지 결정합니다.
	if( if_state == WANT_THEN && if_state2 == NEUTRAL) {
		syn_err("then expected");
		rv = 0;
	}
	else if ( if_state2 == THEN_BLOCK && if_result == SUCCESS )
	{
		rv = 1;
		//printf("if_state=THEN_BLOCK  if_result=SUCCESS.\n");
	}
	else if ( if_state2 == THEN_BLOCK && if_result == FAIL )
	{
		rv = 0; 
		//printf("if_state=WANT_THEN  if_result=SUCCESS.\n");
	}
	else if ( if_state2 == ELSE_BLOCK && if_result == SUCCESS )
	{
		rv = 0; 
		//printf("if_state=WANT_ELSE  if_result=SUCCESS\n");
	}
	else if ( if_state2 == ELSE_BLOCK && if_result == FAIL )
	{
		rv = 1; 
		//printf("if_state=ELSE_BLOCK  if_result=FAIL\n");
	}
	return rv;
}

int is_control_command(char *s)
/*
 * purpose: boolean to report if the command is a shell control command
 * returns: 0 or 1
 */
{
	return (strcmp(s, "if") == 0 || strcmp(s, "then") == 0 || 
					strcmp(s, "fi") == 0 || 
					strcmp(s, "else") == 0);
	//else일 경우를 추가..
}

int do_control_command(char **args)
/*
 * purpose: Process "if", "then", "fi" - change state or detect error
 * returns: 0 if ok, -1 for syntax error
 */
{
	//기본적으로 if_state는 그대로 두고
	//if_state2를 추가하여서 then으로 가면 then_block으로
	//else로 가면 else_block으로 바꾸어 줍니다.
	//그 후에 판단하도록 수정하였습니다.
	//그 이유는 else then이 반복해서 나올수도 있기 때문입니다.
	char	*cmd = args[0];
	int	rv = -1;

	if( strcmp(cmd, "if") == 0) {
		if( if_state != NEUTRAL )
			rv = syn_err( "if unexpected");
		else {
			last_stat = process( args + 1 );
			if_result = ( last_stat == 0 ? SUCCESS : FAIL );
			
			if(if_result == SUCCESS)
				if_state = WANT_THEN;
			else
				if_state = WANT_ELSE;
			rv = 0;
		}
	}
	else if( strcmp( cmd, "then" ) == 0 ) {
		if( if_state != WANT_THEN && if_state != WANT_ELSE)
			rv = syn_err( "then unexpected");
		else {
			if_state2 = THEN_BLOCK;
			rv = 0;
		}
	}
	else if( strcmp( cmd, "else" ) == 0 ) {
		if( if_state != WANT_ELSE && if_state != WANT_THEN)
			rv = syn_err( "else unexpected");
		else {
			if_state2 = ELSE_BLOCK;
			rv = 0;
		}
	}
	else if( strcmp(cmd, "fi" ) == 0 ) {
		if ( if_state2 != THEN_BLOCK && if_state2 != ELSE_BLOCK)
			rv = syn_err( "fi unexpected" );
		else {
			if_state = NEUTRAL;
			if_state2 = NEUTRAL;
			rv = 0;
		}
	}
	else
		fatal( "internal error processing:", cmd, 2);
	return rv;
}

int syn_err(char *msg)
/* purpose: handles syntax errors in control structures
 * details: resets state to NEUTRAL
 * returns: -1 in interractive mode. Should call fatal in scripts
 */
{
	if_state = NEUTRAL;
	fprintf(stderr, "syntax error: %s\n", msg);
	return -1;
}

