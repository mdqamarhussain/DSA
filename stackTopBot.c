#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

int isEmpty(struct Stack *ptr)
{
    return ptr->top == -1;
}

int push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to stack\n", val);
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return val;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *sp, int i)
{
    int arrInd = sp->top - i + 1;
    if (arrInd < 0)
    {
        printf("Not a valid position!\n");
        return -1;
    }
    else
    {
        return sp->arr[arrInd];
    }
}

int stackTop(struct Stack *sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct Stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));

    printf("Enter the size of the stack: ");
    scanf("%d", &sp->size);

    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    int choice, val, element, j;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Topmost\n");
        printf("5. Bottommost\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &val);
            if (push(sp, val) != -1)
            {
                printf("Pushed %d to the stack\n", val);
            }
            break;
        case 2:
            val = pop(sp);
            if (val != -1)
            {
                printf("Popped %d from the stack\n", val);
            }
            break;
        case 3:
            printf("Enter the position to be peeked: ");
            scanf("%d", &j);
            element = peek(sp, j);
            printf("The value at position %d is %d\n", j, element);
            break;
        case 4:
            printf("Topmost element of the stack is %d\n", stackTop(sp));
            break;
        case 5:
            printf("Bottommost element of the stack is %d\n", stackBottom(sp));
            break;
        case 6:
            free(sp->arr);
            free(sp);
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
