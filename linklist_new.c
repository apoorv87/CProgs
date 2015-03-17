#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


void insert(struct node **head, int val)
{
    struct node *temp;
    if (*head == NULL)     
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->next = NULL;
        temp->data = val;
        *head = temp;
    }
    else
    {
        temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = (struct node*)malloc(sizeof(struct node));
        (temp->next)->data = val;
        (temp->next)->next = NULL;
    }
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }

}

void delete(struct node **head, int val)
{
    struct node *temp,*curr, *prev,  *delnode;
    if ((*head)->data == val)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    else
    {
        curr = (*head)->next;
        prev = *head;
        while(curr != NULL)
        {
            if (curr->data == val)
            {
                delnode = curr;
                prev->next = curr->next;                
                curr = curr->next;
                free(delnode);
            }           
            else 
            {
                prev = prev->next;
                curr = curr->next;
            }
        }       
    }

}

void reverse(struct node **head)
{
    struct node *reverse = NULL, *temp, *curr = *head;
    while(curr != NULL)
    {
        temp = curr->next;
        curr->next = reverse;
        reverse = curr;
        curr = temp;
    } 
    *head = reverse;
}

struct node* reverse_recursion(struct node **head, struct node *prev)
{
    struct node *temp;
    if ((*head)->next == NULL) {
        (*head)->next = prev;
        return;
    } 
    else { 
    temp = (*head)->next;   
    (*head)->next = prev;
    prev = *head;
    *head = temp;
    reverse_recursion(head, prev);
    }
}


int main()
{
    struct node *head = NULL, *temp = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    display(head);
    delete(&head, 4);
    printf("\n");
    display(head);
    reverse(&head);
    printf("\n");
    display(head);
    reverse_recursion(&head, temp);
    display(head);
}
