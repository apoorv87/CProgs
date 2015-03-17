#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p;
    p = (char *)realloc(NULL, 20);    
    p[0] = 'a';
    p[1] = 'b';
    p[2] = '\0';
    printf("%s", p);

    int *p1;
    p1 = calloc(2, 8);    
    p1[0] = 3;
    p1[1] = 4;
    printf("\n%d %d\n", p1[0], p1[1]);

}


