#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[])

{
	printf("my process number : [%d] \n", getpid());
	printf("my parents process number : [%d] \n",getppid());
}
/*
static void exit_handler1(void)
{
	printf("first exit\n");
}
static void exit_handler2(void)
{
	printf("second exit\n");
}*/
