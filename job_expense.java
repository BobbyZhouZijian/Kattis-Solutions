import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class job_expense {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int sum = 0;
		while(n-- > 0) {
			int x = s.nextInt();
			sum += x < 0 ? -x : 0;
		}
		System.out.println(sum);
	}
}