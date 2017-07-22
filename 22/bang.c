#include <stdio.h>

int bang(int x){
    //return ((x ^ 0xffffffffU) + 1UL) >> 32;
    return 1 >> x;
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d  %d",bang(x),!x);
}
