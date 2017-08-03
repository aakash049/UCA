#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}nn;

nn* addAtBeginning(nn *head, int x){
    nn *point = (nn*) malloc(sizeof(nn));
    point->data = x;
    point->next = head;
    head = point;
    return head;
}

void print(nn *head){
    nn *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverse_pair(nn **h){
	nn **curr = h;
	nn *first = *h;
	nn *second = first->next;
	while(first && second){
		first->next = second->next;
		second->next = first;
		*curr = second;
		curr = &(first->next);
		first = first->next;
		second = first->next;
	}
}

int main(void){
    nn* head = NULL;
    nn *var = (nn*) malloc(sizeof(nn));
    var->data = 50;
    var->next = NULL;
    head = var;
    head = addAtBeginning(head, 40);
    head = addAtBeginning(head, 30);
    head = addAtBeginning(head, 20);
    head = addAtBeginning(head, 10);
    print(head);
    printf("\n");
    reverse_pair(&head);
    print(head);
}
