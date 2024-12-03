#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo) 
{
    static int count = 1;
    if (count <= 4) 
    {
        printf("%d second\n", count++);
        alarm(1);
    } 
    else 
    {
        printf("Wake up!\n");
        exit(0);
    }
}


void sig2(int signo, void (*func)(int)) 
{
    struct sigaction act;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (sigaction(signo, &act, NULL) == -1) 
    {
        perror("sigaction error");
        exit(1);
    }
}

int main() 
{
    sig2(SIGALRM, handler);
    
    alarm(1);


    while (1) 
    {
        pause();
    }

    return 0;
}

