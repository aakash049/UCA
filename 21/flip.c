#include <stdio.h>

int flip(int x, int n, int p) {
    return ((~(~0 << n) << p ) ^ x);
}

int main(){
    int x = 204,n=3,p=2;
    printf("%d",flip(x,n,p));
    return 0;
}
