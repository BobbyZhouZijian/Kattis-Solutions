import java.io.IOException;
import java.util.HashSet;

public class CD {
    static InputReader reader = new InputReader(System.in);

    int solve(int n, int m) throws IOException {
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            set.add(reader.nextInt());
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (set.contains(reader.nextInt())) ans++;
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        CD cd = new CD();
        while (true) {
            int n = reader.nextInt();
            int m = reader.nextInt();

            if (n == 0 && m == 0) break;
            System.out.println(cd.solve(n, m));
        }
    }
}
