import java.util.Scanner;

public class OutOfSorts {
    public int solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        int m = sc.nextInt();
        int a = sc.nextInt();
        int c = sc.nextInt();
        long x0 = sc.nextInt();

        for (int i = 0; i < n; ++i) {
            x0 = (a * x0 + c) % m;
            arr[i] = (int) x0;
        }

        int ans = 0;

        for (int e : arr) {
            if (found(arr, e)) {
                ans++;
            }
        }

        return ans;
    }

    boolean found(int[] arr, int e) {
        int high = arr.length - 1;
        int low = 0;

        while (low < high) {
            int mid = (low + high) / 2;
            int midNum = arr[mid];
            if (midNum == e) return true;
            else if (midNum < e) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return arr[low] == e;
    }

    public static void main(String[] args) {
        OutOfSorts outOfSorts = new OutOfSorts();
        System.out.println(outOfSorts.solve());
    }
}
