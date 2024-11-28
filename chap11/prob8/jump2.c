#include<stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>

void p1();
void inthandler();
jmp_buf env;

int main()
{
	signal(SIGINT,inthandler);
	if(setjmp(env) != 0)
	{
		printf("Return due to interrupt\n");
		exit(0);
	}
	else printf("Frist pass\n");
	p1();


}

void p1()
{
	while (1)
 	{
		printf("Loop\n");
		sleep(1);
	}
}
 void inthandler()
 {
 	printf("Interrupt\n");
	longjmp(env,1);
 }
