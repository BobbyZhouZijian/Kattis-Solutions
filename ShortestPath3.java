import java.util.*;

public class ShortestPath3 {

    static class Pair {
        int u;
        int v;
        int weight;
        public Pair(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int q = sc.nextInt();
            int s = sc.nextInt();

            if (n == 0 && m == 0 && q == 0 && s == 0) break;

            int[] dis = new int[n];
            List<Pair> list = new LinkedList<>();
            Arrays.fill(dis, Integer.MAX_VALUE);
            dis[s] = 0;
            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();

                list.add(new Pair(u, v, w));
            }

            // relax
            for (int i = 1; i < n; ++i) {
                for (Pair p : list) {
                    if (dis[p.u] != Integer.MAX_VALUE && dis[p.u] + p.weight < dis[p.v]) {
                        dis[p.v] = dis[p.u] + p.weight;
                    }
                }
            }

            // detect negative cycle
            boolean negative = false;
            for (Pair p : list) {
                if (dis[p.u] == Integer.MIN_VALUE || (dis[p.u] != Integer.MAX_VALUE && dis[p.u] + p.weight < dis[p.v])) {
                    dis[p.v] = Integer.MIN_VALUE;
                    negative = true;
                }
            }

            if (negative) {
                for (int i = 1; i < n; ++i) {
                    for (Pair p : list) {
                        if (dis[p.u] == Integer.MIN_VALUE || (dis[p.u] != Integer.MAX_VALUE && dis[p.u] + p.weight < dis[p.v])) {
                            dis[p.v] = Integer.MIN_VALUE;
                        }
                    }
                }
            }

            for (int i = 0; i < q; ++i) {
                int next = sc.nextInt();
                if (dis[next] == Integer.MIN_VALUE) {
                    System.out.println("-Infinity");
                } else if (dis[next] == Integer.MAX_VALUE) {
                    System.out.println("Impossible");
                } else {
                    System.out.println(dis[next]);
                }
            }
            System.out.print("\n");
        }
    }
}
