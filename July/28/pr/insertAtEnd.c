/*
Structure of the linked list node is as
struct node
{
    int data;
    struct node *next;
};
*/
void insertAtEnd(struct node** headRef, int newData)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data =  newData;
    new_node->next = NULL;
    if(*headRef == NULL){
        *headRef = new_node;
        return;
    }
    struct node *ptr = *headRef;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}