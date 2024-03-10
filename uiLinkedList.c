#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    int marks;
    char name[50];
    struct Node *next;
};

void llTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Name: %s\n", ptr->name);
        printf("Roll Number: %d\n", ptr->roll);
        printf("Marks: %d\n", ptr->marks);
        printf("----------------------------------------\n");
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *current = NULL;

    int n;
    printf("Enter the no. of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct Node *newStudent = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the name of the student: ");
        scanf("%s", newStudent->name);

        printf("Enter the roll number of the student: ");
        scanf("%d", &newStudent->roll);

        printf("Enter the marks of the student: ");
        scanf("%d", &newStudent->marks);

        newStudent->next=NULL;

       if(head==NULL)
       {
        head=newStudent;
        current=newStudent;
       }
       else
       {
        current->next=newStudent;
        current=newStudent;
       }
    }
    llTraversal(head);
    return 0;
}