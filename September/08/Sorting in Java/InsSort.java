public class InsSort extends MySort {

	@Override
	protected void sort() {
		for (int i = 1; i < a.length; i++) {
			Integer key = a[i];
			for (int j = i - 1; j >= 0; j--) {
				if (key.compareTo(a[j]) < 0) {
					swap(j, j + 1);
				}
			}
		}
	}

	@Override
	public void print() {
		System.out.println("Insertion sort");
		super.print();
	}
}
