#include <bits/stdc++.h>
using namespace std;
struct node
{
	float key;
	int disp;
	struct node *left, *right;
};

struct node *newNode(float item, int disp)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->disp = disp;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, float key, int disp)
{
	if (node == NULL) return newNode(key, disp);

	if (key < node->key)
		node->left = insert(node->left, key, disp-1);
	else if (key > node->key)
		node->right = insert(node->right, key, disp+1); 

	return node;
}

void printLeft(node *n){
	if(n == NULL) return;
	if(n->left != NULL || n->right != NULL) cout << n->key << endl;
	if(n->left != NULL) printLeft(n->left);
	else printLeft(n->right);
}

void printRight(node *n){
	if(n == NULL) return;
	if(n->right != NULL) printRight(n->right);
	else printRight(n->left);
	if(n->left != NULL || n->right != NULL) cout << n->key << endl;
}

void printLeaves(node *n){
	if(!n) return;
	printLeaves(n->left);
	if(n->left == NULL && n->right == NULL) cout << n->key << endl;
	printLeaves(n->right);
}

void printCircumference(node *n){
	if(n != NULL){
		printLeft(n->left);
		printLeaves(n->left);
		printLeaves(n->right);
		printRight(n->right);
		cout << n->key << endl;
	}
}



int main() {
	struct node *root = NULL;
	root = insert(root, 5, 0);
	insert(root, 3, 0);
	insert(root, 2, 0);
	insert(root, 4, 0);
	insert(root, 7, 0);
	insert(root, 6, 0);
	insert(root, 8, 0);
	insert(root, 5.5, 0);
	printCircumference(root);
}