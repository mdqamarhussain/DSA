#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void dllTraversal(struct Node *head, struct Node *tail)
{
    printf("Traversal in forward direction!\n");
    while(head!=NULL)
    {
        printf("Element: %d\n", head->data);
        head=head->next;
    }
    printf("Traversal in backward direction!\n");
    while(tail!=NULL)
    {
        printf("Element: %d\n", tail->data);
        tail=tail->prev;
    }
}

int main()
{
    struct Node *head=NULL;
    struct Node *tail=NULL;

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        struct Node *newData=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newData->data);
        newData->next=NULL;
        newData->prev=NULL;

        if(head==NULL)
        {
            head=newData;
            tail=newData;
        }
        else
        {
            newData->prev=tail;
            tail->next=newData;
            tail=newData;
        }
    }
    dllTraversal(head,tail);
}