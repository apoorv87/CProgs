#include <stdio.h>

int partiton(char *a, int lindex, int uindex);
void quicksort(char *a, int lindex, int uindex);
int main()
{
    char str[5] = {"hello"};
    int index, unique = 1;
    //printf("%d", (sizeof(arr)/sizeof(int)));
    quicksort(str, 0, 4);
    //printf("\n");
    printf("%s", str);
    for (index=0; str[index]!= '\0'; index++)
    {
        if (str[index+1] == str[index])
        {
            unique = 0;
            break;
        }
    }
    if (unique)
        printf("\n string is unique");
    else
        printf("\n string is not unique");
}

void quicksort(char *a, int lindex, int uindex)
{
    int p;
    if (uindex > lindex)
    {
        p = partition(a, lindex, uindex);
        quicksort(a, lindex, p-1);
        quicksort(a, p + 1, uindex);
    }
}

int partition(char *a, int lindex, int uindex)
{
    int pivot = (lindex + uindex)/2;
    char temp;
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














