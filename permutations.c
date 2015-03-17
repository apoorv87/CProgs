#include <stdio.h>

void swap1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printPerm(int *arr, int start, int len)
{
    int i;
    if (start == len)
    {
        printf("\n");
        for(i=0; i<=len; i++)
        {
            printf("%d", arr[i]);
        }
    } else
    {
        for (i=start; i<=len; i++)
        {
            swap1(arr+start, arr+i);
            printPerm(arr, start+1, len);
            swap1(arr+start, arr+i);
        }
    }
}

int main()
{
    int arr[4] = {3, 4, 1, 2};
    printPerm(arr, 0, 3);

}



