#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> g;
vector<vector<int>> vis;

int hop_c = 0;

bool bfs(vector<pair<int, int>> q) {
    vector<pair<int, int>> next_q;
    for (auto &p : q) {
        int i = p.first, j = p.second;
        if (i == m - 1 && j == n - 1) return true;
        if (vis[i][j]) continue;
        vis[i][j] = 1;
        int step = g[i][j];
        if (i + step < m) next_q.push_back({i + step, j});
        if (i - step >= 0) next_q.push_back({i - step, j});
        if (j + step < n) next_q.push_back({i, j + step});
        if (j - step >= 0) next_q.push_back({i, j - step});
    }
    hop_c += 1;
    if (!next_q.size()) {
        return false;
    }
    return bfs(next_q);
}

int main() {
    cin >> m >> n;
    g.resize(m, vector<int>(n, 0));
    vis.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }
    vector<pair<int, int>> q;
    q.push_back({0, 0});
    if (bfs(q)) {
        cout << hop_c;
    } else {
        cout << -1;
    }
}