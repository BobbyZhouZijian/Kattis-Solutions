import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class BuzzWord {
    String s;
    int n;
    int[] nums;
    long mod = (long) Math.pow(2, 48) + 1;

    void initialize(String s) {
        this.s = s.replaceAll(" ", "");
        n = this.s.length();
        nums = new int[n];
    }

    void solve() {

        // convert to ascii
        for (int i = 0; i <n; ++i) {
            nums[i] = s.charAt(i) - 'A';
        }

        // binary search
        int low = 0;
        int high = n - 1;

        int[] ans = new int[n];

        while (low < high) {
            int mid = (low + high + 1) / 2;

            int num = search(mid);
            ans[mid] = num;

            if (num > 1) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        for (int i = 1; i <= low; ++i) {
            if (ans[i] == 0) {
                System.out.println(search(i));
            } else {
                System.out.println(ans[i]);
            }
        }
    }

    int search(int len) {

        // keep track of maximum count
        Map<Long, Integer> map = new HashMap<>();
        int max = 1;

        // rolling hashcode : init
        long init = 0;
        long mult = 1;
        for (int i = 0; i < len; ++i) {
            init = (init * 26 + nums[i]) % mod;
            mult = (mult * 26) % mod;
        }

        map.put(init, 1);

        for (int j = 1; j <= n - len; ++j) {
            init = (init * 26 - nums[j - 1] * mult % mod + mod) % mod;
            init = (init + nums[j + len - 1]) % mod;

            Integer newCount = map.get(init);

            if (newCount == null) {
                newCount = 0;
            }
            newCount++;
            max = Math.max(max, newCount);
            map.put(init, newCount);
        }

        return max;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BuzzWord buzzWord = new BuzzWord();
        while (sc.hasNextLine()) {
            String next = sc.nextLine();
            if (next.equals("")) {
                break;
            }
            buzzWord.initialize(next);
            buzzWord.solve();
            System.out.print("\n");
        }
    }
}
