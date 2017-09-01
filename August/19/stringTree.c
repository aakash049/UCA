#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char key[100];
    int count;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, char *word) {

    if (root == NULL) {
        node *newNode = calloc(1, sizeof(node));
        strcpy(newNode->key, word);
        newNode->count = 1;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (strcmp(root->key, word) == 0)
        root->count++;
    else if (strcmp(root->key, word) > 0)
        root->right = insert(root->right, word);
    else
        root->left = insert(root->left, word);
    return root;
}

node *findMost(node *root) {
    if (root == NULL || root->left == NULL && root->right == NULL)
        return root;
    node *left = findMost(root->left);
    node *right = findMost(root->right);

    node *larger;
    if (left == NULL)
        larger = right;
    else if (right == NULL)
        larger = left;
    else
        larger = (left->count > right->count) ? left : right;

    return (larger->count > root->count) ? larger : root;
}

void printTree(node *root) {
    if (root == NULL)
        return;
    printTree(root->left);
    printf("%s %d", root->key, root->count);
    printTree(root->right);
}

int main() {
    node *root = NULL;
    FILE *file = fopen("test.txt", "r");
    char *word = calloc(100, sizeof(char));
    while (!feof(file)) {
        fscanf(file, "%s", word);
        if (strlen(word) >= 10)
            root = insert(root, word);
    }
    node *large = findMost(root);
    printf("%s %d\n", large->key, large->count);
}
