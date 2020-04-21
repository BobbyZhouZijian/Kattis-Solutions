import java.io.IOException;
import java.util.*;

public class FloweryTrials {

    static class Node implements Comparable<Node> {
        int node;
        int w;
        Node(int node, int w) {
            this.node = node;
            this.w = w;
        }

        @Override
        public int compareTo(Node o) {
            if (w == o.w) {
                return node - o.node;
            }
            return w - o.w;
        }
    }

    public static void main(String[] args) throws IOException {

        InputReader reader = new InputReader(System.in);

        int v = reader.nextInt();
        int e = reader.nextInt();

        int[] dist = new int[v];
        Arrays.fill(dist, Integer.MAX_VALUE);

        Map<Integer, LinkedList<Node>>
                adj = new HashMap<>(),
                parent = new HashMap<>();

        for (int i = 0; i < e; ++i) {
            int u1 = reader.nextInt();
            int u2 = reader.nextInt();
            int w = reader.nextInt();

            if (!adj.containsKey(u1)) {
                adj.put(u1, new LinkedList<>());
            }
            if (!adj.containsKey(u2)) {
                adj.put(u2, new LinkedList<>());
            }

            adj.get(u1).add(new Node(u2, w));
            adj.get(u2).add(new Node(u1, w));
        }

        TreeSet<Node> set = new TreeSet<>();

        for (int i = 1; i < v; ++i) {
            set.add(new Node(i, Integer.MAX_VALUE));
        }
        set.add(new Node(0, 0));
        dist[0] = 0;
        boolean[] vis = new boolean[v];

        while (!set.isEmpty()) {
            Node top = set.pollFirst();
            int index = top.node;
            if (vis[index]) continue;
            vis[index] = true;

            if (adj.containsKey(index)) {
                for (Node nb : adj.get(index)) {
                    int nbIndex = nb.node;
                    if (dist[index] + nb.w < dist[nbIndex]) {
                        set.remove(new Node(nbIndex, dist[nbIndex]));
                        dist[nbIndex] = dist[index] + nb.w;
                        set.add(new Node(nbIndex, dist[nbIndex]));
                        if (!parent.containsKey(nbIndex)) {
                            parent.put(nbIndex, new LinkedList<>());
                        }
                        parent.get(nbIndex).clear();
                        parent.get(nbIndex).add(new Node(index, nb.w));
                    } else if (dist[index] + nb.w == dist[nbIndex]) {
                        if (!parent.containsKey(nbIndex)) {
                            parent.put(nbIndex, new LinkedList<>());
                        }
                        parent.get(nbIndex).add(new Node(index, nb.w));
                    }
                }
            }
        }

        Queue<Integer> q = new LinkedList<>();
        q.add(v - 1);

        long ans = 0;
        Arrays.fill(vis, false);

        while (!q.isEmpty()) {
            int top = q.poll();

            if (vis[top]) continue;
            vis[top] = true;

            if (parent.containsKey(top)) {
                for (Node nb : parent.get(top)) {
                    ans += nb.w;
                    q.add(nb.node);
                }
            }
        }

        System.out.println(ans * 2);
    }
}
