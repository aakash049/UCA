/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void InsertNth(Node **head, int data, int position)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node *));
    new_node->data = data;
    if(position == 0){
        new_node->next = *head;
        *head = new_node;
    }
    int i = 0;
    struct Node *ptr = *head;
    struct Node *prev;
    while(i < position){
        i++;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new_node;
    new_node->next = ptr;
}
