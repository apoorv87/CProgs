#include <stdio.h>
int main()
{
    int i;
    for (i=0; i<100000; i++)
    {
        if ((i%10)==0)
        {
            printf("\n%d", i);
        }
        else
        {
            printf(" %d", i);
        }
    }

}


























