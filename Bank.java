import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

class Pair {
    int money;
    int time;
    public Pair(int money, int time) {
        this.money = money;
        this.time = time;
    }

    @Override
    public String toString() {
        return String.format("[%d,%d]", money,time);
    }
}

public class Bank {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        Pair[] customers = new Pair[n];
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)->y-x);
        for (int i = 0; i < n; ++i) {
            int curMoney = sc.nextInt();
            int curTime = sc.nextInt();
            customers[i] = new Pair(curMoney, curTime);
        }
        Arrays.sort(customers, (x,y)->y.time-x.time);
        int index = 0;
        int ans = 0;
        while(t-- > 0) {
            while (index < customers.length && customers[index].time >= t) {
                pq.add(customers[index++].money);
            }
            if (!pq.isEmpty()) ans += pq.poll();
        }
        System.out.println(ans);
    }
}