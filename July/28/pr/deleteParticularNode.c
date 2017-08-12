/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
Node* deleteNode(Node *head,int x)
{
    Node *ptr = head;
    if(ptr->data == x){                  // if head has that data which we want to delete.
        Node *temp = head->next;
        free(head);
        return temp;
    }
    Node *prev = NULL;
    while(ptr->data != x){
        prev = ptr;
        ptr = ptr->next;
        if(ptr == NULL)               // if the data which we want to delete is not present in the linked list
            return head;
    }
    prev->next = ptr->next;           // link changing
    free(ptr);
    return head;
}