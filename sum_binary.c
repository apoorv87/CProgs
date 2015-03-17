#include <stdio.h>
#include <math.h>

void inttobinarystring(int val, char *s);
int binarystringtoint(char *s);
void reverse(char *s, int len);

int main()
{
    char str1[10] = "1101";
    char str2[10] = "1100";
    char *str3;
    int len1, len2, len3, i, d1, d2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    len3 = ((len1 >= len2) ? len1:len2); 
    str3 = (char *)malloc((len3+1)*sizeof(char));
    d1 = binarystringtoint(str1);
    d2 = binarystringtoint(str2);
    printf("\n%d\t%d\n", d1, d2);
    inttobinarystring((d1+d2), str3);
    reverse(str3, strlen(str3));
    printf("\n\t%s\n", str3);
}

int binarystringtoint(char *s)
{
    int i, val = 0, index=0;
    i = strlen(s) - 1;
    while (i >= 0)
    {
        if (s[index++] == '1')
        {
            val += pow(2,i);
        }
        i--;
    }
    return val;
}

void inttobinarystring(int n, char *s)
{
    int i=0, index;
    while(n/2)
    {
        if ((n%2) == 1)
        {
            s[i++] = '1';
        }
        else
        {
            s[i++] = '0';
        }
        n = n/2;
    }
    s[i++] = '1';
    s[i] = '\0';
}

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
