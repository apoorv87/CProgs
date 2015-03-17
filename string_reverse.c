#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s, int len)
{
    char tmp;
    int i = 0;
    char *start, *end;
    start = s;
    end = s + (len-1);
    while(i < len/2)
    {
        tmp = *(start);
        *(start) = *(end);
        *(end) = tmp;
        start++;
        end--;
        i++; 
    }
}

int main()
{
    char *s;
    int i, len;
    s = (char *)malloc(20);
    for(i=0; i<10; i++)
    {
        s[i] = 'a' + i;
    }
    s[i] = '\0';
    len = strlen(s);
    printf("\n%s", s);
    reverse(s, len);
    printf("\n%s", s);
}
