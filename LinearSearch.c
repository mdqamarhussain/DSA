#include<stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    //Unsorted Array for Linear Search
    int arr[]={1,2,5,56,4,3,23,5,4,546};
    
    int size=sizeof(arr)/sizeof(int);
    int element=544;
    int searchIndex=linearSearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
}