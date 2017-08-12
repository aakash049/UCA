#include <stdio.h>

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int a = (~x & y);
    int b = (x & ~y);
    int z = ~(~ a & ~b);
    //int z = ~x & ~y;
    printf("%d  %d",z,x^y);
}
