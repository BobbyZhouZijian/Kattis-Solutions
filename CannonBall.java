import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class CannonBall {

    static class Node {
        double x;
        double y;
        boolean isCannon;
        Node(double x, double y, boolean isCannon) {
            this.x = x;
            this.y = y;
            this.isCannon = isCannon;
        }

        double timeTo(Node o) {
            double dx = x - o.x;
            double dy = y - o.y;
            double dist = Math.sqrt(dx * dx + dy *dy);
            double twalk = dist / 5.0;
            if (isCannon) {
                double t1 = 2.0 + Math.abs(dist - 50) / 5.0;
                return Math.min(t1, twalk);
            }
            return twalk;
        }
    }

    static class Edge implements Comparable<Edge> {
        int node;
        double dist;
        Edge(int node, double dist) {
            this.node = node;
            this.dist = dist;
        }

        @Override
        public int compareTo(Edge o) {
            if (dist == o.dist) {
                return node - o.node;
            }
            return (dist - o.dist) < 0 ? -1 : 1;
        }
    }

    void decreaseKey(TreeSet<Edge> set, double[] dist, int key, double weight) {
        Edge edge = new Edge(key, dist[key]);
        set.remove(edge);
        dist[key] = weight;
        Edge newEdge = new Edge(key, weight);
        set.add(newEdge);
    }

    public double solve() {
        Scanner sc = new Scanner(System.in);

        double x = sc.nextDouble();
        double y = sc.nextDouble();
        Node src = new Node(x, y, false);

        x = sc.nextDouble();
        y = sc.nextDouble();
        Node dest = new Node(x, y, false);

        int n = sc.nextInt() + 2;

        Node[] nodes = new Node[n];

        for (int i = 2; i < n; ++i) {
            nodes[i] = new Node(sc.nextDouble(), sc.nextDouble(), true);
        }

        // dijkstra
        double[] dist =  new double[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(dist, 100000);

        nodes[0] = src;
        nodes[1] = dest;

        TreeSet<Edge> set = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            set.add(new Edge(i, 100000));
        }
        decreaseKey(set, dist, 0, 0);

        while (set.size() > 0) {
            Edge top = set.pollFirst();
            int index = top.node;
            double weight = top.dist;

            if (vis[index]) continue;
            vis[index] = true;

            if (index == 1) break;

            for (int i = 0; i < n; ++i) {
                if (i == index || vis[i]) continue;
                Node nb = nodes[i];
                double time = nodes[index].timeTo(nb);

                if (weight + time < dist[i]) {
                    decreaseKey(set, dist, i, time + weight);
                }
            }
        }

        return dist[1];
    }

    public static void main(String[] args) {
        CannonBall cannonBall = new CannonBall();
        System.out.println(cannonBall.solve());
    }
}
