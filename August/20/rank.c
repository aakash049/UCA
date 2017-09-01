#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int key;
    int N;
    struct Node* left;
    struct Node* right;
}node;
node* root = NULL;
node* Insert(int key, node* n)
{
    if(n == NULL)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->key = key;
        temp->N = 1;
        //temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    /*if(key == n->key)
    {
        n->data = data;
    }*/
    if(key > n->key)
    {
        n->right = Insert(key, n->right);
    }
    if(key < n->key)
    {
        (n->N)++;
        n->left = Insert(key, n->left);
    }
    //n->N = size
    return n;
}
void insert(int key)
{
    root = Insert(key, root);
}
int rank(node* n, int key)
{
    int c;
    if(n == NULL)
        return 0;
    if(n->key > key)
        c = rank(n->left, key);
    if(n->key < key)
        c = n->N + rank(n->right, key);
    if(key == n->key)
        return n->N;
    return c;
}

void print(node* n)
{
    if(n == NULL)
        return;
    print(n->left);
    print(n->right);
    printf("%d\n", n->key);
}
int main()
{
    insert(5);
    insert(3);
    insert(2);
    insert(4);
    insert(7);
    insert(6);
    insert(8);
    int ans = rank(root, 5);
    printf("rank(%d) = %d\n", 5, ans);
    ans = rank(root, 3);
    printf("rank(%d) = %d\n", 4, ans);
     ans = rank(root, 2);
    printf("rank(%d) = %d\n", 2, ans);
     ans = rank(root, 4);
    printf("rank(%d) = %d\n", 4, ans);
     ans = rank(root, 7);
    printf("rank(%d) = %d\n", 7, ans);
     ans = rank(root, 6);
    printf("rank(%d) = %d\n", 6, ans);
     ans = rank(root, 8);
    printf("rank(%d) = %d\n", 8, ans);
    return 0;
}