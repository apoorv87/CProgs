#include<stdio.h>

int main()
{
    int arr[6] = {5, -6, 4, -2, -3, -9};
    int max_so_far = 0;
    int max_ending_here = 0;
    int index;
    
    for(index =0; index < 6; index++)
    {
        if ((max_ending_here + arr[index]) < 0)
        {
            max_ending_here = 0;
        }
        else
        {
            max_ending_here = max_ending_here + arr[index];
        }
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }
    printf("Max sum = %d", max_so_far);
}
