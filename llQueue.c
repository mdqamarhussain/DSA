#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *f)
{
    return (f == NULL);
}

int isFull(struct Node *q)
{
    struct Node *n;
    return (n == NULL);
}

void enque(int element)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(newNode))
    {
        printf("The queue is empty!\n");
    }
    else
    {
        newNode->data = element;
        newNode->next = NULL;
        if (f == NULL)
        {
            f = r = newNode;
        }
        else
        {
            r->next = newNode;
            r = newNode;
        }
    }
}

int deque()
{
    int val = -1;
    struct Node *ptr = f;
    if (isEmpty(f))
    {
        printf("The queue is Empty");
    }
    else
    {
        f = f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    int element, ch;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("ENTER YOUR CHOICE!\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter an element to enqueue: ");
            scanf("%d", &element);
            enque(element);
            break;
        case 2:
            printf("Dequeued element: %d\n", deque());
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
