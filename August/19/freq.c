#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	string key;
	int count;
	struct node *left, *right;
};

struct node *newNode(string item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->count = 0;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, string key)
{
	if (node == NULL) return newNode(key);
	if(key == node->key) (node->count)++;
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key); 

	return node;
}

int max1 = 0;
string str;
void preorder(struct node *root){
    if(root == NULL) return;
    if(root->count > max1){
    	max1 = root->count;
    	str = root->key;
    }
    preorder(root->left);
    preorder(root->right);
}

int main() {
	struct node *root = NULL;
	string inp;
	cin >> inp;
	root = insert(root, inp);
	for (int i = 0; i < 5; ++i) {
		cin >> inp;
		if(inp.size() >= 5){
			insert(root, inp);
		}
	}
	preorder(root);
	cout << str << endl;
}