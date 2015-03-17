#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void insertHead(struct node **head, struct node **tail, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;

    if ((*head == NULL) && (*tail == NULL))
    {
        temp->nextf = NULL;
        temp->nextb = NULL; 
        *head = temp;
        *tail = temp;
    }
    else
    {
        temp->nextf = *head;
        temp->nextb = NULL;
        (*head)->nextb = temp;
        *head= temp;
    }
}

void insertTail(struct node **head, struct node **tail, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;

    if ((*tail == NULL) && (*head == NULL))
    {
        temp->nextf = NULL;
        temp->nextb = NULL;
        *head = temp;
        *tail = temp;
    }
    else
    {
        temp->nextb = *tail;
        temp->nextf = NULL;
        (*tail)->nextf = temp;
        *tail= temp;
    }
}

void displayHead(struct node *head)
{
    while(head != NULL)
    {
        printf("\n\t%d", head->data);
        head = head->nextf;
    }
}

void displayTail(struct node *tail)
{
    while(tail != NULL)
    {
        printf("\n\t%d", tail->data);
        tail = tail->nextb;
    }
}

void deleteHead(struct node **head, struct node **tail)
{
    struct node *temp;
    if ((*head == NULL) && (*tail == NULL))
    {
        printf("No elements in list");
    }
    else if (*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        temp = (*head)->nextf;
        free(*head);
        *head = temp;
        (*head)->nextb = NULL;
    }
}

void deleteTail(struct node **head, struct node **tail)
{
    struct node *temp;
    if ((*head == NULL) && (*tail == NULL))
    {
        printf("No elements in list");
    }
    else if (*head == *tail)
    {
        free(*tail);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        temp = (*tail)->nextb;
        free(*tail);
        *tail = temp;
        (*tail)->nextf = NULL;
    }
}


