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

int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;
    for (int i = 0; i < (pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop()
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *ptr = top;
    struct Node *bottom = NULL;

    while (ptr != NULL)
    {
        bottom=ptr;
        ptr = ptr->next;
    }
    return bottom->data;
}

int main()
{
    int choice, val, popped, size, pos, element;

    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek Stack\n");
        printf("4. Topmost\n");
        printf("5. Bottommost\n");
        printf("6. Display Stack\n");
        printf("7. Exit\n");
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
            printf("Enter the position to peek: ");
            scanf("%d", &pos);
            element = peek(top, pos);
            printf("The value at position %d is %d\n", pos, element);
            break;
        case 4:
            printf("Topmost element of the stack is %d\n", stackTop(top));
            break;
        case 5:
            printf("Bottommost element of the stack is %d\n", stackBottom(top));
            break;
        case 6:
            printf("Stack elements:\n");
            llTraversal(top);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
