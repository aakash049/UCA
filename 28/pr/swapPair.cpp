Node* swapPair(Node *head)
{
    Node *ptr = head;
    if(ptr == NULL || ptr->next == NULL)
        return ptr;
    Node *new_head = head->next;
    Node *remain = head->next->next;
    head->next->next = head;
    head->next = swapPair(remain);
    return new_head;
}

/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node 
struct Node
{
    int data;
    Node* next;
};*/
/*You are required to complete below method*/
Node* swapPair(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *ptr = head->next;
    head->next = swapPair(ptr->next);
    ptr->next = head;
    return ptr;
}
