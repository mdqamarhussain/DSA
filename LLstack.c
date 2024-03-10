#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void llTraversal(struct Node *top)
{
    struct Node *to = top;
    while (to != NULL)
    {
        printf("Element: %d\n", to->data);
        to = to->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        free(ptr);
        return 0;
    }
}

struct Node *push(struct Node *top, int val)
{
    if (isFull(top))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    return top;
}

int pop(struct Node *tp)
{
    if (isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = tp;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    int choice, val, popped, size;

    // printf("Enter the size of the stack: ");
    // scanf("%d", &size);

    // for (int i = 0; i < size; i++)
    // {
    //     printf("Enter element %d to be inserted in the stack: ", i + 1);
    //     scanf("%d", &val);
    
    //     top = push(top, val);
    // }

    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &val);
            top = push(top, val);
            break;
        case 2:
            popped = pop(top);
            if (popped != -1)
                printf("Popped value is %d\n", popped);
            break;
        case 3:
            printf("Stack elements:\n");
            llTraversal(top);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
