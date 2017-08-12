#include <stdio.h>

int conditional(int x, int y, int z){
    return (((!(!x) << 31) >> 31 & y) ^ ((!x << 31) >> 31 & z));
}

int main(){
    int x, y, z;
    scanf("%d%d%d",&x, &y, &z);
    printf("%d",conditional(x,y,z));
}
