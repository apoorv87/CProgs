#include <stdio.h>

int main()
{
    int a[3];
    a[0] = 1;
    a[1] = 4;
    a[2] = 5;
    a[-1] = 6;
    printf("%d %d %d", a[2], a[-1], sizeof(char *));
}
