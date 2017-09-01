#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int key;
	struct node *left, *right;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key); 

	return node;
}

void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d\n", root->key);
    preorder(root->left);
    preorder(root->right);
}

int search(struct node *root, int num){
    if(root == NULL) return -1;
    if(root->key == num) return num;
    if(root->key > num) return search(root->left, num);
    else return search(root->right, num);
}
int s1 = 0;

void sumNodes(struct node *root){
    if(root == NULL) return;
    s1 += root->key;
    sumNodes(root->left);
    sumNodes(root->right);
}

int height(struct node *root){
	if(root == NULL) return -1;
	if(root->left == NULL && root->right == NULL) return 0;
	if(height(root->left) > height(root->right))
        return (1 + height(root->left));
    else
        return (1 + height(root->right));
}

struct node* getMin(struct node *root){
    if(root->left == NULL) return root;
    return getMin(root->left);
}

struct node* delMin(struct node *root){
    if(root->left->left == NULL) return root;
    return delMin(root->left);
}

struct node* delMini(struct node *root){
	if(root->left == NULL) return root->right;
	root->left = delMini(root->left);
	return root;
}

struct node* delMaxi(struct node *root){
	if(root->right == NULL) return root->left;
	root->right = delMaxi(root->right);
	return root;
}

struct node* delMax(struct node *root){
    if(root->right == NULL) return root;
    if(root->right->right == NULL) return root;
    return delMax(root->right);
}

int main()
{
	struct node *root = NULL;
	root = insert(root, 15);
	insert(root, 13);
	insert(root, 12);
	insert(root, 11);
	insert(root, 10);
	insert(root, 9);
	insert(root, 8);
    preorder(root);
    printf("Search: %d\n", search(root, 10));
    sumNodes(root);
    printf("Sum : %d\n", s1);
    printf("Height : %d\n", height(root));
    printf("Minimum : %d\n", getMin(root)->key);
    struct node *temp = delMin(root);
    temp->left = NULL;
    preorder(root);
    printf("\n\n");
    temp = delMax(root);
    if(temp != root)
        temp->right = NULL;
    else
        root = root->left;
    preorder(root);
	return 0;
}
