#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct node
{
	char key[100];
	int count;
	struct node *left, *right;
};

struct node *newNode(char *item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	strcpy(temp->key, item);
	temp->count = 0;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node, char *key)
{
	if (node == NULL) return newNode(key);
	if(strcmp(key, node->key) == 0) (node->count)++;
	if (strcmp(key, node->key) < 0)
		node->left = insert(node->left, key);
	else if (strcmp(key, node->key) > 0)
		node->right = insert(node->right, key); 

	return node;
}

int max1 = 0;
char str[100];
void preorder(struct node *root){
    if(root == NULL) return;
    if(root->count > max1){
    	max1 = root->count;
    	strcpy(str,root->key);
    }
    preorder(root->left);
    preorder(root->right);
}

int main() {
	clock_t start = clock();
	struct node *root = NULL;
	/*string inp;
	cin >> inp;
	root = insert(root, inp);
	for (int i = 0; i < 7; ++i) {
		cin >> inp;
		if(inp.size() >= 10){
			insert(root, inp);
		}
	}
	preorder(root);
	cout << str << endl;*/
	FILE * fp;
	fp = fopen("leipzig1M.txt", "r+");
	char *word = (char *)calloc(100, sizeof(char));
	fscanf(fp, "%s", word);
	root = insert(root, word);
	while(!feof(fp)){
		fscanf(fp, "%s", word);
		if (strlen(word) >= 10){
			insert(root, word);
		}
	}
	preorder(root);
	clock_t end = clock();
	double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    printf("N: %lf\n",time_elapsed_in_seconds);
	printf("%s %d",str, max1);
}