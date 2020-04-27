import java.util.Arrays;

class ZigZag {
	protected int[] arr;
	
	public ZigZag(int[] arr) {
		this.arr = arr;
	}

	public void sort() {
		Arrays.sort(arr);
		int[] newArr = new int[arr.length];
		int i = 0;
		int j = arr.length - 1;
		int cur = 0;
		while (i < j) {
			newArr[cur++] = arr[i++];
			newArr[cur++] = arr[j--];
		}
		if (i == j) newArr[cur] = arr[i];
		arr = newArr;
	}
}