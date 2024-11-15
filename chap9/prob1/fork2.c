#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid;
	pid = fork();
	if(pid ==0)
	{
		printf("[Child] : Hello world pid = %d\n", getpid());
	}
	else
	{
		printf("[parent] : hello world pid = %d\n", getpid());
	}
}
