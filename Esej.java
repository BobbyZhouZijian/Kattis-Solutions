import java.util.Scanner;

public class Esej {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        int need = Math.max(a, b / 2);

        int cur = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    for (int l = 0; l < 26; ++l) {
                        String out = "";
                        out += (char) (i + 'a');
                        out += (char) (j + 'a');
                        out += (char) (k + 'a');
                        out += (char) (l + 'a');
                        System.out.print(String.format("%s ", out));
                        cur++;
                        if (cur >= need) return;
                    }
                }
            }
        }
    }
}
