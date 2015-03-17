#include <stdio.h>

#define SIZE 4

int rear = -1, front =-1;

void insert(int *a, int elem)
{
    if (((rear == (SIZE-1)) && (front == 0)) || ((rear +1) == front))
    {
        printf("queue is full\n");
    }
    else
    {
        if (rear == (SIZE-1))
            rear = 0;
        else
            rear++;
        a[rear] = elem;
    }
    if (front == -1)
        front = 0;
}

int delete(int *a)
{
    int elem;
    if (front == -1) 
        printf("queue is empty\n");
    else
    {
        elem = a[front];
        if (front == (SIZE-1))
            front = 0;
        else {
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
        }
        return elem;
    }    
}

int main()
{
    int arr[4], n;
    
    insert(arr, 5);
    insert(arr, -2);
    insert(arr, 7);
    insert(arr, 8);
    insert(arr, 8);

    n = delete(arr);
    printf("last element extracted: %d", n);

    n = delete(arr);
    printf("last element extracted: %d", n);

    n = delete(arr);
    
    printf("last element extracted: %d", n);
    n = delete(arr);

    printf("last element extracted: %d", n);
    n = delete(arr);

    printf("last element extracted: %d", n);

}




