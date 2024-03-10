#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(struct Stack *ptr,int val)
{
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to stack\n", val);
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
        return val;
    }
}

int pop(struct Stack *ptr)
{
    if(isEmpty(ptr)){
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int val;
        val=ptr->arr[ptr->top];
        ptr->top--;
        return val;;
    }
}

int main()
{
    struct Stack *sp=(struct Stack*)malloc(sizeof(struct Stack));
    sp->size=8;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));

    printf("Pushed %d to the stack\n", push(sp, 1));
    printf("Pushed %d to the stack\n", push(sp, 2));
    printf("Pushed %d to the stack\n", push(sp, 3));
    printf("Pushed %d to the stack\n", push(sp, 4));
    printf("Pushed %d to the stack\n", push(sp, 5));
    printf("Pushed %d to the stack\n", push(sp, 6));
    printf("Pushed %d to the stack\n", push(sp, 7));

    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));




    return 0;
}