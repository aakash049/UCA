#include <stdio.h>

void insertion(int* arr, int n){
    for(int i = 1; i < n; i++){
        int j = i-1;
        int val = arr[i];
        while( j >= 0 && val < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

int main(){
    int arr[5] = {5, 4, 1, 2, 3};
    insertion(arr, 5);
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
