#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    int marks;
    char name[50];
    struct Student *next;
};

void llTraversal(struct Student *ptr)
{
    printf("The details of students are\n");
    printf("------------------------------------\n");
    while (ptr != NULL)
    {
        printf("Roll Number: %d\n", ptr->roll);
        printf("Name: %s\n", ptr->name);
        printf("Marks: %d\n", ptr->marks);
        printf("------------------------------------\n");

        ptr = ptr->next;
    }
}

int main()
{
    struct Student *head = NULL;
    struct Student *current = NULL;
    int n;

    printf("Enter the number of students: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));

        printf("Enter the roll number of the student: ");
        scanf("%d", &newStudent->roll);

        printf("Enter the name of the student: ");
        scanf("%s", newStudent->name);

        printf("Enter the marks of the student: ");
        scanf("%d", &newStudent->marks);

        newStudent->next = NULL;

        if (head == NULL)
        {
            head = newStudent;
            current = newStudent;
        }
        else
        {
            current->next = newStudent;
            current = newStudent;
        }
    }
    llTraversal(head);

    // Freeing the allocated memory
    struct Student *curren = head;
    while (curren != NULL)
    {
        struct Student *temp = curren;
        curren = curren->next;
        free(temp);
    }

    return 0;
}
