#include <stdio.h>

int main()
{
    FILE *fp;
    int temp, i=0;
    int nums[100000];
    if ((fp = fopen("numbers.txt", "r")) != NULL)
    {
        while ((fscanf(fp, "%d", &temp)) != EOF)
        {
            nums[i++] = temp;
        }
        printf("Number of elements read = %d", i);
    }
    fclose(fp);
}




