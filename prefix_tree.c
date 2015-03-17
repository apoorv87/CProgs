#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct tnode { 
    char data;
    struct tnode **child;    
};

struct tnode* create_tnode(char c) {
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->data = c;
    temp->child = (struct tnode**)calloc(26, sizeof(struct tnode*));
    return temp;
}

void build_trie(struct tnode **root, char *buf) {
    struct tnode *ptr;
    int i, index;
    char ch;

    *root = create_tnode(' ');
    ptr = *root;
    for(i=0; i<strlen(buf); i++) {
        ch = tolower(buf[i]);        
        if (isalpha(ch)) {
            index = ch - 97;
            if (ptr->child[index] == NULL) {
                ptr->child[index] = create_tnode(ch);
            }
            ptr = ptr->child[index];
        }
        else if ((ch == ' ') || (ch == '\0')) {
            ptr = *root;
        }
    } 
}

int search_trie(struct tnode *root, char *s) {
    int i, index;
    struct tnode *ptr = root;
    for (i=0;i<strlen(s);i++) {
        index = s[i] - 97;
        if (ptr->child[index]) {
            ptr = ptr->child[index];
        }
        else {
            return 0;
        }   
    } 
    return 1;
}

int main() {
    struct tnode *root;
    int ret;
    char s[100] = "hello this is not funny hi";
    char word[8] = "funny";
    build_trie(&root, s);
    ret = search_trie(root, word);
    if (ret) { 
        printf("Word: %s", word);
    }
    else {
        printf("Word not present in trie");
    }
}

