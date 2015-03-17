#include <stdio.h>

void buildheap(int *arr, int len);
void heapify(int *arr, int index, int len);
void heapsort(int *arr, int len);

int main()
{
    int arr[8] = {9, 4, 2, -4, 3, 5, 6, 1};
    int i;
    for (i=0; i<8; i++)
    {
        printf("\t%d", arr[i]);
    }
    buildheap(arr, 8);
    printf("\n");
    for (i=0; i<8; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    heapsort(arr, 8);
    for (i=0; i<8; i++)
    {
        printf("\t%d", arr[i]);
    }
}

void buildheap(int *arr, int len)
{
    int start = (len/2) - 1;
    int i;
    for (i=start; i >= 0; i--)
    {
        heapify(arr, i, len);
    }
}

void heapify(int *arr, int index, int len)
{
    int largest, left, right, temp;
    
    left = 2*index + 1;
    right = 2*index + 2;
    
    if ((left < len) && (arr[index] < arr[left]))
    {
        largest = left;
    }
    else
    {
        largest = index;
    }

    if ((right < len) && (arr[right] > arr[largest]))
    {
        largest = right;
    }
    
    if (largest != index)
    {
        temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;
        heapify(arr, largest, len);
    }
}

void heapsort(int *arr, int len)
{
    int temp, i;
    for (i = (len-1); i>=1; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, 0, i);    
    }    
}

