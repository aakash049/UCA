#include <stdio.h>

int getbyte(int x, int n){
    return ((x >> (n << 3)) & 0xff);
}

int main(void){
    int x, n;
    scanf("%d%d", &x,&n);
    printf("%x %x",x,getbyte(x, n));
}
