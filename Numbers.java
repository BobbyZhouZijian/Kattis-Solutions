import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Numbers {

    static Map<Integer, BigInteger> memo = new HashMap<>();

    static BigInteger nthCatalan(int n) {
        BigInteger upper, lower1, lower2;
        if (memo.containsKey(2 * n)) {
            upper = memo.get(2 * n);
        } else {
            upper = factorial(2 * n);
        }

        if (memo.containsKey(n)) {
            lower1 = memo.get(n);
        } else {
            lower1 = factorial(n);
        }

        if (memo.containsKey(n + 1)) {
            lower2 = memo.get(n + 1);
        } else {
            lower2 = factorial(n + 1);
        }

        return upper.divide(lower1.multiply(lower2));
    }

    static BigInteger factorial(int n) {
        BigInteger b = new BigInteger("1");
        if (n == 0) return b;
        int cur = n;
        while (cur > 1) {
            if (memo.containsKey(cur)) {
                b = b.multiply(memo.get(cur));
                cur = 0;
            } else {
                b = b.multiply(new BigInteger(Integer.toString(cur--)));
            }
        }
        memo.put(n, b);
        return b;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        while (cases-- > 0) {
            int n = sc.nextInt();
            System.out.println(nthCatalan(n).toString());
        }
    }
}
