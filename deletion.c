#include<stdio.h>

void display(int arr[], int n){
    //code for traversal
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
    void indDeletion(int arr[], int size, int element, int index) {
        //code for deletion
        for(int i=index; i<=size-1; i++ )
        {
            arr[i]=arr[i+1]; 
        }
    }


int main(){
    int arr[100]={7, 8, 12, 27, 88};
    int size=5, element=45, index=4;
    size=size-1;
    indDeletion(arr, size, element, index);
    display(arr, size);
    return 0;
}