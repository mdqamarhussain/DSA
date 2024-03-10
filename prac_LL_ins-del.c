#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Declare head globally
struct Node *head = NULL;

struct Node *insert(struct Node *ptr)
{
    struct Node *insertNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &insertNode->data);

    insertNode->next = head;
    head = insertNode;
    return head;
}

struct Node *deleteNode(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = p->next;

    if (p->data == value)
    {
        head = p->next;
        free(p);
        return head;
    }

    while (q != NULL && q->data != value)
    {
        p = p->next;
        q = q->next;
    }

    if (q != NULL)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("Value not found!\n");
    }

    return head;
}

void LLTraversal(struct Node *ptr)
{
    printf("---------------------------\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("---------------------------\n");
}

int main()
{
    int n;

    struct Node *curr = NULL;

    int s;
    printf("Enter the no. of data you want to insert: ");
    scanf("%d", &s);

    for (int i = 0; i < s; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            curr = newNode;
        }
        else
        {
            curr->next = newNode;
            curr = newNode;
        }
    }

    do
    {
        printf("1. Insert a data\n");
        printf("2. Delete a element\n");
        printf("3. Display the elements\n");
        printf("4. Exit\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            head = insert(head);
            LLTraversal(head);
            break;
        case 2:
        {
            int value;
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            head = deleteNode(head, value);
            LLTraversal(head);
        }
        break;

        case 3:
            LLTraversal(head);
            break;
        case 4:
            printf("Exiting.........!\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    } while (n != 4);

    printf("Thank You!\n");

    return 0;
}
