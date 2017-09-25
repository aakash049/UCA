public abstract class MySort {
	protected Integer[] a = null;
	protected abstract void sort();

	protected void setInput(Integer[] a) {
		this.a = a;
	}

	protected void swap(int i, int j) {
		Integer temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	protected void print() {
		StringBuilder sb = new StringBuilder("[");
		for (int e : a) {
			sb.append(e);
			sb.append(",");
		}
		sb.deleteCharAt(sb.length() - 1);
		sb.append("]");
		System.out.println(sb.toString());
	}
}
