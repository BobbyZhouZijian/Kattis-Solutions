import java.util.Scanner;
import java.util.ArrayList;

public class 10kindsofpeople {
	int[] fathers;
	public static void main(Stringp[] args) {
		Scanner in = new Scanner(System.in);
		int r = in.nextInt();
		int c = in.nextInt();

		int[][] grid = new int[r][c];
		fathers = new int[10000000];
		for (int i = 0; i < r; ++i) {
			char[] cur = in.next().toCharArray;
			for (int j = 0; j < c; ++j) {
				grid[i][j] = cur[j] - '0';
			}
		}

		initialize(grid[][], r, c);

		int n = in.nextInt();
		while(n-- > 0) {
			int i1 = in.nextInt();
			int j1 = in.nextInt();

			int i2 = in.nextInt();
			int j2 = in.nextInt();
			i1--;
			i2--;
			j1--;
			j2--;

			if (find(i1 * c + j1) == find(i2 * c + j2)) {
				cout << grid[i1][j1] == 1 ? "decimal" : "binary";
			} else cout << "neither";
			cout << endl;
		}
	}

	private void initialize(int[][] grid, int r, int c) {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				fathers[i * c + j] = i * c + j;
			}
		}


		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (i == 0 && j == 0) continue;
				else if (i == 0) {
					if (grid[i][j - 1] == grid[i][j]) fathers[i * c + j] = i * c + j - 1;
				} else if (j == 0) {
					if (grid[i - 1][j] == grid[i][j]) fathers[i * c + j] = (i - 1) * c + j;
				} else {
					if (grid[i - 1][j] == grid[i][j] && grid[i][j] == grid[i][j - 1]) {
						fathers[i * c + j] = i * c + j - 1;
						unite(i * c + j - 1, (i - 1) * c + j);
					}
					else if (grid[i - 1][j] == grid[i][j]) fathers[i * c + j] = (i - 1) * c + j;
					else if (grid[i][j - 1] == grid[i][j]) fathers[i * c + j] = i * c + j - 1;
				}
			}
		}
	}

	private void unite(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if (fx == fy) return;
		fathers[fy] = fx;
	}

	private int find(int x) {
		return fathers[x] == x ? x : find(fathers[x]);
	}
}