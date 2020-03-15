import java.util.*;

class KattisQuest {

    static class Gold implements Comparable<Gold> {
        int gold;
        int timeStamp;
        public Gold(int gold, int timeStamp) {
            this.gold = gold;
            this.timeStamp = timeStamp;
        }

        @Override
        public int compareTo(Gold o) {
            if (gold == o.gold) {
                return o.timeStamp - timeStamp;
            }
            return o.gold - gold;
        }
    }

    public static void main(String[] args) {
        TreeMap<Integer, PriorityQueue<Gold>> map = new TreeMap<>();
        Scanner sc = new Scanner(System.in);
        int queries = sc.nextInt();
        for (int i = 0; i < queries; ++i) {
            String action = sc.next();
            if (action.equals("add")) {
                int e = sc.nextInt();
                int g = sc.nextInt();
                if (!map.containsKey(e)) {
                    map.put(e, new PriorityQueue<>());
                }
                map.get(e).add(new Gold(g, i));
            } else {
                int x = sc.nextInt();
                long sum = 0;
                while(!map.isEmpty()) {
                    Integer k = map.floorKey(x);
                    if (k == null) break;
                    if (map.get(k).isEmpty()) {
                        map.remove(k);
                        continue;
                    }
                    while (x - k >= 0) {
                        PriorityQueue<Gold> pq = map.get(k);
                        if (pq.isEmpty()) break;
                        Gold top = pq.poll();
                        x -= k;
                        sum += top.gold;
                    }
                }
                System.out.println(sum);
            }
        }
    }
}
