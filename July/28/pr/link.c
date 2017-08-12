#include <stdio.h>
#include "insertAtEnd.c"

/*struct node
{
    int data;
    struct node *next;
};*/

void print(struct node *head){
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){
	struct node *head = NULL;
	insertAtEnd(&head, 10);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 30);
	insertAtEnd(&head, 40);
	print(head);
}