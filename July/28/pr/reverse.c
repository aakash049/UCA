Node* Reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Recursive

Node* Reverse(Node *head)
{
    Node *curr = head;
    if(curr == NULL || curr->next == NULL){
        head = curr;
        return head;
    }
    Node *ans = Reverse(curr->next);
    curr->next->next = curr;
    curr->next = NULL;
    return ans;
}
    