import java.math.BigInteger;
import java.util.*;

public class Persistent {
    static public void solve(BigInteger bigInteger) {
        BigInteger ten = new BigInteger("10");
        BigInteger zero = new BigInteger("0");
        if (bigInteger.compareTo(ten) < 0) {
            System.out.print(bigInteger.intValue() + 10);
        } else {
            List<Integer> factors = new ArrayList<>();
            boolean divisible = false;
            while (bigInteger.compareTo(ten) >= 0) {
                // System.out.print(bigInteger.toString(10));
                divisible = false;
                for (int i = 9; i >= 2; --i) {
                    BigInteger div = new BigInteger(Integer.toString(i));
                    if (bigInteger.remainder(div).equals(zero)) {
                        divisible = true;
                        bigInteger = bigInteger.divide(div);
                        factors.add(i);
                        break;
                    }
                }

                if (!divisible) {
                    System.out.print("There is no such number.");
                    return;
                }
            }
            factors.add(bigInteger.intValue());

            Collections.sort(factors);
            for (int i : factors) System.out.print(i);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String next = sc.next();
            if (next.equals("-1")) break;
            solve(new BigInteger(next));
            System.out.print("\n");
        }
    }
}
