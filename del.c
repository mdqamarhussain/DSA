#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = p->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = p->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
    else
    { 
        printf("Value not found!\n");
        return head;
    }
}

void llTraversal(struct Node *ptr)
{
    printf("---------------------------\n");
    while (ptr != NULL)
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("---------------------------\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;

    int n;
    printf("Enter the number of data: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
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
    }
    printf("Before Deletion!\n");
    llTraversal(head);
    int ch, index, value;
    printf("Press 1 to delete a node from the beginning!\n");
    printf("Press 2 to delete a node at an index!\n");
    printf("Press 3 to delete a node from the last!\n");
    printf("Press 4 to delete a node of a value!\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        head = deleteAtBeginning(head);
        printf("After deletion!\n");
        llTraversal(head);
        break;
    case 2:
        printf("Enter the index at which you want to delete!\n");
        scanf("%d", &index);
        head = deleteAtIndex(head, index);
        printf("After deletion!\n");
        llTraversal(head);
        break;
    case 3:
        head = deleteAtLast(head);
        printf("After deletion!\n");
        llTraversal(head);
        break;
    case 4:
        printf("Enter the value you want to delete!\n");
        scanf("%d", &value);
        head = deleteAtValue(head, value);
        printf("After deletion!\n");
        llTraversal(head);
        break;
    default:
        printf("Invalid Choice!");
    }
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
