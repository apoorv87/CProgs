#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

void memtest()
{
    printf("hello");
  int *a = (int *)malloc(sizeof(int));
  int *b = (int *)malloc(sizeof(int));

}

int main()
{
    mtrace();
    memtest();
    muntrace();
}
