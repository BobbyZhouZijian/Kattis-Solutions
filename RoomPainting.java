import java.util.Arrays;
import java.util.Scanner;

public class RoomPainting {
    public long solve() {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int n = sc.nextInt();

        int[] arr = new int[m];

        for (int i = 0; i < m; ++i) {
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        long ans = 0;

        for (int i = 0; i < n; ++i) {
            int cur = sc.nextInt();
            int b = binary(arr, cur);
            ans += b - cur;
        }

        return ans;
    }

    int binary(int[] arr, int n) {
        int low = 0;
        int high = arr.length - 1;

        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < n) {
                low = mid + 1;
            } else if (arr[mid] == n) {
                return n;
            } else {
                high = mid;
            }
        }
        return arr[high];
    }

    public static void main(String[] args) {
        RoomPainting roomPainting = new RoomPainting();
        System.out.println(roomPainting.solve());
    }
}
