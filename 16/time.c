#include <stdio.h>
#include <time.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

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
    printf("Selection Sort : %lf\n",time_elapsed_in_seconds); 
    for(int i = 16000; i >= 1; i--){
        arr[16000-i] = i;
    }
    clock_t start2 = clock();
    qsort(arr, 16000, sizeof(int), cmpfunc);
    clock_t end2 = clock();
    double time_elapsed_in_seconds2 = (end2 - start2)/(double)CLOCKS_PER_SEC;
    printf("Quick Sort : %lf\n",time_elapsed_in_seconds2);
    printf("Quick Sort is computing %.0lf times faster than selection sort\n",time_elapsed_in_seconds/time_elapsed_in_seconds2);
    return 0;
}
