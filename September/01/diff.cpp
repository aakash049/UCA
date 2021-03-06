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
int sum = 0;
void diff(struct node *root){
    stack <node *> s1;
    s1.push(root);
    bool rev = false;
    while(!s1.empty()){
        stack <node *> s2;
        while(!s1.empty()){
            struct node *temp = s1.top();
            s1.pop();
            sum += temp->key;
            if(rev == true){
                if(temp->left) s2.push(temp->left);
                if(temp->right) s2.push(temp->right);           
            }
            else{ 
                if(temp->right){ 
                	temp->right->key *= -1;
                	s2.push(temp->right);
                }
                if(temp->left){
                	temp->left->key *= -1;  
                	s2.push(temp->left);
                }
            }
        }
        s1 = s2;
        rev = !rev;
    }
}

void diff2(struct node *root) {
    queue <node *> q;
    q.push(root);
    q.push(NULL);
    int mul = 1;
    while(!q.empty()){
        node *x = q.front();
        if(x != NULL){
            sum += (mul*(x->key));
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
        else if(q.size() > 1){
            mul *= -1;
            q.push(x);
        }
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
	diff(root); // can use diff2 also
	cout << sum << endl;
	return 0;
}
