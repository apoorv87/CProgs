#include <stdio.h>
#include "dlist.h"


int main()
{
    struct node *head = NULL, *tail = NULL;
    insertHead(&head, &tail, 6);
    insertHead(&head, &tail, 7);
    insertHead(&head, &tail, 8);
    insertTail(&head, &tail, 2);
    insertTail(&head, &tail, 3);
    insertTail(&head, &tail, 4);
    displayHead(head);
    displayTail(tail);
    deleteHead(&head, &tail);
    deleteTail(&head, &tail);
    displayHead(head);
}
