#include <stdio.h>

int main()
{
    FILE *fp;
    char msg1[10], msg2[10];
    fp = fopen("test.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Invalid File Pointer");
    }
    while (fscanf(fp, "%s %s", msg1, msg2) != EOF)
    {
        printf("\n%s\t%s", msg1, msg2);
    }
}
