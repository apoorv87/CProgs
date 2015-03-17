#include <stdio.h>

int checkRegex(char *reg, char *inp)
{
    int i=0, j=0;
    int match = 1;
    char c;
    while((reg[i] != '\0') && (inp[j] != '\0'))
    {
        if ((reg[i] >= 'a') && (reg[i] <= 'z') && (reg[i+1] != '*'))
        {
            if (reg[i] != inp[j])
            {
                match = 0;
                break;
            }
            i++;
            j++;
        }
        else if (reg[i] == '.')
        {
            if (!((inp[j] >= 'a') && (inp[j] <= 'z')))
            {
                match = 0;
                break;
            }
            i++;
            j++;
        }
        else if (reg[i+1] == '*')
        {
            c = reg[i];
            while ((inp[j] == c) && (j < strlen(inp)))
                    j++;
            i++;
            i++;
        }
    }


    return match;
}

int main()
{
    char reg[10] = "aa.b";
    char inp[10] = "aa1b";
    int match;
    match = checkRegex(reg, inp);
    printf("String Matches: %d", match);
}



























