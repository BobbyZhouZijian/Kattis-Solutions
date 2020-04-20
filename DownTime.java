import java.util.Scanner;

public class DownTime {

    public int solver() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        int[] times = new int[n];
        int index = 0;
        int need = 1;
        int max = 1;
        times[0] = sc.nextInt();

        for (int i = 1; i < n; ++i) {
            times[i] = sc.nextInt();
            while (times[index] + 1000 <= times[i]) {
                need--;
                index++;
            }
            need++;
            max = Math.max(max, need);
        }

        if (max % k == 0) {
            return max / k;
        } else {
            return max / k + 1;
        }
    }

    public static void main(String[] args) {
        DownTime downTime = new DownTime();
        System.out.println(downTime.solver());
    }
}
