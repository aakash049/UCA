public class MergeSort {
    public static void Merge(int[] arr, int l, int m, int r) {
        int size1 = m-l+1, size2 = r-m;
        int aux1[] = new int[size1];
        int aux2[] = new int[size2];
        for(int i = 0; i < size1; i++) aux1[i] = arr[l+i];
        for(int i = 0; i < size2; i++) aux2[i] = arr[m+i+1];
        int i = 0, j = 0, k = l;
        while(i < size1 && j < size2) {
            if(aux1[i] < aux2[j]) arr[k++] = aux1[i++];
            else arr[k++] = aux2[j++];
        }
        while(i < size1) arr[k++] = aux1[i++];
        while(j < size2) arr[k++] = aux2[j++];
        
    }
    public static void Msort(int[] arr, int l, int r) {
        if(l >= r) return;
        int mid = (l+r)/2;
        Msort(arr, l, mid);
        Msort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }
    public static void main(String[] args) {
        //int[] arr = {5, 2, 3, 1, 4, 8};
        int[] arr = {2, 1, 3, 1, 2};
        Msort(arr, 0, arr.length-1);
        for(int i = 0; i < arr.length; i++) System.out.println(arr[i]);
    }
}
