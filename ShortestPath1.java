package exam;

import java.util.*;

public class ShortestPath1 {

    static class Pair implements Comparable<Pair> {
        int p, dis;
        public Pair(int p, int dis) {
            this.p = p;
            this.dis = dis;
        }

        @Override
        public int compareTo(Pair o) {
            return dis - o.dis;
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
            Map<Integer, List<Pair>> map = new HashMap<>();
            Pair[] nodes = new Pair[n];
            boolean[] vis = new boolean[n];
            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();

                if (!map.containsKey(u)) map.put(u, new LinkedList<>());
                map.get(u).add(new Pair(v, w));
            }

            // run dijkstra
            int[] dis = new int[n];
            Arrays.fill(dis, Integer.MAX_VALUE);
            dis[s] = 0;
            PriorityQueue<Pair> pq = new PriorityQueue<>();
            pq.add(new Pair(s, 0));

            while (!pq.isEmpty()) {
                Pair top = pq.poll();
                dis[top.p] = top.dis;
                vis[top.p] = true;
                if (!map.containsKey(top.p)) continue;
                for (Pair d : map.get(top.p)) {
                    if (vis[d.p]) continue;
                    if (d.dis + dis[top.p] < dis[d.p]) {
                        dis[d.p] = d.dis + dis[top.p];
                    }
                    if (nodes[d.p] != null) {
                        pq.remove(nodes[d.p]);
                    }
                    Pair newNode= new Pair(d.p, dis[d.p]);
                    pq.add(newNode);
                    nodes[d.p] = newNode;
                }
            }
            for (int i = 0; i < q; ++i) {
                int query = sc.nextInt();
                if (dis[query] == Integer.MAX_VALUE) System.out.println("Impossible");
                else System.out.println(dis[query]);
            }
            System.out.print("\n");
        }
    }
}
