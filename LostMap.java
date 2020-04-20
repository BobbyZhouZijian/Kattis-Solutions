import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;

public class LostMap {

    static class Node implements Comparable<Node> {
        int index;
        int weight;
        Node(int index, int weight) {
            this.index = index;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return weight == o.weight
                    ? index - o.index
                    : weight - o.weight;
        }
    }

    void decreaseKey(TreeSet<Node> set, int[] dist, int index, int weight) {
        Node node = new Node(index, dist[index]);
        set.remove(node);
        dist[index] = weight;
        set.add(new Node(index, weight));
    }

    public void solve() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] map = new int[n][n];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                map[i][j] = sc.nextInt();
            }
        }

        // mst
        TreeSet<Node> set = new TreeSet<>();
        Map<Integer, Integer> parent = new HashMap<>();
        int[] dist = new int[n];
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            set.add(new Node(i, Integer.MAX_VALUE));
            dist[i] = Integer.MAX_VALUE;
        }

        decreaseKey(set, dist, 0, 0);

        while (!set.isEmpty()) {
            Node top = set.pollFirst();
            int index = top.index;
            int w = top.weight;
            if (vis[index]) continue;
            vis[index] = true;

            for (int i = 0; i < n; ++i) {
                if (vis[i] || map[index][i] == 0) continue;
                int newDist = map[index][i];

                if (newDist < dist[i]) {
                    decreaseKey(set, dist, i, newDist);
                    parent.put(i, index);
                }
            }
        }

        for (Map.Entry<Integer, Integer> entry : parent.entrySet()) {
            System.out.println(String.format("%d %d", entry.getKey() + 1, entry.getValue() + 1));
        }
    }

    public static void main(String[] args) {
        LostMap lostMap = new LostMap();
        lostMap.solve();
    }
}
