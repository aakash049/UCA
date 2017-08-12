#include <stdio.h>

int Add(int x, int y)
{
	if (y == 0)
		return x;
	else
		return Add( x ^ y, (x & y) << 1);
}

int main(){
    printf("%d", Add(19, 35));
    return 0;
}