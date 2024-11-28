#include <stdio.h>
#include <signal.h>
#include <signal.h>
void inthandler();

int main()
{
	signal(SIGINT,inthandler);

	while(1)
		pause();		
	printf("End\n");
	
}
void inthandler(int signo)
{
	printf("Inturrupt signal\n");
	printf("signal number : %d\n", signo);
	exit(0);
}

