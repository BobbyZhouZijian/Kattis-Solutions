import java.util.Collections;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Scanner;

class MedianFinder {
    // TODO: Include your data structures here
    private PriorityQueue<Integer> maxpq; // max heap
    private PriorityQueue<Integer> minpq;
    public MedianFinder() {
        // TODO: Construct/Initialise your data structures here
        maxpq = new PriorityQueue<>(Collections.reverseOrder());
        minpq = new PriorityQueue<>();
    }
    public void insert(int x) {
        // TODO: Implement your insertion operation here
        if (minpq.isEmpty() || x > minpq.peek()) {
            minpq.add(x);
        } else {
            maxpq.add(x);
        }
        rotate();
    }
    public int getMedian() {
        // TODO: Implement your getMedian operation here
        int ans = minpq.poll();
        rotate();
        return ans;
    }
    private void rotate() {
        if (minpq.size() - maxpq.size() > 1) {
            int cur = minpq.poll();
            maxpq.add(cur);
        }
        if (maxpq.size() > minpq.size()) {
            int cur = maxpq.poll();
            minpq.add(cur);
        }
    }
}

public class CookieSelection {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MedianFinder mf = new MedianFinder();
        while (sc.hasNextLine()) {
            String next = sc.nextLine();
            if (next.equals("#")) {
                System.out.println(mf.getMedian());
            } else {
                mf.insert(Integer.parseInt(next));
            }
        }
    }
}