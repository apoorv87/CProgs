#include <stdio.h>

int power(int x, int y)
{
    int temp; 
    if (y==0) {
        return 1;
    }
    temp = power(x, (int)(y/2));
    if (y%2 == 0) {
        return temp*temp;
    }
    else {
        return x*temp*temp;
    }
}

int main()
{
    int res;
    res = power(4, 5);    
    printf("Result: %d", res);
}



