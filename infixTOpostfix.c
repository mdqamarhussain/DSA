#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    char data;
    struct Stack *next;
};

struct Stack *top = NULL;

int isEmpty(struct Stack *top)
{
    return (top == NULL);
}

int isFull(struct Stack *top)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    return (sp == NULL);
}

char stackTop(struct Stack *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
        return '\0';
    }
    return top->data;
}

struct Stack *push(struct Stack *top, char exp)
{
    struct Stack *newData = (struct Stack *)malloc(sizeof(struct Stack));
    newData->data = exp;
    newData->next = top;
    top = newData;
    return top;
}

char pop(struct Stack **tp)
{
    if (isEmpty(*tp))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    struct Stack *n = *tp;
    *tp = (*tp)->next;
    char val = n->data;
    free(n);
    return val;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '^')
        return 1;
    return 0;
}

int precedence(char ch)
{
    if (ch == '(' || ch == ')')
        return 4;
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

char *infixTOpostfix(char *infix)
{
    struct Stack *sp = NULL;
    char *postFix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postFix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (!isEmpty(sp) && precedence(infix[i]) > precedence(stackTop(sp)))
            {
                sp = push(sp, infix[i]);
                i++;
            }
            else
            {
                while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp)))
                {
                    postFix[j] = pop(&sp);
                    j++;
                }
                sp = push(sp, infix[i]);
                i++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postFix[j] = pop(&sp);
        j++;
    }
    postFix[j] = '\0';
    return postFix;
}

int main()
{
    char infix[100];
    printf("Enter an Infix expression: ");
    scanf("%s", infix);

    char *postfix = infixTOpostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    free(postfix);

    return 0;
}
