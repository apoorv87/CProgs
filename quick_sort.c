#include <stdio.h>

int partiton(int *a, int lindex, int uindex);
void quicksort(int *a, int lindex, int uindex);
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int index;
    //printf("%d", (sizeof(arr)/sizeof(int)));
    quicksort(arr, 0, 4);
    //printf("\n");
    for (index = 0; index < 5; index++)
    {
        printf("\t%d", arr[index]);
    }
}

void quicksort(int *a, int lindex, int uindex)
{
    int p;
    if (uindex > lindex)
    {
        p = partition(a, lindex, uindex);
        quicksort(a, lindex, p-1);
        quicksort(a, p + 1, uindex);
    }
}

int partition(int *a, int lindex, int uindex)
{
    int pivot = (lindex + uindex)/2, temp;
    int i = lindex;
    int j = uindex;
    
    while(i < j)
    {
        while ((a[i] <= a[pivot]) && (i < uindex))
            i++;
        while (a[j] > a[pivot])
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    //swap a[j] with a[pivot]
    temp = a[pivot];
    a[pivot] = a[j];
    a[j] = temp;
    return j;
}














