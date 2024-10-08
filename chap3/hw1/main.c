#include <stdio.h>
#include <string.h>
#include "copy.h"


char line[MAXLINE];
char jang[5][MAXLINE];
char temp[MAXLINE];


int main() 
{
    
    int i = 0;
    
    int j;

    while (i < 5 && gets(line) != NULL) 
    {
        copy(line, jang[i]);
        
        
         i++;
    }


    for (i = 0;i < 5; i++) 
    {
        for (j = i +1; j < 5;j++) 
        {
            if (strlen(jang[i]) < strlen(jang[j]) ) 
            {
                copy(jang[i], temp);
                copy(jang[j], jang[i]);
                copy(temp, jang[j]);
            }
            
        }
        
    }


    for (i = 0; i < 5;i++) 
    {
        printf("%s\n", jang[i]);
    }

    return 0;
    
    
    
    
}



