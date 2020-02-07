#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int vis[105][105];
int grid[105][105];
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(queue<pair<int, int>> &q, int r, int c, int depth) {
	queue<pair<int, int>> next_q;

	while (!q.empty()) {
		auto &t = q.front();
		int x = t.first;
		int y = t.second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < r && nx >= 0 && ny < c && ny >= 0 && vis[nx][ny] == 0 && grid[nx][ny] == 1) {
				if (nx == 0 && ny == 0) return depth;
				vis[nx][ny] = 1;
				next_q.push({nx, ny});
			}
		}
	}
	if (next_q.empty()) return -1;
	else {
		q = next_q;
		return bfs(q, r, c, depth + 1);
	}
}

int main(int argc, char const *argv[])
{
	fast();

	int n;
	cin >> n;

	int x, y;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			if (ch == '.') grid[i][j] = 1;

			if (ch == 'K') {
				if (i == 0 && j == 0) {
					cout << 0;
					return 0;
				}
				vis[i][j] = 1;
				grid[i][j] = 1;
				x = i;
				y = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({x, y});
	cout << bfs(q, n, n, 1);
	return 0;
}