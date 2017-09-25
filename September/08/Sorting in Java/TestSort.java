public class TestSort {

	public static void main(String[] args) {
		MySort d = new MergeSort();
		Integer[] b = { 3, 5, 2, 7, 7 };
		d.setInput(b);
		d.sort();
		d.print();
	}
}
