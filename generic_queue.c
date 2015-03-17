#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct queue {
    int len;
    int numBytes;
    int rear;
    int front;
    void *a;
};

void create(struct queue *q, int elems, int size)
{
    q->len = (elems);
    q->numBytes = size;
    q->rear = 0;
    q->front = 0;
    q->a = (void *)malloc((s->len)*(s->numBytes));
}

void grow(struct queue *q)
{
    q->len *= 2;
    q->a = realloc(q->a, (q->len*q->numBytes));
    printf("\nQueue needs to grow\n");
}

void qInsert(struct queue *q, void *elemAddr)
{
    if (((q->front + 1) % (q->len)) == q->rear)
    {
        grow(q);
    }
    char *target = (char *)(q->a) + (q->front * q->numBytes);
    memcpy(target, elemAddr, q->numBytes);
    q->front = (q->front + 1)%(q->len);
}

void qDelete(struct queue *q, void *elemAddr)
{
    assert(q->rear != q->front);
    q->len--;
    char *src = (char *)(q->a) + (q->rear * s->numBytes);
    memcpy(elemAddr, src, q->numBytes);
    q->rear = (q->rear + 1)%(q->size);
}

int main()
{
    struct stack *s;
    s = (struct stack*)malloc(sizeof(struct stack));
    int a=2, b=3, c=4, d=5, e=6, f=7;
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
