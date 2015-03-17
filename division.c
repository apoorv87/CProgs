#include <stdio.h>

int main()
{
    int a = 127, b = 6, quotient;
    quotient = divide(a,b);
    printf("Quotient: %d", quotient);
}

int divide(int a, int b)
{
    int temp = b, q = 1;
    if (a < b)
    {
        return 0;
    }
    while((a-temp) > 0)
    {
        temp <<= 1;
        q <<= 1;
    }
    if ((a-temp) == 0)
    {
        return q;
    }
    else
    {
        temp >>= 1;
        q >>= 1;
        return (q + divide((a-temp), b));
    }
}
