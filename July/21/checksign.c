#include <stdio.h>

int checksign(int x){
    return !(x & (1 << 31));
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", checksign(x));
}
