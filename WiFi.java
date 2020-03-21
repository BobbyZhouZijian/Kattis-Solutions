import java.util.Arrays;
import java.util.Scanner;

class WiFi {

    /**
     * Implement your solution here
     */
    public static double computeDistance(int[] houses, int numOfAccessPoints) {
        double maxDistance = houses[houses.length - 1] - houses[0];
        double minDistance = 0.0;
        while (minDistance + 0.1 < maxDistance) {
            double midDistance = (minDistance + maxDistance) / 2;
            if (coverable(houses, numOfAccessPoints, midDistance)) {
                maxDistance = midDistance;
            } else {
                minDistance = midDistance;
            }
        }
        return roundToHalf(maxDistance);
    }

    public static double roundToHalf(double d) {
        return Math.round(d * 2) / 2.0;
    }

    /**
     * Implement your solution here
     */
    public static boolean coverable(int[] houses, int numOfAccessPoints, double distance) {
        double curPos = Integer.MIN_VALUE + distance * 2;
        for (int house : houses) {
            if (curPos + distance < house || curPos - distance > house) {
                numOfAccessPoints--;
                if (numOfAccessPoints < 0) return false;
                curPos = house + distance;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; ++i) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] houses = new int[m];
            for (int j = 0; j < m; ++j) {
                houses[j] = sc.nextInt();
            }
            Arrays.sort(houses);
            System.out.println(computeDistance(houses, n));
        }
    }
}
