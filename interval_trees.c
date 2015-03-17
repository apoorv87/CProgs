#include <stdio.h>
#include <stdlib.h>
    
struct interval {
int low;
int high;
};

struct itnode { 
    int max;
    struct interval *i;
    struct itnode *left, *right;    
};

struct itnode *insert(struct itnode *root, struct interval *in) {
    if (root == NULL) {
        root = (struct itnode*)malloc(sizeof(struct itnode));
        root->i = in;
        root->max = in->high;
        return root;
    }    
    
    int low = root->i->low;
    if (in->low <= low) {
        root->left = insert(root->left, in);  
    } 
    else {
        root->right = insert(root->right, in);  
    }
    if (root->max < in->high) {
        root->max = in->high;
    }
    return root;
}

void inorder(struct itnode *root) {
    if (root) {
        inorder(root->left);
        printf("\n%d %d", root->i->low, root->i->high);
        inorder(root->right);
    }
}

int main() {
    struct interval *i1, *i2, *i3;
    struct itnode *root=NULL;

    i1 = (struct interval*)malloc(sizeof(struct interval));
    i2 = (struct interval*)malloc(sizeof(struct interval));
    i3 = (struct interval*)malloc(sizeof(struct interval));

    i1->low = -4;
    i1->high = 5;

    i2->low = -7;
    i2->high = 2;

    i3->low = 4;
    i3->high = 9;

    root = insert(root, i1);
    root = insert(root, i2);
    root = insert(root, i3);

    inorder(root);
}

