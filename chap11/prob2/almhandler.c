#include <stdio.h>
#include <signal.h>
void alarmhandler();
int main()
{
	signal(SIGALRM,alarmhandler);

	alarm(5);
	short i = 0;
	while(1)
	{
		sleep(1);
		i++;
		printf("%d second\n",i);
	}
	printf("End\n");
	
}
void alarmhandler(int signo)
{
	printf("Wake Up\n");
	exit(0);
}

