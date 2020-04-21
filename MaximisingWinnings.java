import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class MaximisingWinnings {
    static Pair bfs(int r, int step, int n, int[][] map, Map<Pair, Pair> dp) {
        if (step == 0) return new Pair(0, 0);
        Pair p = new Pair(r ,step);
        if (dp.containsKey(p)) return dp.get(p);
        int max = -1, min = (int) 1e9;
        for (int r2 = 0; r2 < n; ++r2) {
            Pair next = bfs(r2, step - 1, n, map, dp);
            max = Math.max(max, next.u + map[r][r2]);
            min = Math.min(min, next.v + map[r][r2]);
        }
        dp.put(p, new Pair(max, min));
        return dp.get(p);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;
            int[][] map = new int[n][n];
            Map<Pair, Pair> dp = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) map[i][j] = sc.nextInt();
            }
            int step = sc.nextInt();
            Pair p = bfs(0, step, n, map, dp);
            System.out.println(String.format("%d %d", p.u, p.v));
        }
    }
}

class Pair {
    int u;
    int v;
    public Pair(int u, int v) {
        this.u = u;
        this.v = v;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) return true;
        if (obj == null) return false;
        if (getClass() != obj.getClass()) return false;
        Pair p = (Pair) obj;
        return u == p.u && v == p.v;
    }

    @Override
    public int hashCode() {
        String str = String.format("%d,%d", u,v);
        return str.hashCode();
    }
}
