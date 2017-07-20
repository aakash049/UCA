#include <stdio.h>

void insertion(int* arr, int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        while( j >= 0 && arr[i] < arr[j]){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
        }
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
