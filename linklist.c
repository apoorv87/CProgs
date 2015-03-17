#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(struct node **head, int val)
{
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   struct node *temp1;
   temp->data = val;
   temp->next = NULL;
   if (*head == NULL)
   {
     *head = temp;
   }
   else
   {
       temp1 = *head;
       while(temp1->next)
       {
           temp1 = temp1->next;
       }
       temp1->next = temp; 
   }
}

void sortedInsert(struct node **head, int val)
{
    struct node *temp, *curr, *temp1;
    if (*head == NULL)
    {
        *head = (struct node *)malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->next = NULL;
    }
    else
    {
        if (val < (*head)->data)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = val;
            temp->next = *head;
            *head = temp;
        }
        else
        {
            curr = *head;
            //printf("\n\tPrinting %d", curr->data);
            while(curr != NULL)
            {
                //printf("\nPrinting %d", (*head)->data);
                if (curr->next != NULL)
                {
                if (val < ((curr->next)->data))
                {
                    temp1 = curr->next;
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = val;
                    temp->next = temp1;
                    curr->next = temp;
                    break;
                }
                else
                {
                    curr = curr->next;
                }
                }
                else
                {
                    temp = (struct node *)malloc(sizeof(struct node));
                    temp->data = val;
                    temp->next = NULL;
                    curr->next = temp;
                    break;
                }
            } 
        }
    }
}

void sort(struct node **head)
{
    struct node *tempHead = NULL;
    struct node *curr = *head;
    struct node *prev;

    while(curr != NULL)
    {
        sortedInsert(&tempHead, curr->data);
 //       printf("\n\t%d", tempHead->data);
        prev = curr;
        curr = curr->next;
        free(prev);
//        printf("\n%d Printing", curr->data);
    }
    *head = tempHead;
}

void display(struct node *head)
{
    printf("\n\tDisplay: ");
    while (head != NULL)
    {
        printf("\n\t%d", head->data);
        head = head->next;
    }    
}

void reverse_display(struct node *head)
{
    struct node *temp = head;
    if (temp->next != NULL)
    {
        reverse_display(temp->next);
    }
    printf("\n\t%d\n", temp->data);
}

void reverse_list(struct node **head)
{
    struct node *temp = *head;
    struct node *temp1, *prev;
    while (temp != NULL)
    {
        temp1 = temp->next;
        if (temp == *head)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = prev;
        }
        prev = temp;
        temp = temp1;
    }
    *head = prev;
}

void reverse_smart(struct node **head)
{
    struct node *temp = *head, *temp1;
    struct node *revList = NULL;
    
    while(temp)
    {
        temp1 = temp;
        temp = temp->next;
        temp1->next = revList;
        revList = temp1;
    }
    *head=revList;
}

void reverse_recurse(struct node **head, struct node *curr, struct node *prev)
{
    struct node *temp;
    if (curr->next == NULL)
    {
        curr->next = prev;
        *head = curr;
    }
    else
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        reverse_recurse(head, temp, prev);
    }
}

void remDuplicates(struct node *head)
{
    struct node *temp1, *temp2, *dup;
    while((temp1->next != NULL) || (temp1 != NULL))
    {
       temp2 = temp1;
       while(temp2->next != NULL)
       {
           if (temp1->data == temp2->next->data)
           {
               dup = temp2->next;
               temp2->next = temp2->next->next;
               free(dup); 
           }
           else
           {
               temp2 = temp2->next;
           }
       }
       temp1 = temp1->next;
    }
}

void palindrome(struct node *head)
{
    struct node *slow = head, *fast = head, *mid, *temp, *temp1, *prev;
    while((fast->next) || (fast->next->next))
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    mid = slow->next;
    temp = mid;
    while (temp)
    {
        if (temp == mid) 
        {
        temp1 = (struct node*)malloc(sizeof(struct node));
        temp1->data = temp->data;
        temp1->next = NULL;
        prev = temp1;
        temp = temp->next;
        }
        else
        {
        temp1 = (struct node*)malloc(sizeof(struct node));
        temp1->data = temp->data;
        temp1->next = NULL;
        prev->next = temp1;
        prev = temp1;
        temp = temp->next;
        }
    }
}

struct node* findLoop(struct node *head)
{
    struct node *fast, *slow;
    fast = head;
    slow = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return slow;
        }
    } 
    return NULL;
}

void remLoop(struct node *head)
{
    struct node *temp, *ptr1, *ptr2;
    temp = findLoop(head);
    if (temp)
    {
        while(1)
        {
            ptr1 = head;
            while((ptr2->next != ptr1) && (ptr2->next != temp))
            {
                ptr2 = ptr2->next;
            }
            if (ptr2->next == ptr1)
            {
                break;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        ptr2->next = NULL;
    }
}

int main()
{
    struct node *head = NULL;
    int i;
    for (i=0; i<10; i++)
        create(&head, i);
    display(head);
    sort(&head);
    display(head);
    printf("\nReverse List:");
    reverse_smart(&head); 
    display(head);
    palindrome(head);
    remLoop(head);
}
