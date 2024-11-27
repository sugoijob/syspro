#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) 
{
    struct node *node2 = (struct node *)malloc(sizeof(struct node));
    if (node2 == NULL) 
    {
        printf("Fail.\n");
        return;
    }
    node2->data = data;
    node2->next = NULL;

    if (*tail == NULL) 
    {
        *head = *tail = node2;
    } 
    else 
    {
        (*tail)->next = node2;
        *tail = node2;
    }
}

int delete(struct node **head, struct node **tail) 
{
    if (*head == NULL) 
    {
        printf("empty queue.\n");
        return -1;
    }
    struct node *temp = *head;
    int deldata = temp->data;
    *head = temp->next;
    if (*head == NULL) 
    {
        *tail = NULL;
    }
    free(temp);
    return deldata;
}

void printQueue(struct node *head) 
{
    struct node *nowi = head;
    while (nowi != NULL) 
    {
        printf("%d\n", nowi->data);
        nowi = nowi->next;
    }
}

int main() 
{
    struct node *head = NULL, *tail = NULL;
    char input[100];

    while (1) 
    {
        scanf("%s", input);

        char *end;
        double number = strtod(input, &end);

        if (*end == '\0' && (int)number == number && number > 0) 
        {
            addq(&head, &tail, (int)number);
        } 
        else 
        {
            printf("Print queue\n");
            printQueue(head);
            return 0;
        }
    }
    return 0;
}

