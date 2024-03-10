#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n)
{
    int temp, indexOfMin;
    for(int i=0; i<n-1; i++)
    {
        indexOfMin=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[indexOfMin])
            {
                indexOfMin=j;
            }
        }
        //swap arr[i] and indexofmin
        temp=arr[i];
        arr[i]=arr[indexOfMin];
        arr[indexOfMin]=temp;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n); 

    return 0;
}
