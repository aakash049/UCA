public class MergeSort2 {
    public static void p(Object line) {
            System.out.println(line);
    }
    public static long Merge(int[] arr, int l, int m, int r) {
        int size1 = m-l+1, size2 = r-m;
        long count = 0;
        int aux1[] = new int[size1];
        int aux2[] = new int[size2];
        for(int i = 0; i < size1; i++) aux1[i] = arr[l+i];
        for(int i = 0; i < size2; i++) aux2[i] = arr[m+i+1];
        int i = 0, j = 0, k = l;
        while(i < size1 && j < size2) {
            if(aux1[i] <= aux2[j]) arr[k++] = aux1[i++];
            else {
                arr[k++] = aux2[j++];
                count += (m-i+1);
                //p(m-i);
            }
        }
        while(i < size1) arr[k++] = aux1[i++];
        while(j < size2) arr[k++] = aux2[j++];
        return count;
    }
    public static long Msort(int[] arr, int l, int r) {
        long count = 0;
        if(l >= r) return count;
        int mid = (l+r)/2;
        count += Msort(arr, l, mid);
        count += Msort(arr, mid+1, r);
        count += Merge(arr, l, mid, r);
        return count;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 10, 4, 5};
        long count = Msort(arr, 0, arr.length-1);
        System.out.println(count);
    }
}
