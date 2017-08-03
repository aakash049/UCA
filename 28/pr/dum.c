/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
LinkedListNode* removeNodes(LinkedListNode* list, int x) {
    LinkedListNode* ptr = list;
    LinkedListNode* head = list;
    LinkedListNode* prev;
    int count = 0;
    while(ptr != NULL){
        if(ptr->val <= x){
            if(count == 0){
                LinkedListNode *new_node = new LinkedListNode(ptr->val);
                //new_node->val = ptr->val;
                new_node->next = NULL;
                head = new_node;
            }
            else{
                LinkedListNode *new_node = new LinkedListNode(ptr->val);
                //new_node->val = ptr->val;
                new_node->next = NULL;
                LinkedListNode *temp  = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new_node;
            }
        }
        count++;
        ptr = ptr->next;
    }
    return head;
}

