#include<iostream>
#include<vector>

using namespace std;

int fathers[10000000] = {0};

int find(int x) {
	return fathers[x] == x ? x : find(fathers[x]);
}

void unify(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return;
	fathers[fy] = fx;
} 

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void initialize(vector< vector<int> > &grid, int r, int c) {
	for (int k = 0; k < r * c; ++k) fathers[k] = k;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (i == 0 && j == 0) continue;
			else if (i == 0) {
				if (grid[i][j - 1] == grid[i][j]) fathers[i * c + j] = i * c + j - 1;
			}
			else if (j == 0) {
				if (grid[i][j] == grid[i - 1][j]) fathers[i * c + j] = (i - 1) * c + j;
			}
			else {
				if (grid[i - 1][j] == grid[i][j] && grid[i][j - 1] == grid[i][j]) {
					fathers[i * c + j] = i * c + j - 1;
					unify(i * c + j - 1, (i - 1) * c + j);
				}
				else if (grid[i - 1][j] == grid[i][j]) fathers[i * c + j] = (i - 1) * c + j;
				else if (grid[i][j - 1] == grid[i][j]) fathers[i * c + j] = i * c + j - 1;
			}
		}
	}
}

int main() {
	fast();

	int r, c;
	cin >> r >> c;

	vector<vector<int>> grid(r, vector<int>(c, 0));
	for (int i = 0; i < r; ++i) {
		string cur;
		cin >> cur;
		for (int j = 0; j < c; ++j) {
			grid[i][j] = cur[j] - '0';
		}
	}

	initialize(grid, r, c);

	int n;
	cin >> n;

	while(n--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; x2--; y1--; y2--;
		if (find(x1 * c + y1) == find(x2 * c + y2)) {
			if (grid[x1][y1] == 1) cout << "decimal";
			else cout << "binary";
		}
		else cout << "neither";

		//for (int k = 0; k < r * c; ++k) cout << find(k) << " ";

		cout << endl;
	}
}