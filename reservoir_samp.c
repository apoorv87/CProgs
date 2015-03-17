#include <stdio.h>

int main()
{
   int src[5] = {1, 2, 3, 4, 5};
   int k=3, i, j;
   int res[3];
   for (i=0;i<3;i++)
   {
      res[i] = src[i];
   }

   printf("\n");
    for (i=0;i<3; i++)
    {
        printf("\t%d", res[i]);
    }
   for (i=k; i < 5; i++)
   {
        j = (rand()%i);
        if (j<k)
        {
            res[j] = src[i];
        }
   }
   printf("\n");
    for (i=0;i<3; i++)
    {
        printf("\t%d", res[i]);
    }


}
