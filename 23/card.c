#include <stdio.h>

int isGreater(int x, int y){
    return ((x & 0xf) > (y & 0xf));
}

int isSameNumber(int x, int y){
    return ((x & 0xf) == (y & 0xf));
}

int isSameSuit(int x, int y){
    return ((x & 0xf0) == (y & 0xf0));
}

int main(){
    char arr[53],x = -16,sum = 0;
    for(int i = 1; i <= 52; i++){
        if(i % 13 == 1){
            sum = 0;
            x += 16;
        }
        sum++;
        arr[i] = x + sum;
    }
    int card1, card2 ;
    scanf("%d %d",&card1,&card2);
    printf("%d ",isGreater(arr[card1], arr[card2]));
    printf("%d ",isSameNumber(arr[card1], arr[card2]));
    printf("%d ",isSameSuit(arr[card1], arr[card2]));
}
