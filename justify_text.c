#include <string.h>
#include <stdio.h>

int count_words(char *s)
{
    int i;
    for (i=0; i<strlen(s); i++)
    {
        
    }

}


int main()
{
    char s[84];
    int i, j, number_lines, line_size=10;
    for (i=0; i<83; i++)
    {
        if (i%3) {
        s[i++] = 'a';
        }
        else if 
        {
            s[i++] = ' '
        }
    }
    s[i] = '\0';
    
    if (strlen(s) % line_size) { 
        number_lines = (strlen(s)/line_size) + 1;
    }
    else
    {
        number_lines = (strlen(s)/line_size);
    }
        
    for (i=0; i<number_lines; i++)
    {
        words = 0;
        spaces = 0;
        space_seen = 1;
        for (j=0; j<line_size; j++)
        {
            if ((s[j] == ' ') || (s[j] == '\n'))
            {
                space_seen = 1;
            }
            else if (space_seen == 1)
            {
                space_seen = 0;
                words++;
            }           
        }
        dist_spaces = (line_size/words);
        for (j=0; j<line_size; j++)
        {
            if (((s[j] == ' ') || (s[j] == '\n')) && (space_seen == 0))
            {
                space_seen = 1;
                for (k=0; k <dist_spaces; k++)
                {
                    printf("%c", ' ');
                }
            }
            else if (space_seen == 1)
            {
                space_seen = 0;
                printf("%c", s[j]);
            }           
        }
        dist_spaces = (line_size/words);
    }


}





