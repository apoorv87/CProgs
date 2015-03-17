#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *test[2], str[12] = "hi";
    int i, size; 
    test[0] = (char *)malloc(sizeof(char)*10);
    test[1] = (char *)malloc(sizeof(char)*6);
    strcpy(test[0], "hello");
    strcpy(test[1], "test");
    printf("\n%s", test[0]); 
    printf("\n%s", test[1]); 
    for (i=0;i<2;i++) {
        size = strlen(test[i]);
        printf("\n%d", size);
    }
    printf("\n%d", sizeof(str));

    return 0;
}
