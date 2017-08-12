/*
Structure of the linked list node is as
struct node
{
    int data;
    struct node *next;
};
*/
void insertAtBegining(struct node** headRef, int newData)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data =  newData;
    new_node->next = *headRef;
    *headRef = new_node;
}