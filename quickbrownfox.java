import java.util.Scanner;

public class quickbrownfox {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		s.nextLine();

		while(n-- > 0) {
			String cur = s.nextLine();
			int[] chars = new int[26];
			String ans = "";
			for (char ch : cur.toCharArray()) {
				if (ch - 'a' >= 0 && ch - 'a' < 26) {
					chars[ch - 'a']++;
				}
				if (ch - 'A' >= 0 && ch - 'A' < 26) {
					chars[ch - 'A']++;
				}
			}
			for (int i = 0; i < 26; ++i) {
				if (chars[i] == 0) ans += (char)('a' + i);
			}
			if (ans == "") {
				System.out.println("pangram");
			} else {
				System.out.println("missing " + ans);
			}
		}
	}
}