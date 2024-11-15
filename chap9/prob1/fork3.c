#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid1, pid2;
	pid1 = fork();
	if(pid1 ==0)
	{
		printf("[Child 1] : Hello world pid = %d\n", getpid());
		exit(0);
	}
	pid2 = fork();
	if(pid2 == 0)
	{
		printf("[child 2] : hello world pid = %d\n", getpid());
		exit(0);
	}
	printf("[parent] : Hello world pid = %d\n", getpid());
}
