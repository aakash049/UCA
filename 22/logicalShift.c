#include <stdio.h>

int logicalShift(int x){
    return (x >> 1 & ((1 << 31)-1)); 
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", logicalShift(x));
}
