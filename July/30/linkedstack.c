#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head, int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void print(struct node **head){
    struct node *ptr = *head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void pop(struct node **head){
    struct node *ptr = *head;
    if(ptr == NULL){
        printf("Underflow\n");
        return;
    }
    ptr = ptr->next;
    free(*head);
    *head = ptr;
}

int main(){
    struct node *head = NULL;
    push(&head, 5);
    push(&head, 8);
    push(&head, 10);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    pop(&head);
    print(&head);
    return 0;
}
