#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int len;
    int numBytes;
    int index;
    void *a;
};

void create(struct stack *s, int elems, int size)
{
    s->len = elems;
    s->numBytes = size;
    s->index = 0;
    s->a = (void *)malloc((s->len)*(s->numBytes));
}

void grow(struct stack *s)
{
    s->len *= 2;
    s->a = realloc(s->a, (s->len*s->numBytes));
    printf("\nStack needs to grow\n");
}

void push(struct stack *s, void *elemAddr)
{
    if (s->index == s->len)
    {
        grow(s);
    }
    char *target = (char *)(s->a) + (s->index * s->numBytes);
    memcpy(target, elemAddr, s->numBytes);
    s->index++;
}

void pop(struct stack *s, void *elemAddr)
{
    assert(s->index != 0);
    s->index--;
    s->len--;
    char *src = (char *)(s->a) + (s->index * s->numBytes);
    memcpy(elemAddr, src, s->numBytes);
}

int main()
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    int a=2, b=3, c=4, d=5, e=1, f=7;
    int g, h;
    create(s, 2, 4);
    push(s, (void *)&a);
    push(s, (void *)&b);
    push(s, (void *)&c);
    push(s, (void *)&d);
    push(s, (void *)&e);    
    push(s, (void *)&f);

    pop(s, (void *)&g);
    pop(s, (void *)&h);
    printf("%d", g); 
    printf("%d", h);
}







