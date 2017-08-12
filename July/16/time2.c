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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    printf("QSort : %lf\n",time_elapsed_in_seconds2);
    //printf("Quick Sort is computing %.0lf times faster than selection sort\n",time_elapsed_in_seconds/time_elapsed_in_seconds2);
    for(int i = 16000; i >= 1; i--){
        arr[16000-i] = i;
    }
    clock_t start3 = clock();
    quickSort(arr, 0, 15999);
    clock_t end3 = clock();
    double time_elapsed_in_seconds3 = (end3 - start3)/(double)CLOCKS_PER_SEC;
    printf("Quick Sort : %lf\n",time_elapsed_in_seconds3); 
    return 0;

}
