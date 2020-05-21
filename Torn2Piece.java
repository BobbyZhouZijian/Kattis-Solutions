import java.util.*;

public class Torn2Piece {

    static class Pair {
        String node;
        Pair parent;
        Pair(String node, Pair parent) {
            this.node= node;
            this.parent = parent;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String, HashSet<String>> map = new HashMap<>();
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; ++i) {
            String[] strs = sc.nextLine().split(" ");
            String cur = strs[0];
            if (!map.containsKey(cur)) map.put(cur, new HashSet<>());
            int len = strs.length;

            for (int j = 1; j < len; ++j) {
                String o = strs[j];
                map.get(cur).add(o);

                if (!map.containsKey(o)) {
                    map.put(o, new HashSet<>());
                }
                map.get(o).add(cur);
            }
        }

        // dfs
        String[] queries = sc.nextLine().split(" ");
        Pair start = new Pair(queries[1], null);

        dfs(start, queries[0], map);

        if (dest == null) {
            System.out.println("no route found");
        } else {
            while (dest != null) {
                System.out.print(dest.node + " ");
                dest = dest.parent;
            }
        }
    }

    static Pair dest = null;
    static HashSet<String> vis = new HashSet<>();

    static void dfs(Pair cur, String end, Map<String, HashSet<String>> map) {
        if (cur.node.equals(end)) {
            dest = cur;
            return;
        }
        if (dest != null || vis.contains(cur.node)) {
            return;
        }

        vis.add(cur.node);

        if (map.containsKey(cur.node)) {
            for (String nb : map.get(cur.node)) {
                dfs(new Pair(nb, cur), end, map);
            }
        }
    }
}
