#include <stdio.h>
#include <stdlib.h>

int a = 5;

struct node {
    int val;
    struct node *left;
    struct node *right;
};   

struct node* insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;
        root->val = data;
        return root;
    }
    else
    {
        if (data <= root->val)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

void walk_tree(struct node *root, int *size)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        walk_tree(root->left, size);
        printf("%d\n", root->val);
        (*size)++; 
        walk_tree(root->right, size);
    }
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}


int max_depth(struct node *root)
{
    
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(1 + max_depth(root->left), 1 +  max_depth(root->right));
    }

}

int print_paths(struct node *root, int *arr, int index)
{
    int i;
    if ((root->left == NULL) && (root->right == NULL))
    {
        arr[index++] = root->val;
        printf("\nNew Path:");
        for (i=0 ; i < index; i++)
        {
            printf("\t%d", arr[i]);
        }
    }
    else
    {
        arr[index++] = root->val;
        if (root->left != NULL)
            print_paths(root->left, arr, index);
        if (root->right != NULL)
            print_paths(root->right, arr, index);
    }
}

struct node* mirror(struct node *root)
{
    struct node *temp;
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        root->left = mirror(root->left);
        root->right = mirror(root->right);
        return root;
    }
}

int main()
{
    struct node *root = NULL;
    int size =0, maxd;
    int arr[10], index = 0;
    root = insert(root, 5);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 9);

    
    
    walk_tree(root, &size);
    printf("size of tree: %d", size);

    maxd = max_depth(root);
    printf("\nmax depth: %d", maxd);

    print_paths(root, arr, index);
    root = mirror(root);
    int size1 = 0;
    walk_tree(root, &size1);
}



