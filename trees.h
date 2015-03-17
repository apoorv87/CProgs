struct node {
    struct node *right;
    struct node *left;
    int data;
};

struct node* insert(struct node*, int);
void display(struct node*);
int lookup(struct node*, int);
struct node* delete_node(struct node*, int);
void nonrecur_traversal(struct node*);
struct node* inorderSucc(struct node*, int);
int isBst(struct node*, int min, int max);
void printpaths(struct node*, int [], int pathlen);


