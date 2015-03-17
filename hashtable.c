#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct hashtable {
    int size;
    struct node **table;
};

int hash(int i)
{
    return (i%50);
}

void create(struct hashtable **ht)
{
    *ht = (struct hashtable *)malloc(sizeof(struct hashtable));
    (*ht)->size = 50;
    (*ht)->table = (struct node **)calloc(50, sizeof(struct node *));
}

void insert(struct hashtable *ht, int item)
{
    int index;
    struct node *temp, *temp1;
    index = hash(item);
    if (ht->table[index] == NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = item;
        temp->next = NULL;
        ht->table[index] = temp;
    }
    else
    {
        temp  = ht->table[index];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = (struct node*)malloc(sizeof(struct node));
        temp1->data = item;
        temp1->next = NULL;
        temp->next = temp1;     
    }
}

int search (struct hashtable *ht, int item)
{
    int index = hash(item);
    struct node *temp;
    if (ht->table[index] == NULL)
    {
        return 0;
    }
    else
    {
        temp = ht->table[index];
        while(temp != NULL)
        {
            if (temp->data == item)
                return 1;
            temp = temp->next;
        }
        return 0;
    }
}

int main()
{
    struct hashtable *ht;
    int k, found;
    create(&ht);
    for (k=0; k<150; k++)
    {
        insert(ht, k);
    }
    found = search(ht, 120);
    printf("Element Found: %d", found);
}
