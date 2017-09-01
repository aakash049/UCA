#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void insertAtEnd(struct node** headRef, int newData)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = newData;
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
void insertAtBegining(struct node** headRef, int newData)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = newData;
    new_node->next = *headRef;
    *headRef = new_node;
}
void print(struct node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        struct node *head1 = NULL;
        struct node *head2 = NULL;
        int size1, size2, x;
        cin >> size1 >> size2;
        while(size1--){
            cin >> x;
            insertAtBegining(&head1, x);
        }
        while(size2--){
            cin >> x;
            insertAtBegining(&head2, x);
        }
        int sum = 0, carry = 0;
        struct node *head3 = NULL;
        while(head1 && head2){
            int sum = (head1->data + head2->data + carry)%10;
            carry = (head1->data + head2->data + carry)/10;
            insertAtBegining(&head3, sum);
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1){
            insertAtBegining(&head3, (head1->data+carry)%10);
            carry = (head1->data + carry)/10;
            head1 = head1->next;
        }
        while(head2){
            insertAtBegining(&head3, (head2->data+carry)%10);
            carry = (head2->data + carry)/10;
            head2 = head2->next;
        }
        if(carry)
            insertAtBegining(&head3, carry);
        print(head3);
        cout << endl;
    }
}