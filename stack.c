#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct stack
{
    int len;
    int index;
    int *a;
};

void create(struct stack *s, int len)
{
    s->len = len;
    s->index = 0;
    s->a = malloc(len*sizeof(int));
}

void push (struct stack *s, int elem)
{
    assert(s->index != s->len);
    s->a[s->index++] = elem;    
}

int pop (struct stack *s)
{
    assert(s->index != 0);
    s->index--;
    return s->a[s->index];    
}

void destroy(struct stack *s)
{
    free(s->a);
}

int main()
{
    struct stack *s;
    int elem1, elem2;
    
    s = (struct stack*)malloc(sizeof(struct stack));
    create(s, 5);
    push(s, 5);
    push(s, 1);
    push(s, 6);
    push(s, 2);
    elem1 = pop(s);
    elem2 = pop(s);
    printf("%d %d", elem1, elem2);
    destroy(s);
}






