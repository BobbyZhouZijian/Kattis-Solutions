import java.util.Scanner;
import java.util.Arrays;
public class goatrope {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int x = s.nextInt();
		int y = s.nextInt();
		int x1 = s.nextInt();
		int y1 = s.nextInt();
		int x2 = s.nextInt();
		int y2 = s.nextInt();
		if (x >= x1 && x <= x2) {
			double d7 = Math.abs(y - y1);
			double d8 = Math.abs(y - y2);
			System.out.println(Math.min(d7, d8));
			return;
		}
		if (y >= y1 && y <= y2) {
			double d5 = Math.abs(x - x1);
			double d6 = Math.abs(x - x2);	
			System.out.println(Math.min(d5, d6));
			return;
		}

		double d1 = Math.sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
		double d2 = Math.sqrt((x - x1) * (x - x1) + (y - y2) * (y - y2));
		double d3 = Math.sqrt((x - x2) * (x - x2) + (y - y1) * (y - y1));
		double d4 = Math.sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
		double min = Math.min(d1, Math.min(d2, Math.min(d3, d4)));
		System.out.println(min);
	} 
}