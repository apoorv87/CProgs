#include <stdio.h>

#define SIZE 6

void insert(int arr[], int *enqueue, int *dequeue, int item)
{
    if (((*enqueue + 1)%SIZE) != *dequeue)
    {
        arr[*enqueue] = item;
        *enqueue = (*enqueue + 1)%SIZE;
    }
    else
    {
        printf("Qeueue is full");
    }
}

int delete(int arr[], int *enqueue, int *dequeue)
{
    int val;
    if (*enqueue != *dequeue)
    {
        val = arr[*dequeue]; 
        *dequeue = (*dequeue + 1)%SIZE;
        return val;
    }
    else
    {
        printf("Qeueue is empty");
    }
}

int main()
{
    int arr[SIZE];
    int enqueue = 0, dequeue = 0, val;
    insert(arr, &enqueue, &dequeue, 5);
    insert(arr, &enqueue, &dequeue, 6);
    insert(arr, &enqueue, &dequeue, 7);
    insert(arr, &enqueue, &dequeue, 8);
    insert(arr, &enqueue, &dequeue, 9);
    insert(arr, &enqueue, &dequeue, 10);
    insert(arr, &enqueue, &dequeue, 11);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
    val = delete(arr, &enqueue, &dequeue);
}




