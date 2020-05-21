import java.util.Arrays;
import java.util.Scanner;

public class Winnings {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();
            if (n == 0) break;

            int[] dpMax = new int[n];
            int[] dpMin = new int[n];
            int[][] g = new int[n][n];

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    g[i][j] = sc.nextInt();
                }
            }

            int k = sc.nextInt();

            // run once first
            dpMax[0] = dpMin[0] = 0;
            for (int j = 0; j < n; ++j) {
                dpMax[j] = dpMin[j] = g[0][j];
            }

            for (int l = 1; l < k; ++l) {
                int[] nextMax = new int[n];
                int[] nextMin = new int[n];

                for (int i = 0; i < n; ++i) {
                    nextMax[i] = 0;
                    nextMin[i] = Integer.MAX_VALUE;
                }

                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        nextMax[j] = Math.max(dpMax[i] + g[i][j], nextMax[j]);
                        nextMin[j] = Math.min(dpMin[i] + g[i][j], nextMin[j]);
                    }
                }

                for (int i = 0; i < n; ++i) {
                    dpMax[i] = nextMax[i];
                    dpMin[i] = nextMin[i];
                }
            }

            int max = 0;
            int min = Integer.MAX_VALUE;

            for (int i = 0; i < n; ++i) {
                max = Math.max(max, dpMax[i]);
                min = Math.min(min, dpMin[i]);
            }

            System.out.println(String.format("%d %d", max, min));
        }
    }
}
