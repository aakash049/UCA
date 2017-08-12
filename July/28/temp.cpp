#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}nn;

nn* addAtBeginning(nn *head, int x){
    nn *point = new nn();
    point->data = x;
    point->next = head;
    head = point;
    return head;
}

void print(nn *head){
    nn *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

nn* deleteAtBeginning(nn *head){
    nn *temp = head;
    if(temp == NULL){
        cout << "empty\n";
        return head;
    }
    head = head->next;
    delete temp;
    temp = NULL;
    return head;
}

int main(void){
    nn* head = NULL;
    nn *var = new nn();
    var->data = 10;
    var->next = NULL;
    head = var;
    for(int i = 0; i < 10; i++){
        int x;
        cin >> x;
        head = addAtBeginning(head, x);
    }
    head = deleteAtBeginning(head);
    print(head);
}
