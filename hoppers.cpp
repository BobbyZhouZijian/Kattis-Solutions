#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> vis;
vector<vector<int>> g;
int odd = 1;

void dfs(int i, int val) {
    vis[i] = val;

    for (int& j : g[i]) {
        if (!vis[j]) dfs(j, val + 1);
        if (((abs(vis[i] - vis[j]) + 1) % 2) != 0) odd = 0;
    }
}

int main() {
    cin >> m >> n;

    vis.resize(m + 1, 0);
    g.resize(m + 1);

    // input data
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) {
            dfs(i, 1);
            ans++;
        }
    }

    cout << ans - 1 + odd;
}
