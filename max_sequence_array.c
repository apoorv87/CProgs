#include <stdio.h>

int main()
{
    int a[10] = {2, -5, 7, 4, -8, 3, 9, 6, 1, 20};
    int i, max_curr=0, max_sum = 0, start = 0, end=0, tempstart = 0;
    for (i=0; i<10; i++)
    {
        max_curr = max_curr + a[i];
       
        if (max_curr > max_sum)
        {
            max_sum = max_curr;
            if ((i - tempstart) > (end - start))
            {
                start = tempstart;
                end = i;
            }
        }
        else if (max_curr < 0)
        {
            max_curr = 0;
            tempstart = i+1;
        }
    }
    printf("max sum: %d   start idnex %d    end index %d", max_sum, start, end);
}






