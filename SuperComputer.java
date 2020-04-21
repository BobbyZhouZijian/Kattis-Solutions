import java.util.Scanner;

public class SuperComputer {
    boolean[] bits;
    int[] biTree;
    int n;

    void update(int i) {
        int change = bits[i] ? -1 : 1;
        bits[i] = !bits[i];
        while (i <= n) {
            biTree[i] += change;
            i += i & (-i);
        }
    }

    int get(int i) {
        int ans = 0;
        while (i > 0) {
            ans += biTree[i];
            i -= i & (-i);
        }
        return ans;
    }

    SuperComputer(int n) {
        this.n = n;
        bits = new boolean[n + 5];
        biTree = new int[n + 5];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();

        SuperComputer superComputer = new SuperComputer(n);

        for (int i = 0; i < q; ++i) {
            String op = sc.next();

            if (op.equals("F")) {
                superComputer.update(sc.nextInt());
            } else {
                System.out.println(-superComputer.get(sc.nextInt() - 1) + superComputer.get(sc.nextInt()));
            }
        }
    }
}
