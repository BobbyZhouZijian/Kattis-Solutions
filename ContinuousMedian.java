import java.io.IOException;
import java.util.PriorityQueue;

public class ContinuousMedian {

    static InputReader sc = new InputReader(System.in);

    PriorityQueue<Integer> pMax;
    PriorityQueue<Integer> pMin;

    long solve(int n) throws IOException {
        pMax = new PriorityQueue<>((x, y) -> y - x);
        pMin = new PriorityQueue<>((x, y) -> x - y);

        long accum = 0;
        for (int i = 0; i < n; ++i) {
            int e = sc.nextInt();

            if (pMin.isEmpty() || e < pMin.peek()) {
                pMax.add(e);
            } else {
                pMin.add(e);
            }

            if (pMax.size() > pMin.size() + 1) {
                pMin.add(pMax.poll());
            }

            if (pMax.size() < pMin.size()) {
                pMax.add(pMin.poll());
            }

            if (i % 2 == 1) {
                accum += (pMin.peek() - pMax.peek()) / 2 + pMax.peek();
            } else {
                accum += pMax.peek();
            }
        }
        return accum;
    }

    public static void main(String[] args) throws IOException {
        ContinuousMedian median = new ContinuousMedian();
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            System.out.println(median.solve(sc.nextInt()));
        }
    }
}
