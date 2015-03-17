#include <stdio.h>

int main()
{
    int a, i;
    char b[100];
    a = (1 << 31);
    printf("%d\n", a);
    for (i=0; i<99; i++)
    {
        b[i] = 'v';
    }
    //b[99] = '\0';
    printf("string is: %s\n", b);
}
