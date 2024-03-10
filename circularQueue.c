#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct circularQueue *q)
{
    if ((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

void enque(struct circularQueue *q, int element)
{
    if (isFull(q))
    {
        printf("The queue is full!\n");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = element;
        printf("Enqued element: %d\n", element);
    }
}

int deque(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty!\n");
        return -1;
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
}

int main()
{
    struct circularQueue q;
    int element, ch;
    q.size = 5;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));
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
            enque(&q, element);
            break;
        case 2:
            printf("Dequeued element: %d\n", deque(&q));
            break;
        case 3:
            free(q.arr); // Free the allocated memory before exiting
            exit(0);
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}