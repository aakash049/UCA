#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

void insert(int key, struct Node **n){
    if(*n == NULL){
        *n = (struct Node *n)malloc(sizeof(struct Node));
        (*n)->key = key;
        (*n)->left = NULL;
        (*n)->right = NULL;
        return;
    }
    if((*n)->key > key)
        (*n)->left = insert(key, (*n)->left);
    else
        (*n)->right = insert(key, (*n)->right);
    return;
}

int main(){
    struct Node *n = NULL;
    insert(5, n);
    insert(3, n);
    //insert(8, &n);
    //insert(4);
    //insert(2);
    //insert(1);
    //insert(7);
    //insert(9);
}
