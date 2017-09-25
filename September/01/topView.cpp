#include <bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	int disp;
	struct node *left, *right;
};

struct node *newNode(int item, int disp)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->disp = disp;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, int key, int disp)
{
	if (node == NULL) return newNode(key, disp);

	if (key < node->key)
		node->left = insert(node->left, key, disp-1);
	else if (key > node->key)
		node->right = insert(node->right, key, disp+1); 

	return node;
}

void preOrder(struct node *root){
	if(!root) return;
	preOrder(root->left);
	cout << root->key << " " << root->disp << endl;
	preOrder(root->right);
}


void topView(struct node *root){
	queue <node *> q;
	q.push(root);
	map <int, node *> m;
	while(!q.empty()){
        node *temp = q.front();
	    if(m.count(temp->disp) == 0){
			m.insert(make_pair(temp->disp, temp));
		}
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
	}
	for (map <int, node*> :: iterator it = m.begin(); it != m.end(); ++it){
		cout << (it->second)->key << endl;
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
	topView(root);
	//preOrder(root);
	return 0;
}
