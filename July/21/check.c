// checks sign of an integer
#include <stdio.h>

int check(int x){
    return ((x >> 31) | !(!x));   
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d", x);
}
