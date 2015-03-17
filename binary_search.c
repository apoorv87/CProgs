#include <stdio.h>

int search(int *a, int elem, int lindex, int rindex)
{
    int mid = (lindex + rindex)/2;
    if (lindex > rindex)
    {
        return 0;
    }
    if (elem == a[mid])
    {
        return 1;
    }
    else if (elem < a[mid])
    {
        return search(a, elem, lindex, mid-1);
    }
    else if (elem > a[mid])
    {
        return search(a, elem, mid+1, rindex);
    }
}

int search1(int *a, int elem, int lindex, int rindex)
{
    int mid = lindex + (rindex - lindex)/2;
    if (lindex > rindex)
    {
        return 0;
    }
    if (elem == a[mid])
    {
        return mid;
    }
    else if (elem < a[mid])
    {
        return search1(a, elem, lindex, mid-1);
    }
    else if (elem > a[mid])
    {
        return search1(a, elem, mid+1, rindex);
    }
}

int rotSortedSearch(int *b, int l, int r, int elem)
{
    while(l < r)
    {
        int m = (l +  (r - l)/2);
        if ((b[l] <= b[m]) && (elem >= b[l]) && (elem <= b[m]))
            return search1(b, elem, l, m);
        else if ((b[m+1] <= b[r]) && (elem >= b[m+1]) && (elem <= b[r]))
            return search1(b, elem, m+1, r);
        else if (b[l] > b[m])
            return rotSortedSearch(b, l, m, elem);
        else if (b[m+1] > b[r])
            return rotSortedSearch(b, m+1, r, elem);
    }
}

int main()
{
    int a[6] = {3, 7, 10, 12, 14, 15};
    int b[6] = {10, 12, 14, 15, 3, 7};
    int val = 25, found = 0, diff, i, index = -1;

    for (i=0; i<6; i++)
    {
        diff = val - a[i];
        if (search(&a[i+1], diff, 0, (6-(i+2))))
        {   
            found = 1;
            break;
        }        
    }
    if (found)
        printf("Val found in sorted array %d", a[i]);
    else
        printf("val not found in sorted array");

    index = rotSortedSearch(b, 0, 5, 12);

    if (index)
    {
        printf("Element found at index: %d\n", index);
    }
}
