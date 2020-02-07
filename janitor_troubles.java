import java.util.Scanner;

public class janitor_troubles {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();
		int d = s.nextInt();
		double sp = (double)(a + b + c + d) / 2;
		double max_area = Math.sqrt((sp - a) * (sp - b) * (sp - c) * (sp  -d));
		System.out.println(max_area);
	}
}