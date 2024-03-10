#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack *top = NULL;

struct Stack
{
    char data;
    struct Stack *next;
};

int isEmpty(struct Stack *top)
{
    return (top == NULL);
}

int isFull(struct Stack *top)
{
    struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
    return (ptr == NULL);
}

struct Stack *push(struct Stack *top, char exp)
{
    if (isFull(top))
    {
        printf("Stack Overflow");
        return top;
    }
    else
    {
        struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
        newStack->data = exp;
        newStack->next = top;
        top = newStack;
        return top;
    }
}

char pop(struct Stack *tp)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow");
        return '\0';
    }
    else
    {
        struct Stack *newStack = tp;
        top = tp->next;
        int value = newStack->data;
        free(newStack);
        return value;
    }
}

int parenthesisMatch(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            top = push(top, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(top))
            {
                return 0;
            }
            char popped = pop(top);
            if (popped != '(')
            {
                return 0; // Mismatched parenthesis
            }
        }
    }
    return isEmpty(top); // If the stack is empty, all parentheses are matched
}

int main()
{
    char exp[100];
    printf("Enter the expression:  ");
    scanf("%s", exp);

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching!");
    }
    else
    {
        printf("The parenthesis is not matching!");
    }
    return 0;
}
