import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class EnlargingHashTables {
    boolean[] sleves = new boolean[40000];
    List<Integer> primes = new LinkedList<>();

    void preprocess() {
        for (int i = 2; i <= 200; ++i) {
            if (sleves[i]) continue;
            int j = 2;
            while (j * i < 40000) {
                sleves[j * i] = true;
                j++;
            }
        }

        for (int i = 2; i < 40000; ++i) {
            if (!sleves[i]) {
                primes.add(i);
            }
        }
    }

    boolean isPrime(long n) {
        if (n < 40000) {
            return !sleves[(int) n];
        }
        for (Integer i : primes) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void solve(int next) {
        long larger = next * 2;
        while (!isPrime(larger)) {
            larger++;
        }
        if (isPrime(next)) {
            System.out.println(larger);
        } else {
            System.out.println(String.format("%d (%d is not prime)", larger, next));
        }
    }

    public static void main(String[] args) throws IOException {
        EnlargingHashTables tables = new EnlargingHashTables();
        InputReader reader = new InputReader(System.in);
        tables.preprocess();
        while (true) {
            int next = reader.nextInt();
            if (next == 0) return;
            tables.solve(next);
        }
    }
}
