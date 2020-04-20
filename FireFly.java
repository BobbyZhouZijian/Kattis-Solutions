import java.util.*;

public class FireFly {

    public void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int[] ups = new int[n / 2];
        int[] downs = new int[n / 2];
        for (int i = 0; i < n / 2; ++i) {
            ups[i] = sc.nextInt();
            downs[i] = h - sc.nextInt();
        }

        Arrays.sort(ups);
        Arrays.sort(downs);

        Stack<Integer> s1 = new Stack<>(), s2 = new Stack<>();

        for (int i = n / 2 - 1; i >= 0; --i) {
            s1.add(ups[i]);
            s2.add(downs[i]);
        }

        int level = 1;
        int accum = s1.size();

        int min = Integer.MAX_VALUE;
        Map<Integer, Integer> map = new HashMap<>();


        while (level <= h) {
            int h2 = h, h1 = h;
            while (!s2.isEmpty()) {
                h2 = s2.peek();
                if (h2 < level) {
                    s2.pop();
                    accum++;
                } else {
                    break;
                }
            }

            while (!s1.isEmpty()) {
                h1 = s1.peek();
                if (h1 < level) {
                    s1.pop();
                    accum--;
                } else {
                    break;
                }
            }

            int curCount = accum;
            min = Math.min(min, curCount);
            int next = Math.min(h1, h2) + 1;

            if (!map.containsKey(curCount)) {
                map.put(curCount, next - level);
            } else {
                map.put(curCount, map.get(curCount) + next - level);
            }
            level = next;
        }

        System.out.println(String.format("%d %d", min, map.get(min)));
    }

    public static void main(String[] args) {
        FireFly fireFly = new FireFly();
        fireFly.solve();
    }
}
