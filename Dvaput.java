import java.util.HashSet;
import java.util.Scanner;

public class Dvaput {
    int n;
    String s;
    int[] nums;
    long mod = (long) Math.pow(2, 48) + 1;

    Dvaput(int n, String s) {
        this.n = n;
        this.s = s;
        nums = new int[n];
    }

    int solve() {

        // store the hashcode of characters
        for (int i = 0; i < n; ++i) {
            nums[i] = s.charAt(i) - 'a';
        }

        // binary search
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (matched(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    boolean matched(int len) {
        // use rolling hash to find repeated pattern
        HashSet<Long> set = new HashSet<>();

        // rolling hashcode : init
        long init = 0;
        long mult = 1;
        for (int i = 0; i < len; ++i) {
            init = (init * 26 + nums[i]) % mod;
            mult = (mult * 26) % mod;
        }

        set.add(init);

        // perform hashing
        for (int j = 1; j <= n - len; ++j) {
            init = (init * 26 - nums[j - 1] * mult % mod) % mod;
            init = (init + nums[j + len - 1]) % mod;

            if (set.contains(init)) {
                return true;
            }
            set.add(init);
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Dvaput dvaput = new Dvaput(sc.nextInt(), sc.next());
        System.out.println(dvaput.solve());
    }
}
