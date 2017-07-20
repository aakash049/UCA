#include <stdio.h>
#include <assert.h>

void selection(int *arr, int n) {
    int min = 0;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void test(int* arr, int* out, int n) {
    for(int i = 0; i < n; i++) {
        assert(arr[i] == out[i]);
    }
    printf("Success\n");
} 

int main() {
    int arr[5] = {5, 7, 1, 8, 3};
    selection(arr, 5);
    int out[5] = {1, 3, 5, 7, 8};
    test(arr,out,5);
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
	printf("\n");
}
