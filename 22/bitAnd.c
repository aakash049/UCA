#include <stdio.h>

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int z = ~x | ~y;
    printf("%d  %d",~z,x&y);
}
