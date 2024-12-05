#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#define MAXLINE 100

void toUpperCase(char *str);

int main()
{
    int pipefd[2];
    pid_t pid1, pid2;
    char buffer[MAXLINE];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("parent process start\n");

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {
        close(pipefd[0]);
        printf("input string: ");
        fgets(buffer, MAXLINE, stdin);
        write(pipefd[1], buffer, strlen(buffer) + 1);
        close(pipefd[1]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0)
        {
            close(pipefd[1]);
            read(pipefd[0], buffer, MAXLINE);
            close(pipefd[0]);

            toUpperCase(buffer);
            printf("%s", buffer);
            exit(EXIT_SUCCESS);
        }
        else
        {
            close(pipefd[0]);
            close(pipefd[1]);
            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}

void toUpperCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

