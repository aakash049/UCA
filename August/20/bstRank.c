#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int key;
	struct node *left, *right;
	int size;
};

struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	temp->size = 1;
	return temp;
}

/*int sizeofBST(struct node *root){
	if(root == NULL) return 0;

}*/

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);

	if (key < node->key){
		(node->size)++;
		node->left = insert(node->left, key);
	}
	else if (key > node->key){
		(node->size)++;
		node->right = insert(node->right, key); 
	}

	return node;
}

int rank(struct node *root, int key){
	if(root == NULL) return 0;
	else if(root->key < key) return 1 + (root->left ? root->left->size : 0) + rank(root->right, key);
	else if(root->key > key) return rank(root->left, key);
	else return (root->left ? root->left->size : 0);
}

void preorder(struct node *root){
    if(root == NULL) return;
    printf("%d %d\n", root->key, root->size);
    preorder(root->left);
    preorder(root->right);
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
	//preorder(root);
	int x = rank(root, 5);
	printf("%d\n", x);
	 x = rank(root, 3);
	printf("%d\n", x);
	 x = rank(root, 2);
	printf("%d\n", x);
	 x = rank(root, 4);
	printf("%d\n", x);
	 x = rank(root, 7);
	printf("%d\n", x);
	 x = rank(root, 8);
	printf("%d\n", x);
}