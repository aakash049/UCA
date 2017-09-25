public class Bubble {
    public static void main(String[] arg) {
        int[] arr = {5, 3, 1, 10, 6};
        for(int i = 0; i < arr.length-1; i++) {
            for(int j = i+1; j < arr.length; j++) {
                if(arr[i] > arr[j]){
                    swap(arr, i, j);
                }
            }
        }
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);
    }
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
