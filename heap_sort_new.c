#include <stdio.h>


void heapify(int *a, int size, int index)
{
    int largest = index, left, right, temp;
    left = (index * 2) + 1;
    right = (index * 2) + 2;
    if ((left <= (size-1)) && (a[left] > a[index]))
    {
        largest = left;
    }
    if ((right <= (size-1)) && (a[right] > a[largest]))
    {
        largest = right;
    } 
    if (largest != index)
    {
        temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;
        heapify(a, size, largest);
    }   
}

void build_heap(int *a, int size)
{
    int i = (size/2) - 1;
    while(i>=0)
    {
        heapify(a, size, i);
        i--;
    }
}

void heapsort(int *a, int size)
{
    int i=size-1, temp;
    while(i >= 1)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
        i--;
    }
}

int main()
{
    int arr[9] = {-5, -8, -1, 98, 0, 45, 0, 7, -156};
    int i;
    build_heap(arr, 9);
    for(i=0;i<9;i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n");
    heapsort(arr, 9);
    for (i=0; i<9; i++)
    {
        printf("\t%d", arr[i]); 
    }
}




