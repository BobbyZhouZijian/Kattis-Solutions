import java.util.*;

public class ImportSpaghetti {
    static int inf = 1 << 29;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        HashMap<String, Integer> names = new HashMap<>();
        HashMap<Integer, String> index = new HashMap<>();
        HashMap<Integer, LinkedList<Integer>> adj = new HashMap<>();

        String[] strs = sc.nextLine().split(" ");

        for (int i = 0; i < n; ++i) {
            String cur = strs[i];
            names.put(cur, i);
            index.put(i, cur);
        }

        for (int i = 0; i < n; ++i) {
            String[] next = sc.nextLine().split(" ");
            int k = names.get(next[0]);
            int num = Integer.parseInt(next[1]);

            if (!adj.containsKey(k)) {
                adj.put(k, new LinkedList<>());
            }


            for (int j = 0; j < num; ++j) {

                String[] line = sc.nextLine().split(" ");
                int len = line.length;
                for (int l = 1; l < len; l++) {
                    if (l == len - 1) {
                        int cur = names.get(line[l]);
                        adj.get(k).add(cur);
                        continue;
                    }
                    String in = line[l].substring(0, line[l].length() - 1);
                    int cur = names.get(in);
                    adj.get(k).add(cur);
                }
            }
        }

        int count = inf;
        List<Integer> ans = new LinkedList<>();

        for (int i = 0; i < n; ++i) {
            List<Integer> cur = bfs(adj, i, n);
            if (cur.size() > 0 && cur.size() < count) {
                count = cur.size();
                ans = cur;
            }
        }

        if (count == inf) {
            System.out.println("SHIP IT");
        } else {
            for (int i : ans) {
                System.out.print(index.get(i) + " ");
            }
        }
    }

    static List<Integer> bfs(HashMap<Integer, LinkedList<Integer>> adj, int index, int n) {
        int[] parent = new int[n];
        boolean[] vis = new boolean[n];

        Queue<Integer> q = new LinkedList<>();
        boolean found = false;

        if (adj.containsKey(index)) {
            for (int nb : adj.get(index)) {
                q.add(nb);
                parent[nb] = index;

                if (nb == index) {
                    found = true;
                    break;
                }
            }
        }

        while (!q.isEmpty()) {
            int top = q.poll();

            if (found) {
                break;
            }

            if (vis[top]) continue;
            vis[top] = true;

            if (adj.containsKey(top)) {
                for (int nb : adj.get(top)) {
                    if (!vis[nb]) {
                        parent[nb] = top;
                        q.add(nb);

                        if (nb == index)  {
                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        List<Integer> ans = new LinkedList<>();

        if (found) {
            int trav = parent[index];
            while (trav != index) {
                ans.add(trav);
                trav = parent[trav];
            }
            ans.add(index);
        }
        Collections.reverse(ans);
        return ans;
    }
}