#include <stdio.h>

int main()
{
    int a[8] = {-3, -2, 1, 4, 5, 6, 8, 10};
    int search = 6, imin = 0, imax = 7, mid, found = 0;
    while (imax >= imin)
    {
        mid = (imin + imax)/2;
        if (a[mid] == search)
        {
            found = 1;
            break;
        }
        else if (search < a[mid])
        {
            imax = mid-1;    
        }
        else if (search > a[mid])
        {
            imin = mid+1;
        }
    }
    if (found)
    {
        printf("Element Found at index: %d", mid);
    }
    else
    {
        printf("Element Not Found");
    }
}
























