public class QuickSort extends MySort {

	@Override
	protected void sort() {
		quicksort(0, a.length - 1);
	}

	private void quicksort(int left, int right) {
		if (left >= right)
			return;
		int last = left;
		for (int i = left + 1; i <= right; i++) {
            if (a[i].compareTo(a[left]) < 0) {
				swap(++last, i);
			}
		}
		swap(left, last);
		quicksort(left, last - 1);
		quicksort(last + 1, right);
	}

	@Override
	public void print() {
		System.out.println("Quick sort");
		super.print();
	}
}
