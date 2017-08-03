/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    Node *ptr = head;
    Node *prev;
    if(position == 0){
        head = ptr->next;
        free(ptr);
        return head;
    }
    int i = 0;
    while(i < position){
        i++;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    return head;
}

// Recursive Implementation

Node* Delete(Node *head, int position)
{
    if(head == NULL){
        return head;
    }
    if(position == 0){
        return head->next;
    }
    head->next =  Delete(head->next, position-1);
    return head;
}
// Recursive Implementation Along with Free

Node* Delete(Node *head, int position)
{
    if(head == NULL){
        return head;
    }
    if(position == 0){
        Node *ptr = head->next;
        free(head);
        return ptr;
    }
    head->next =  Delete(head->next, position-1);
    return head;
}
