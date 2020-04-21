import java.io.IOException;
import java.util.HashSet;

public class Shiritori {
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader(System.in);

        int n = reader.nextInt();
        HashSet<String> set = new HashSet<>();

        String last = reader.nextString();
        set.add(last);

        for (int i = 1; i < n; ++i) {
            String cur = reader.nextString();
            if (cur.charAt(0) != last.charAt(last.length() - 1) || set.contains(cur)) {
                System.out.println(String.format("Player %d lost", i % 2 + 1));
                return;
            }
            last = cur;
            set.add(last);
        }
        System.out.println("Fair Game");
    }
}
