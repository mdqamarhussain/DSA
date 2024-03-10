#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void llTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;

    int n,i;
    printf("Enter the number of data: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct Node *newData = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d", &newData->data);
        newData->next = NULL;

        if (head == NULL)
        {
            head = newData;
            current = newData;
        }
        else
        {
            current->next = newData;
            current = newData;
        }
        current->next = head;
    }
    llTraversal(head);
    return 0;
}
