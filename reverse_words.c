#include <stdio.h>

void reverse(char *str, int start, int end);

int main()
{
    char str[80] = "teri maa ki saaree";
    int i, start = 0;

    for (i=0 ; str[i]!= '\0'; i++)
    {
        if (str[i] == ' ')
        {
            reverse(str, start, i);
            start = i+1;
        }
    }
    reverse(str, start, i);
    printf("\nReversed: %s", str);

}

void reverse(char *str, int start, int end)
{
    int j,k, mid;
    mid = start + ((end-start)/2);
    char temp;

    for (j =start, k=end-1; j <= mid; j++, k--)
    {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}



