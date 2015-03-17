#include <stdio.h>

#define SIZE 6

void insert(int arr[], int *enqueue, int *dequeue, int item, int *count)
{
    if (*count < SIZE)
    {
        arr[*enqueue] = item;
        *enqueue = (*enqueue + 1) % SIZE;    
        (*count)++;
    }
    else
    {
        printf("\nQueue is full");
    }
}

int delete(int arr[], int *enqueue, int *dequeue, int *count)
{
    int val;
    if (*count != 0)
    {
        val = arr[*dequeue]; 
        *dequeue = (*dequeue + 1)%SIZE;
        (*count)--;
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
    int enqueue = 0, dequeue = 0, count =0, val;
    insert(arr, &enqueue, &dequeue, 5, &count);
    insert(arr, &enqueue, &dequeue, 6, &count);
    insert(arr, &enqueue, &dequeue, 7, &count);
    insert(arr, &enqueue, &dequeue, 8, &count);
    insert(arr, &enqueue, &dequeue, 9, &count);
    insert(arr, &enqueue, &dequeue, 10, &count);
    insert(arr, &enqueue, &dequeue, 11, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    val = delete(arr, &enqueue, &dequeue, &count);
    printf("\nCount: %d", count);
}




