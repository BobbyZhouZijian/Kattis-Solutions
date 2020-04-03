import java.util.*;

public class GetShorty {

    static class Edge implements Comparable<Edge> {
        int u;
        double weight;
        public Edge(int u, double weight) {
            this.u = u;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            if (weight == o.weight) {
                return u - o.u;
            }
            if (weight > o.weight) return -1;
            else return 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();
            int m = sc.nextInt();

            if (n == 0 && m == 0) break;

            Map<Integer, List<Edge>> map = new HashMap<>();
            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                double w = sc.nextDouble();

                if (!map.containsKey(u)) {
                    map.put(u, new LinkedList<>());
                }
                map.get(u).add(new Edge(v, w));

                if (!map.containsKey(v)) {
                    map.put(v, new LinkedList<>());
                }
                map.get(v).add(new Edge(u, w));
            }

            double[] dist = new double[n];
            boolean[] settled = new boolean[n];
            dist[0] = 1.0;

            // dijkstra
            PriorityQueue<Edge> pq = new PriorityQueue<>();
            pq.add(new Edge(0, 1.0));

            while (!pq.isEmpty()) {
                Edge top = pq.poll();

                settled[top.u] = true;

                int u = top.u;
                double w = top.weight;

                if (top.u == n - 1) {
                    break;
                }

                for (Edge edge : map.get(top.u)) {
                    if (!settled[edge.u]) {
                        if (edge.weight * w > dist[edge.u]) {
                            dist[edge.u] = edge.weight * w;
                            pq.remove(top);
                            pq.add(new Edge(edge.u, w * edge.weight));
                        }
                    }
                }
            }

            System.out.println(String.format("%.4f", dist[n - 1]));
    }
    }
}
