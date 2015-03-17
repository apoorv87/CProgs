#include <stdio.h>
#include <assert.h>

int merge(int *a, int lindex, int mid, int uindex);
void mergesort(int *a, int lindex, int uindex);
int main()
{
    int arr[5] = {2, 6, 3, 8, 1};
    int temp[5];
    int index;
    //printf("%d", (sizeof(arr)/sizeof(int)));
    mergesort(arr, 0, 4);
    //printf("\n");
    for (index = 0; index < 5; index++)
    {
        printf("\t%d", arr[index]);
    }
}

void mergesort(int *a, int lindex, int uindex)
{
    int mid;
    if (uindex > lindex)
    {
        mid = (lindex + uindex)/2;
        mergesort(a, lindex, mid);
        mergesort(a, mid + 1, uindex);
        merge(a, lindex, mid, uindex);
    }
}

int merge(int *a, int lindex, int mid, int uindex)
{
    int size = uindex - lindex + 1;
    int temp[size];
    int i,j,k;
    i = lindex;
    j = mid+1;
    k = 0;
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
    assert(k==size);
    k=lindex;
    for(i=0; i<size; i++)
        a[k++] = temp[i];

}

