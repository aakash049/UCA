public class MergeSort extends MySort {
    @Override
    protected void sort() {
        Integer[] aux = new Integer[a.length];
        MergeSort(a, aux, 0, a.length-1);
    }

    private void MergeSort(Integer[] a, Integer[] aux, int l, int h) {
        if(h <= l) return;
        int mid = (l+h) >>> 1;
        MergeSort(a, aux, l, mid);
        MergeSort(a, aux, mid+1, h);
        merge(a, aux, l, mid, h);
    }

    private void merge(Integer[] a, Integer[] aux, int low, int mid, int high) {
        for(int i = low; i <= high; i++) aux[i] = a[i];
        int i = low, j = mid+1;
        for(int k = low; k <= high; k++) {
            if(i > mid) a[k] = aux[j++];
            else if(j > high) a[k] = aux[i++];
            else if(aux[i] < aux[j]) a[k] = aux[i++];
            else a[k] = aux[j++];
        }
    }

    @Override
    public void print() {
        System.out.println("Merge Sort");
        super.print();
    }
}
