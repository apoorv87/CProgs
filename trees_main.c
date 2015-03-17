#include <stdio.h>
#include "trees.h"

int main()
{
    struct node *root = NULL;
    int *level, check;
    *level = 0;
    int path[100];
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 4);
    display(root);
    if (lookup(root, 2))
    {
        printf("\nelement found in tree");
    }
    else
    {
        printf("\nelement not found");
    }
    printf("\nMin value: %d", min(root));
    root = delete_node(root, 3);
    display(root);
    printpaths(root, path, 0);  
    check = checkLeafLevel(root, 0, level);
    if (check)
    {
        printf("All leafs at same level");    
    }
    else
    {
        printf("leafs are not at same level");
    }
}

