#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size; 
    int *ptr;
};

void createArray(struct myArray* a, int tSize, int uSize){
    // (*a).total_ize=tSize;
    // (*a).used_size=uSize;
    // (*a).ptr=(int *) malloc(tSize*sizeof(int)); 
    
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *) malloc(tSize * sizeof(int)); 
}

void show(struct myArray *a){
    printf("We are running show now\n");
    for(int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

void setVal(struct myArray *a){
    printf("We are running setVal now\n");
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &(a->ptr)[i]);
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    setVal(&marks);
    show(&marks);

    free(marks.ptr); // Don't forget to free the memory allocated by malloc
    return 0;
}
    
    
    
    

