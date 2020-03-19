#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &grid, int i, int j, int r, int c) {
	if (grid[i][j] == '#' || grid[i][j] == 'v') return 0;
	grid[i][j] = 'v';
	if (i > 0) dfs(grid, i - 1, j, r, c);
	if (i < r - 1) dfs(grid, i + 1, j, r ,c);
	if (j > 0) dfs(grid, i, j - 1, r, c);
	if (j < c - 1) dfs(grid, i , j + 1, r, c);
	return 1;
}

int main() {
	int r, c;
	int n = 0;
	while (cin >> r && cin >> c) {
		n++;
		vector<vector<char>> grid(r, vector<char>(c));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> grid[i][j];
			}
		}
		int count = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				count += dfs(grid, i, j, r, c);
			}
		}
		cout << "Case " << n << ": " << count << endl;
	}
}