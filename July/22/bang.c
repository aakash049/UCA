#include <stdio.h>

int bang(int x){
    //return 1 >> (x%31);
    return ((x >> 31) + 0x01) & ((~x+1) >> 31 + 0x01);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d  %d",bang(x),!x);
}
