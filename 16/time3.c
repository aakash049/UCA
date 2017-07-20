#include <stdio.h>
#include <time.h>

void selection(int *arr, int n) {
    int min = 0;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(){
    int arr[16000];
    for(int i = 16000; i >= 1; i--){
        arr[16000-i] = i;
    }
    clock_t start = clock();    
    selection(arr,16000);
    clock_t end = clock();
    double time_elapsed_in_seconds = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Selection Sort 16000 : %lf\n",time_elapsed_in_seconds);
    int arr2[32000]; 
    for(int i = 32000; i >= 1; i--){
        arr[32000-i] = i;
    }
    clock_t start2 = clock();
    selection(arr2,32000);
    clock_t end2 = clock();
    double time_elapsed_in_seconds2 = (end2 - start2)/(double)CLOCKS_PER_SEC;
    printf("Selection Sort 32000 : %lf\n",time_elapsed_in_seconds2);
    return 0;
}
