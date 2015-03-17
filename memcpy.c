#include <stdio.h>
#include <stdlib.h>

void* mymemcpy(void *dst, const void *src, int nbytes)
{
    int i, overlap_start, overlap_end;
    char *dst8, *src8;
    dst8= (char *)dst;
    src8= (char *)src;
    char *temp1, *temp2;
    for (i=0; i < nbytes; i++)
    {
        if ((src8 + i) == dst8)
        {
            overlap_start = 1;
            break;
        }
         if ((src8 + i) == (dst8 + (nbytes - 1)))
        {
            overlap_end = 1;
            break;
        }
    }
    i = 0;
    if ((overlap_start) && !(overlap_end))
    {
        temp1 = src8 + (nbytes - 1);
        temp2 = dst8 + (nbytes - 1);
        while(i < nbytes)
        {
            *(temp2--) = *(temp1--);
            i++;
        }
    }
    else
    {
        while(i < nbytes)
        {
            *(dst8++) = *(src8++);
            i++;
        }
    }
}

int main()
{
    int *a = malloc(5*sizeof(int));
    int *c, *d;
    a[0] = 1;
    a[1] = 2;
    int *b = a;
//    printf("\n%d %d", a[0], a[1]);
    free(b);
//    printf("\n%d %d", a[0], a[1]);

    c =  malloc(4*sizeof(int));
    d = &(c[2]);
    c[0] = 4;
    c[1] = 1;
    c[2] = 2;
    c[3] = 3;
    mymemcpy((void *)d, (const void *)c, 4*sizeof(int));

    printf("\n\t%d\t%d\t%d\t%d", c[0], c[1], c[2], c[3]);
    printf("\n\t%d\t%d\t%d\t%d", d[0], d[1], d[2], d[3]);
}
