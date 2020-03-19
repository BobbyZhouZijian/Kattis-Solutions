import java.util.*;

public class Amanda {

    static class Edge {
        int u;
        int v;
        int c;
        public Edge(int u, int v, int c) {
            this.u = u;
            this.v = v;
            this.c = c;
        }
    }

    public static Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
    private static boolean ok;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        Set<Edge> twos = new HashSet<>();
        Set<Edge> zeros = new HashSet<>();

        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            if (c == 2) {
                twos.add(new Edge(a, b, c));
            }

            if (c == 1) {
                if (!map.containsKey(a)) {
                    map.put(a, new HashMap<>());
                }
                map.get(a).put(b, c);

                if (!map.containsKey(b)) {
                    map.put(b, new HashMap<>());
                }

                map.get(b).put(a, c);
            }

            if (c == 0) {
                zeros.add(new Edge(a, b, c));
            }
        }

        int[] lounges = new int[n + 1];
        boolean[] vis = new boolean[n + 1];

        for (int i = 0; i < n + 1; ++i) {
            lounges[i] = 2;
            vis[i] = false;
        }

        int ans = 0;

        settleZeros(lounges, zeros);
        ok = settleTwos(lounges, twos);

        for (int i = 1; i < n + 1; ++i) {
            if (!vis[i] && (lounges[i] == 1 || lounges[i] == 0)) {
                ans += dfs1(lounges, vis, map, i);
            }
        }

        for (int i = 1; i < n + 1; ++i) {
            if (!vis[i] && lounges[i] == 2) {
                lounges[i] = 3;
                ans += dfs2(lounges, vis, map, i).getMin();
            }
        }

        if (ok) System.out.println(ans);
        else System.out.println("impossible");
    }

    public static void settleZeros(int[] lounges, Set<Edge> zeros) {
        for (Edge edge : zeros) {
            lounges[edge.u] = 0;
            lounges[edge.v] = 0;
        }
    }

    public static boolean settleTwos(int[] lounges, Set<Edge> twos) {
        for(Edge edge : twos) {
            int u = edge.u;
            int v = edge.v;

            if (lounges[u] == 0 || lounges[v] == 0) {
                return false;
            }

            else {
                lounges[u] = 1;
                lounges[v] = 1;
            }
        }
        return true;
    }

    public static int dfs1(int[] lounges, boolean[] vis,  Map<Integer, Map<Integer, Integer>> map, int index) {
        if (vis[index]) return 0;
        vis[index] = true;

        int ans = 0;

        if (lounges[index] == 1) {
            ans++;
        }

        Map<Integer, Integer> neighbours = map.get(index);

        if (neighbours == null) return ans;

        for (Integer key : neighbours.keySet()) {
            if (lounges[index] == 1 && lounges[key] == 1) {
                ok = false;
            } else if (lounges[index] == 0 && lounges[key] == 0) {
                ok = false;
            } else {
                if (lounges[index] == 1) {
                    lounges[key] = 0;
                } else if (lounges[index] == 0){
                    lounges[key] = 1;
                }

                ans += dfs1(lounges, vis, map, key);
            }
        }
        return ans;
    }

    static class Pair {
        int a;
        int b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }

        public int getMin() {
            return Math.min(a, b);
        }
    }

    public static Pair dfs2(int[] lounges, boolean[] vis, Map<Integer, Map<Integer, Integer>> map, int index) {
        if (vis[index]) return new Pair(0, 0);
        vis[index] = true;

        int a = 0;
        int b = 0;

        if (lounges[index] == 3) a++;
        else b++;

        Map<Integer, Integer> neighbours = map.get(index);

        if (neighbours == null) return new Pair(0,0);

        for (Integer key : neighbours.keySet()) {
            if (lounges[index] == 3 && lounges[key] == 3) {
                ok = false;
            } else if (lounges[index] == 4 && lounges[key] == 4) {
                ok = false;
            } else {
                if (lounges[index] == 3) {
                    lounges[key] = 4;
                } else {
                    lounges[key] = 3;
                }
                Pair p = dfs2(lounges, vis, map, key);
                a += p.a;
                b += p.b;
            }
        }
        return new Pair(a, b);
    }
}
