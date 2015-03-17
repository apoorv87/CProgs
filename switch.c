#include <stdio.h>

int main()
{
    int i=3;
    switch(i) 
    {
        case 3:
            printf("\nhello");
        case 4:
            printf("\nhi");
        default:
            printf("\ndefault\n");
            break;
    }
    return;
}
