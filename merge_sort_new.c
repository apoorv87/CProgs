#include <stdio.h>

int merge(int *a, int lindex, int mid, int uindex)
{
    int i, j, k=0, size = (uindex - lindex + 1);
    int temp[size];
    i = lindex; 
    j = mid + 1;

    while((i <= mid) && (j <= uindex))
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=uindex)
    {
        temp[k++] = a[j++];
    }

    for (i=0; i<size; i++)
    {
        a[lindex++] = temp[i];
    }
}

void mergesort(int *a, int lindex, int rindex)
{
    int mid;
    printf("\nhello %d %d", lindex, rindex); 
    if (lindex < rindex)
    {
        mid = (lindex + rindex)/2;
        mergesort(a, lindex, mid);
        mergesort(a, mid+1, rindex);
        merge(a, lindex, mid, rindex);     
    }
    
}

int main()
{
    int arr[9] = {-9, -6, -34, 8, 4, 100, 320, -1001, -567};
    int i;
    mergesort(arr,  0, 8);
    for (i=0; i<=8; i++)
    {
        printf("\t%d", arr[i]);
    }

}
   


