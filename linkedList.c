#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void llTraversal(struct Node*ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = first;

    first->data = 10;
    first->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    llTraversal(head);

}