import java.util.*;

public class RunningMom {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Map<String, Integer> names = new HashMap<>();
        Map<Integer, LinkedList<Integer>> adj = new HashMap<>();
        int[] ind = new int[2 * n];
        int index = 0;
        for (int i = 0; i < n; ++i) {
            String s1 = sc.next();
            String s2 = sc.next();
            if (!names.containsKey(s1)) {
                names.put(s1, index++);
            }
            if (!names.containsKey(s2)) {
                names.put(s2, index++);
            }

            int id1 = names.get(s1);
            int id2 = names.get(s2);

            ind[id1]++;
            if (!adj.containsKey(id2)) {
                adj.put(id2, new LinkedList<>());
            }
            adj.get(id2).add(id1);
        }

        Queue<Integer> q = new LinkedList<>();

        index++;

        for (int i = 0; i < index; ++i) {
            if (ind[i] == 0) {
                q.add(i);
            }
        }

        boolean[] danger = new boolean[index];

        while (!q.isEmpty()) {
            int top = q.poll();

            danger[top] = true;

            if (adj.containsKey(top)) {
                for (Integer nb : adj.get(top)) {
                    ind[nb]--;

                    if (ind[nb] == 0) {
                        q.add(nb);
                    }
                }
            }
        }

        while (sc.hasNext()) {
            String cur = sc.next();
            int id = names.get(cur);
            if (danger[id]) {
                System.out.println(String.format("%s %s", cur, "trapped"));
            } else {
                System.out.println(String.format("%s %s", cur, "safe"));
            }
        }
    }
}
