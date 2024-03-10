#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head=NULL;
    struct Node *current=NULL;

    int n;

    printf("Enter the numbers of element of linked list: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        struct Node *newNode;
        newNode= (struct Node *)malloc(sizeof(struct Node));
        int value;

        printf("Enter the value for element %d: ", i+1);
        scanf("%d", &newNode->data);

        newNode->next= NULL; 

        if(head==NULL)
        {
            head=newNode;
            current=newNode;
        }
        else{
            current->next = newNode;
            current = newNode;
        }
    }
    linkedListTraversal(head);

    // Freeing the allocated memory
    struct Node *curren = head;
    while (curren != NULL)
    {
        struct Node *temp = curren;
        curren = curren->next;
        free(temp);
    }
    return 0;
}









