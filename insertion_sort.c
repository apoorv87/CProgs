#include <stdio.h>

typedef int (*callback)(int, int);

int descending(int a, int b)
{
    return (a < b);
}

void insertion_sort(int *a, int n, callback comparison)
{
    int key, j, i;
    for (j=1; j < n; j++)
    {
        i = j - 1;
        key = a[j];
        while ( comparison(a[i], key) && (i>=0))
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main()
{
    int a[8] = { 12, 4, 5, 9, 1, 6, 10, 2 } ;
    int j;
    insertion_sort(a, 8, descending);
        printf("Sorted Array\n");
    for (j=0; j<8; j++)
    {
        printf("  %d", a[j]);
    }
}



