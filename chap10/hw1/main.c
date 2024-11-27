#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node 
{
    int data;
    struct node *next;
};

void push(struct node **top, int data) 
{
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    if (node2 == NULL) 
    {
        printf("Fail.\n");
        return;
    }
    node2->data = data;
    node2->next = *top;
    *top = node2;
}

int pop(struct node **top) 
{
    if (*top == NULL) 
    {
        printf("empty stack.\n");
        return -1;
    }
    struct node *temp = *top;
    int popdata = temp->data;
    *top = temp->next;
    free(temp);
    return popdata;
}

void printStack(struct node *top) 
{
    struct node *nowi = top;
    while (nowi != NULL) 
    {
        printf("%d\n", nowi->data);
        nowi = nowi->next;
    }
}

int main() 
{
    struct node *stack = NULL;
    char input[100];

    while(1) 
    {
        scanf("%s", input);

        char *end;
        double number = strtod(input, &end);

        if (*end == '\0' && (int)number == number && number > 0) 
        {
            push(&stack, (int)number);
        } 
        else 
        {
            printf("Print stack\n");
            printStack(stack);
            return 0;
        }
    }
    return 0;
}

