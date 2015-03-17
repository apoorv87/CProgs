#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node* createTree(struct node *root, int val, struct node *parent)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        temp->parent = parent;
        root = temp;
    }
    else
    {
        if (val <= root->data)
        {
            root->left = createTree(root->left, val, root);
        }
        else
        {
            root->right = createTree(root->right, val, root);
        }        
    }
    return root;
}

void display(struct node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("\n\t%d",root->data);
        display(root->right);
    } 
}

struct node* search(struct node *root, int val)
{
    struct node *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else if (val == root->data)
    {
        return root;       
    }
    else if (val < root->data)
    {
        temp = search(root->left, val);
    }
    else if (val > root->data)
    {
        temp = search(root->right, val);
    }
    return temp;
}

int next(struct node *temp, int data)
{
    struct node *temp1;
    if (temp->right != NULL)
    {
        return ((temp->right)->data);
    }
    else if (temp == ((temp->parent)->left))
    {
        return ((temp->parent)->data);
    }
    else if (temp->parent != NULL)
    {
        while (temp->data > ((temp->parent)->data))
        {
            temp = temp->parent;                
        }
        if (temp->parent)
        {
            return ((temp->parent)->data);
        }
        else
        {
            return -1;
        }
    }
    return -1;
}

int main()
{
    struct node *root = NULL, *temp;
    int next_elem;
    root = createTree(root, 5, NULL);  
    root = createTree(root, 1, NULL); 
    root = createTree(root, 6, NULL); 
    root = createTree(root, 3, NULL);
    root = createTree(root, 4, NULL);
    root = createTree(root, 2, NULL);
    display(root);
    temp = search(root, 4);
    if (temp != NULL)
    {
        printf("\n\t%d\t", temp->data);
    }
    next_elem = next(temp, 4); 
    printf("\nNext Element : %d", next_elem);
//  next = nextElem(elem, root);
}
