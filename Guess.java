import java.util.Scanner;

class Solution {

    // Your local variables here
    private int low = 1;
    private int high = 1000;

    /**
     * Implement how your algorithm should make a guess here
     */
    public int guess() {
        if (low >= high) return low;
        return (low + high) / 2;
    }

    /**
     * Implement how your algorithm should update its guess here
     */
    public void update(int answer) {
        if (answer == -1) {
            low = (low + high) / 2 + 1;
        } else {
            high = (low + high) / 2 - 1;
        }
    }
}

public class Guess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sln = new Solution();
        while (true) {
            System.out.println(sln.guess());
            String response = sc.nextLine();
            if (response.equals("higher")) {
                sln.update(-1);
            } else if (response.equals("lower")) {
                sln.update(1);
            } else {
                break;
            }
        }
    }
}
