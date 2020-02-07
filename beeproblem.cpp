#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int dfs(vector<vector<bool>> &v, int i, int j) {

	int n = v.size(), m = v[0].size(); 
	v[i][j] = false;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

	if (i - 1 >= 0 && v[i - 1][j]) a = dfs(v, i - 1, j);
	if (i + 1 < n && v[i + 1][j]) b = dfs(v, i + 1, j);
	if (j - 1 >= 0 && v[i][j - 1]) c = dfs(v, i, j - 1);
	if (j + 1 < m && v[i][j + 1]) d = dfs(v, i, j + 1);
	if (i % 2) {
		if (i - 1 >= 0 && j + 1 < m && v[i - 1][j + 1]) e = dfs(v, i - 1, j + 1);
		if (i + 1 < n && j + 1 < m && v[i + 1][j + 1]) f = dfs(v, i + 1, j + 1);
	} else {
		if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1]) e = dfs(v, i - 1, j - 1);
		if (i + 1 < n && j - 1 >= 0 && v[i + 1][j - 1]) f = dfs(v, i + 1, j - 1);
	}

	return 1 + a + b + c + d + e + f;
}

int main(int argc, char const *argv[])
{
	fast();

	int h, n, m;
	cin >> h >> n >> m;

	vector<vector<bool>> v(n, vector<bool>(m, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j) {

			char s;
			cin >> s;
			if (s == '.') v[i][j] = true;
		}
	}

	vector<int> areas;

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < m; ++j) {

			if (v[i][j]) areas.push_back(dfs(v, i, j));
		}
	}

	sort(areas.begin(), areas.end(), greater<int>());
	int ptr = 0, cnt = 0;

	while (ptr < areas.size()) {
		if (h <= 0) break;

		h -= areas[ptr];
		cnt++;
		ptr++;
	}

	cout << cnt;


	return 0;
}














