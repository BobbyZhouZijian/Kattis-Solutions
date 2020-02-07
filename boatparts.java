import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
public class boatparts {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int p = s.nextInt();
		int n = s.nextInt();
		s.nextLine();
		Map<String, Integer> m = new HashMap<>();
		int i = 0;
		while(n-- > 0) {
			i++;
			String cur = s.nextLine();
			if (!m.containsKey(cur)) {
				m.put(cur, 1);
				p--;

				if (p == 0) {
					System.out.println(i);
					return;
				}
			}
			else {
				continue;
			}
		}
		System.out.println("paradox avoided");
	}
}