#include <stdio.h>

void printsubset(int arr[], int data[], int start, int end, int size, int index);

int main()
{
    int size = 3;
    int arr[5] = {4, 1, 6, 3, 5};    
    int data[size];
    printsubset(arr, data, 0, 4, 3, 0);
}

void printsubset(int arr[], int data[], int start, int end, int size, int index)
{
    int i;
    if (index == size)
    {
        printf("\nSubset:");
        for (i=0; i<size; i++)
        {
            printf("%d", data[i]);
        }
    }
    for (i=start; ((i <= end) && ((end-i+1) >= (size-index))); i++)
    {
        data[index] = arr[i];
        printsubset(arr, data, i+1, end, size, index+1);
    }    
}
























