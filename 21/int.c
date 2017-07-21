#include <stdio.h>
int lonely(int *arr, int n){
	int x = 0;
	for(int i = 0; i < n; i++) {
			x ^= arr[i];
	}
	return x;
}

int main(void){
	int arr[5] = {1, 2, 3, 1, 3};
	printf("%d",lonely(arr,5));
}
