#include <stdio.h>
#include <string.h>

int main()
{
    char s[20] = "ab,45,67,89";    
    char *tok;
    tok = strtok(s, ",");
    tok = strtok(NULL, ",");

    printf("\n%s", tok);
}


