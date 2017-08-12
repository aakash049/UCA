#include <stdio.h>

int arr[7];
int front = -1;
int rear = -1;

void enq(int x){
    if(rear == 6){
        printf("OVERFLOW\n");
        return;
    }
    arr[++rear] = x;
    front = 2;
}

int deq(){
    if(front == -1){
        printf("UNDERFLOW");
        return -1;
    }
    return (arr[front--]);
}

int main(){
    enq(10);
    enq(20);
    enq(30);
    printf("%d\n", deq());
    printf("%d\n", deq());
    printf("%d\n", deq());
}:
