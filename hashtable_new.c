#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
int data;
struct node *next;
};

void insert(struct node **hashtable, int val)
{
    int index;
    struct node *temp;
    index = (val % SIZE);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    if (hashtable[index] == NULL)
    {
        hashtable[index]=temp;
        hashtable[index]->next = NULL;
    }
    else
    {
        temp->next = hashtable[index]->next;
        hashtable[index]->next = temp;
    }
}

void display(struct node **hashtable)
{
    int i;
    struct node *temp;
    for (i =0; i<SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            printf("\n");
            temp = hashtable[i];
            while(temp != NULL)
            {
                printf("%d\t",temp->data);
                temp = temp->next; 
            }
        }
    }
}

int main()
{
    struct node **table;
    table = (struct node **)calloc(SIZE, sizeof(struct node *)); 
    insert(table, 5);
    insert(table, 15);
    insert(table, 25);
    insert(table, 26);
    insert(table, 37);
    display(table);
}

