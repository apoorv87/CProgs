#include <stdio.h>

int compare(int a, int b)
{
    if (a <= b)
        return 1;
    else
        return 0;
}


void insertion_sort(int *a, int (*comp)(int a, int b))
{
    int i,j, temp;
    for (j=1; j<6; j++)
    {
        i = j-1;
        temp = a[j];
        while( (comp(temp, a[i])) && (i >= 0)  )
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = temp;
    }
}

int main()
{
    int arr[6] = {8, 5, -6, 2, 4, 1};
    int i;
    printf("original array\n");
    for (i = 0; i<6; i++)
    {
        printf("\t%d", arr[i]);
    }
    insertion_sort(arr, compare); 
    printf("\nSorted Array: ");
    for (i = 0; i<6; i++)
    {
        printf("\t%d", arr[i]);
    }
}



