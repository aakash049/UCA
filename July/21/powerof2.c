#include <stdio.h>

int powerof2(int x){
	return (!( x & (x - 1)));
}

int main(){
	int x;
    scanf("%d", &x);
	if(powerof2(x))
		printf("YES");
	else
		printf("NO");
}
