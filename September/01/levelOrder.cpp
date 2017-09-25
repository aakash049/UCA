#include <bits/stdc++.h>
using namespace std;
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

void levelOrder(struct node *root){
	queue <node *> q;
	q.push(root);
	while(!q.empty()){
        node *temp = q.front();
	    cout << temp->key << endl;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
	}
}

void levelOrder2(struct node *root) {
    queue <node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *x = q.front();
        if(x != NULL){
            cout << x->key << endl;
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        else if(q.size() > 1)
            q.push(x);
        q.pop();
    }
}

int main() {
	struct node *root = NULL;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 7);
	insert(root, 6);
	insert(root, 8);
	levelOrder2(root);
	return 0;
}
