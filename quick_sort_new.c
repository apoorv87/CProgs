#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int lindex, int rindex)
{
   int pivot, i=lindex ,j = rindex, temp;
   pivot = rindex;
   while(i < j)
   {
       while((a[i] <= a[pivot]) && (i <rindex)) 
       {
           i++;
       } 
       while(a[j] > a[pivot])
       {
           j--;
       }
       if (i < j)
       {
          temp = a[i];
          a[i] = a[j];
          a[j] = temp;
       }
   }  
   temp = a[pivot];
   a[pivot] = a[j];
   a[j] = temp;
   return j;  
}

int quicksort(int *a, int lindex, int rindex)
{
    int p;
    printf("\nhello %d\t%d\n", lindex, rindex);
    if (lindex < rindex)
    {
        p = partition(a, lindex, rindex);
        printf("\npivot: %d", p);
        quicksort(a, lindex, p-1);
        quicksort(a, p+1, rindex);
    }
}

int main()
{
    int a[8] = {-1, 3, 5, 2, -4, 6, 9, -4};
    int lindex, rindex, i;
    lindex = 0; 
    rindex = 7;
    quicksort(a, lindex, rindex);
    for(i=0; i<8; i++)
    {
        printf("\t%d", a[i]);
    }
}








