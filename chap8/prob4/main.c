#include <stdio.h>
#include <stdlib.h>
static void exit_handler1(void), exit_handler2(void);

int main(int argc, char *argv[])

{
	if(atexit(exit_handler1) != 0)
		perror("exit_handler1 can't register\n");
	if(atexit(exit_handler2) != 0)
		perror("exit_handler2 can't register\n");
	printf("main finish\n");

	exit(0);
}

static void exit_handler1(void)
{
	printf("first exit\n");
}
static void exit_handler2(void)
{
	printf("second exit\n");
}
