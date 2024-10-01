#include <stdio.h>
#include <string.h>
#include "copy.h"
#define linenum 5

char lines[linenum][MAXLINE];
void linefun(char lines[][MAXLINE], int a);

int main() 
{
    int i,j;
    
    for (i = 0; i < linenum; i++) 
    {
        scanf("%s", lines[i]);
    }


    linefun(lines, linenum);
    
    
    for (i = 0; i < linenum; i++) 
    {
        printf("%s\n", lines[i]);
    }

    return 0;
    
    
}

void linefun(char lines[][MAXLINE], int a) 
{
    char temp[MAXLINE];
    int i,j;
    
    for (i = 0; i < a - 1; i++) 
    {
        for (j = i + 1; j < a; j++) 
        {
            if (strlen(lines[i]) < strlen(lines[j])) 
            {
                copy(lines[i], temp);
                copy(lines[j], lines[i]);
                copy(temp, lines[j]);
            }
            
        }
    }
    
    
}
