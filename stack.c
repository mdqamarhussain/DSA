#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size *sizeof(int));

    // pushing element manually
    s->arr[0] = 7;
    s->top++;

    if (isEmpty(s))
    {
        printf("The stack is empty!\n");
    }
    else
    {
        printf("The stack is not empty!\n");
    }
    if (isFull(s))
    {
        printf("The stack is full!");
    }
    else
    {
        printf("The stack is not full!");
    }
    return 0;
}