#include <stdio.h>

int sum(int a, int b)
{
    return a+b;
}

int main()
{
    int result;
    int (*fn)(int, int);

    fn = sum;
    result = (*fn)(3, 5);
    printf("Result: %d\n", result);

}
