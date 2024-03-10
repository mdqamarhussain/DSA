#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int isSorted = 0; // Initialize isSorted inside the loop
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 1; // Set isSorted to 1 if a swap occurs
            }
        }
        if (!isSorted) // If no swaps occurred in this pass, the array is sorted
            return;
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

    int arr[n]; // Declare the array after getting n
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n); // Corrected the printf statement

    return 0;
}
