#include <stdio.h>

int logicalShift(int x, int n){
    return (x >> n & ((1 << 33+~n) + ~1)+1);
    //return (x >> n & ((1 << 32-n) + ~1)+1);
    //return (x >> n & ~(~0 << (32 + (~n+1))));
}

int main(){
    int x,n;
    scanf("%d %d", &x,&n);
    printf("%d", logicalShift(x, n));
}
