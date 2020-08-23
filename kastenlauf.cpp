#include <iostream>
#include <vector>
using namespace std;

bool ok = false;
int n;

void dfs(int i, vector<vector<int>>& g, vector<bool>& vis) {
    if (ok || vis[i]) return;
    vis[i] = true;
    if (i == n + 1) {
        ok = true;
        return;
    }
    for (int& j : g[i]) {
        if (!vis[j]) dfs(j, g, vis);
    }
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        vector<pair<int, int>> loc;
        vector<vector<int>> g(n + 2);

        for (int i = 0; i < n + 2; ++i) {
            int x, y;
            cin >> x >> y;
            loc.emplace_back(x, y);
        }

        for (int i = 0; i < n + 2; ++i) {
            for (int j = 0; j < n + 2; ++j) {
                if (i == j) continue;
                int x_dist = abs(loc[i].first - loc[j].first);
                int y_dist = abs(loc[i].second - loc[j].second);
                if (x_dist + y_dist <= 1000) {
                   g[i].push_back(j);
                   g[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n + 2, false);
        dfs(0, g, vis);
        if (ok) cout << "happy" << endl;
        else cout << "sad" << endl;
        ok = false;
    }
}