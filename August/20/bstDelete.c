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

struct node* getMin(struct node *root){
	if(root->left == NULL) return root;
	return getMin(root->left);
}

struct node* delMin(struct node *root){
	if(root->left == NULL) return root->right;
	root->left = delMin(root->left);
	return root;
}

struct node* delete(struct node *root, int key){
	if(root == NULL) return root;
	if(root->key > key)
        root->left = delete(root->left, key);
    else if(root->key < key)
        root->right = delete(root->right, key);
    else{
        struct node *temp = root;
        root = getMin(root->right);
        root->right = delMin(temp->right);
        root->left = temp->left;
        return root;
    }
}

int main()
{
	struct node *root = NULL;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 7);
	insert(root, 6);
	insert(root, 8);
	preorder(root);
	delete(root, 7);
	printf("\n");
    preorder(root);
}
