#include <bits/stdc++.h>
using namespace std;

vector<bool> colors;
vector<bool> vis;
vector<vector<int>> v;

void dfs(int x, bool c) {
    if (vis[x]) return;
    vis[x] = true;
    colors[x] = c;
    for (int nb : v[x]) {
        dfs(nb, !c);
    }
}

int main() {
    int n;
    cin >> n;
    int a, b;
    v.resize(n);
    colors.resize(n, false);
    vis.resize(n, false);
    vector<pair<int, int>> q;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        a--; b--;
        q.push_back({a, b});
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(0, false);

    for (auto &p : q) {
        if (colors[p.first]) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
}