import java.util.Scanner;

public class NumberTree {
    public int solve() {
        Scanner sc = new Scanner(System.in);
        int h = sc.nextInt();
        String moves;
        if (sc.hasNext()) {
            moves = sc.next();
        } else {
            moves = "";
        }

        int len = moves.length();
        int pos = 0;
        for (int i = 0; i < len; ++i) {
            pos <<= 1;
            if (moves.charAt(i) == 'L') {
                pos++;
            }
        }

        int diff = h - len;
        int ans = 0;
        for (int i = 0; i < diff; ++i) {
            ans += 1 << h;
            h--;
        }
        ans += pos + 1;

        return ans;
    }

    public static void main(String[] args) {
        NumberTree numberTree = new NumberTree();
        System.out.println(numberTree.solve());
    }
}
